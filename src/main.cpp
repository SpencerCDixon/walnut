//
//  main.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include "Config.hpp"
#include "Pipeline.hpp"
#include "MarkdownMiddleware.hpp"


int main(int argc, const char * argv[]) {
    auto config = std::make_shared<wn::Config>();
    
    auto pipeline = wn::Pipeline(config);
    
    auto mdMiddleware = std::make_unique<wn::MarkdownMiddleware>();
    
    pipeline.RegisterMiddleware(std::move(mdMiddleware));
    
    pipeline.Execute();

//    auto layoutPath = config->GetLayoutPath();
//    auto contentPath = config->GetContentPath();

//    auto parser = std::make_shared<maddy::Parser>();

//    auto results = wn::util::filesWithExtension(contentPath, ".md");
    
//    for (auto f : results) {
//        std::cout << "  found: " << f << std::endl;
//    }
    

//    for (auto f : results) {
//        std::cout << f << std::endl;
//        std::fstream stream;
//        stream.open(f);
//        std::string line;
//
//        std::stringstream markdown;
//
//        while (getline(stream, line)) {
//            markdown << line << '\n';
//        }
//
//        std::string html = parser->Parse(markdown);
//
//
//        std::ofstream out;
//        auto outPath = config->GetDistPath() + "/" + f;
//        std::cout << "outPath: " << outPath << std::endl;
//        out.open(outPath);
//        out << html;
//        out.close();
//
//        std::cout << "HTML: " << html << std::endl;
//    }

    return 0;
}
