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

namespace wn {
    struct PageMetadata {
        std::string path;
        std::string extension;
        
        PageMetadata(std::string path, std::string extension) : path(path), extension(extension) {}
    };
    
    struct Page {
        std::string content;
        std::unique_ptr<PageMetadata> metadata;
        
        Page(std::string content, std::unique_ptr<PageMetadata> metadata) : content(content), metadata(std::move(metadata)) {}
    };
    
    class Middleware {
    public:
        virtual ~Middleware() {}
        virtual void Run(std::shared_ptr<Page>&& page) = 0;
    };
}

#endif /* Middleware_hpp */
