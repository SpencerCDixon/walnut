//
//  LayoutMiddleware.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/29/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "LayoutMiddleware.hpp"
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

namespace wn {
    LayoutMiddleware::LayoutMiddleware(std::shared_ptr<wn::Config> config) : m_Config(config) {}
    
    void LayoutMiddleware::Run(std::shared_ptr<wn::Page> &&page) {
        if (page->metadata->layout.size() <= 0) return;
        
        std::string layoutPath = m_Config->GetLayoutPath() + "/" + page->metadata->layout + ".html";
        
        namespace fs = boost::filesystem;
        fs::path path(layoutPath);
        
        if (!fs::exists(path)) {
            std::cout << "WALNUT ERROR: missing layout file: " << layoutPath << std::endl;
            return;
        }
        
        fs::ifstream file(path);
        std::stringstream newContent;
        std::string line;
        
        // TODO: implement more robust interpolation which lets any page metadata be injected
        // into the template.
        while (getline(file, line)) {
            if (line.find("{{content}}") != std::string::npos) {
                newContent << page->content + '\n';
            } else {
                newContent << line + '\n';
            }
        }
        
        page->content = newContent.str();
    }
}
