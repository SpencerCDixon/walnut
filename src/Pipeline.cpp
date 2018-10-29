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

namespace wn {
    Pipeline::Pipeline(std::shared_ptr<Config> config) {
        auto filepaths = wn::util::filesWithExtension(config->GetContentPath(), ".md");
        for (auto f : filepaths) {
            boost::filesystem::path path(f);
            auto meta = std::make_unique<PageMetadata>(f, path.extension().string());
            
            std::stringstream contents;
            boost::filesystem::ifstream file(path);
            std::string line;
            
            while (getline(file, line)) {
                contents << line;
            }
            auto page = std::make_shared<Page>(contents.str(), std::move(meta));
            
            m_Pages.push_back(page);
        }
    }
    
    void Pipeline::Execute() {
        std::cout << "middleware count: " << m_Middlewares.size() << std::endl;
        
        std::vector<std::shared_ptr<wn::Page>>::iterator i;
        for (i = m_Pages.begin(); i != m_Pages.end(); i++) {
            std::cout << "processing page: " << (*i)->metadata->path << std::endl;
            
            std::cout << "  page contents: " << (*i)->content << std::endl;
        
            for (auto& m : m_Middlewares) {
                m->Run(std::move(*i));
            }
            
            std::cout << "  page contents: " << (*i)->content << std::endl;
        }
    }
    
    void Pipeline::RegisterMiddleware(std::unique_ptr<wn::Middleware> m) {
        m_Middlewares.push_back(std::move(m));
    }
};
