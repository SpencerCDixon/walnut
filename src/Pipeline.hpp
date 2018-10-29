//
//  Pipeline.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef Pipeline_hpp
#define Pipeline_hpp

#include "Middleware.hpp"
#include "Config.hpp"

#include <vector>
#include <memory>

namespace wn {
    class Pipeline {
    public:
        Pipeline(std::shared_ptr<Config> config);
        void Execute();
        void RegisterMiddleware(std::unique_ptr<wn::Middleware> m);
    private:
        std::vector<std::unique_ptr<wn::Middleware>> m_Middlewares;
        std::vector<std::shared_ptr<wn::Page>> m_Pages;
        std::shared_ptr<wn::Config> m_Config;
    };
}

#endif /* Pipeline_hpp */
