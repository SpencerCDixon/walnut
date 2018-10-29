//
//  LayoutMiddleware.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/29/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "LayoutMiddleware.hpp"
#include <iostream>

namespace wn {
    LayoutMiddleware::LayoutMiddleware() {}
    
    void LayoutMiddleware::Run(std::shared_ptr<wn::Page> &&page) {
        if (page->metadata->layout.size() <= 0) return;
        
        std::cout << "processing layout for: " << page->metadata->path << std::endl;
    }
}
