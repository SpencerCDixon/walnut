//
//  Middleware.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef Middleware_hpp
#define Middleware_hpp

#include <memory>
#include <string>
#include <cpptoml/cpptoml.h>
#include <iostream>

namespace wn {
    class PageMetadata {
    public:
        std::string path;
        std::string extension;
        
        // Coming from TOML frontmatter
        std::string layout;
        std::string slug;
        std::string title;
        
        PageMetadata(std::string path, std::string extension, std::shared_ptr<cpptoml::table> table);
        
        std::string Value(std::string key);
        friend std::ostream& operator<<(std::ostream& os, const PageMetadata& pm);
    };
    
    struct Page {
        std::string content;
        std::unique_ptr<PageMetadata> metadata;
        
        Page(std::string content, std::unique_ptr<PageMetadata> metadata)
            : content(content), metadata(std::move(metadata)) {}
    };
    
    class Middleware {
    public:
        virtual ~Middleware() {}
        virtual void Run(std::shared_ptr<Page>&& page) = 0;
    };
}

#endif /* Middleware_hpp */
