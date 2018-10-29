//
//  Pipeline.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "Pipeline.hpp"
#include "utils/File.hpp"

#include <iostream>
#include <boost/filesystem.hpp>
#include <cpptoml/cpptoml.h>

namespace wn {
    Pipeline::Pipeline(std::shared_ptr<Config> config) : m_Config(config) {
        auto filepaths = wn::util::filesWithExtension(config->GetContentPath(), ".md");
        for (auto f : filepaths) {
            boost::filesystem::path path(f);
            boost::filesystem::ifstream file(path);
            
            std::stringstream ss[2];
            std::string line;
            bool inHeader = false;
            bool onFirstLine = true;
            bool shouldInsert = true;
            
            while (getline(file, line)) {
                if (onFirstLine && line.find("---") != std::string::npos) {
                    inHeader = true;
                    onFirstLine = false;
                    shouldInsert = false;
                } else if (inHeader && line.find("---") != std::string::npos) {
                    inHeader = false;
                    shouldInsert = false;
                } else {
                    shouldInsert = true;
                }
                
                line += '\n';
                
                if (shouldInsert) {
                    if (inHeader) {
                        ss[0] << line;
                    } else {
                        ss[1] << line;
                    }
                }
            }
            
            cpptoml::parser p{ss[0]};
            auto table = p.parse();
            auto meta = std::make_unique<PageMetadata>(f, path.extension().string(), table);
            
            std::cout << *(meta.get()) << std::endl;
            auto page = std::make_shared<Page>(ss[1].str(), std::move(meta));
        
            m_Pages.push_back(page);
        }
    }
    
    void Pipeline::Execute() {
        // Process pages
        for (auto& p : m_Pages) {
            std::cout << "processing page: " << p->metadata->path << std::endl;
            std::cout << "  before:\n" << p->content << std::endl;
            for (auto& m : m_Middlewares) {
                m->Run(std::move(p));
            }
            std::cout << "  after:\n" << p->content << std::endl;
        }
        
        // Copy assets
        boost::filesystem::path assetSource(m_Config->GetAssetPath());
        boost::filesystem::path assetDest(m_Config->GetDistPath() + "/" + m_Config->GetAssetPath());
        
        wn::util::copyDirectoryRecursively(assetSource, assetDest);
    }
    
    void Pipeline::RegisterMiddleware(std::unique_ptr<wn::Middleware> m) {
        m_Middlewares.push_back(std::move(m));
    }
};
