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
#include "../Config.hpp"

namespace wn {
    class LayoutMiddleware : public wn::Middleware {
    public:
        LayoutMiddleware(std::shared_ptr<wn::Config> config);
        
        void Run(std::shared_ptr<wn::Page>&& page) override;
    private:
        std::shared_ptr<wn::Config> m_Config;
    };
}

#endif /* LayoutMiddleware_hpp */
