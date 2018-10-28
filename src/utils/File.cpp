//
//  File.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "File.hpp"
#include <boost/filesystem.hpp>
#include <iostream>

namespace wn { namespace util {
    std::vector<std::string> filesWithExtension(const std::string& dir, const std::string& ext) {
        using namespace boost::filesystem;
        std::vector<std::string> results;
        path directoryPath(dir);
        
        if (exists(directoryPath)) {
            if (is_directory(directoryPath)) {
                for (directory_entry& x : recursive_directory_iterator(directoryPath)) {
                    if (x.path().extension() == ext) {
                        results.push_back(x.path().string());
                    }
                }
            }
        }
        
        return results;
    }
} }
