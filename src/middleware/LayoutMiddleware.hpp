//
//  LayoutMiddleware.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/29/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef LayoutMiddleware_hpp
#define LayoutMiddleware_hpp

#include <memory>
#include "Middleware.hpp"

namespace wn {
    class LayoutMiddleware : public wn::Middleware {
    public:
        LayoutMiddleware();
        
        void Run(std::shared_ptr<wn::Page>&& page) override;
    };
}

#endif /* LayoutMiddleware_hpp */
