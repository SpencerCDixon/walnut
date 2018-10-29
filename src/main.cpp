//
//  main.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include <memory>

#include "Config.hpp"
#include "Pipeline.hpp"
#include "middleware/MarkdownMiddleware.hpp"
#include "middleware/LayoutMiddleware.hpp"

int main(int argc, const char * argv[]) {
    // Configuration/Environment
    auto config = std::make_shared<wn::Config>();
    auto pipeline = wn::Pipeline(config);
    
    // Middlewares
    auto mdMiddleware = std::make_unique<wn::MarkdownMiddleware>();
    auto layoutMiddleware = std::make_unique<wn::LayoutMiddleware>();
    pipeline.RegisterMiddleware(std::move(mdMiddleware));
    pipeline.RegisterMiddleware(std::move(layoutMiddleware));
    
    // Build
    pipeline.Execute();

    return 0;
}
