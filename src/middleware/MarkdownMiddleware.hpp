//
//  MarkdownMiddleware.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef MarkdownMiddleware_hpp
#define MarkdownMiddleware_hpp

#include <memory>
#include <maddy/parser.h>
#include "Middleware.hpp"

namespace wn {
    class MarkdownMiddleware : public wn::Middleware {
    public:
        MarkdownMiddleware();
        
        void Run(std::shared_ptr<wn::Page>&& page) override;
        
    private:
        std::unique_ptr<maddy::Parser> m_Parser;
    };
}

#endif /* MarkdownMiddleware_hpp */
