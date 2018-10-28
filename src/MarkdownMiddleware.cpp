//
//  MarkdownMiddleware.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "MarkdownMiddleware.hpp"

#include <iostream>

namespace wn {
    MarkdownMiddleware::MarkdownMiddleware() :
        m_Parser(std::make_unique<maddy::Parser>()) {
    }

    void MarkdownMiddleware::Run(std::shared_ptr<wn::Page>&& page) {    
        std::stringstream ss;
        ss << page->content;
        
        std::string html = m_Parser->Parse(ss);
    
        page->content = html;
    }
}
