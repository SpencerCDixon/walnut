//
//  DistMiddleware.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/29/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "DistMiddleware.hpp"
#include <boost/filesystem.hpp>

namespace wn {
    DistMiddleware::DistMiddleware(std::shared_ptr<wn::Config> config) : m_Config(config) {}
    
    void DistMiddleware::Run(std::shared_ptr<wn::Page> &&page) {
        namespace fs = boost::filesystem;
        
        std::string contentPathStripped = page->metadata->path.substr(m_Config->GetContentPath().size() + 1);
        
        fs::path path(contentPathStripped);
        fs::path dir(m_Config->GetDistPath() + "/" + path.parent_path().string());
        
        if (!fs::exists(dir)) {
            fs::create_directories(dir);
        }
        
        std::string filename = path.stem().string() + ".html";
        std::string contentDir = dir.string().back() == '/' ? dir.string() : dir.string() + "/";
        fs::path contentPath(contentDir + filename);
        std::cout << contentPath << std::endl;
        
        fs::ofstream file;
        file.open(contentPath);
        file << page->content << std::endl;;
        file.close();
    }
}
