//
//  File.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "File.hpp"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <iostream>

namespace wn { namespace util {
    namespace fs = boost::filesystem;
    
    std::vector<std::string> filesWithExtension(const std::string& dir, const std::string& ext) {
        std::vector<std::string> results;
        fs::path directoryPath(dir);
        
        if (fs::exists(directoryPath)) {
            if (fs::is_directory(directoryPath)) {
                for (fs::directory_entry& x : fs::recursive_directory_iterator(directoryPath)) {
                    if (x.path().extension() == ext) {
                        results.push_back(x.path().string());
                    }
                }
            }
        }
        
        return results;
    }
    
    void copyDirectoryRecursively(const fs::path& sourceDir, const fs::path& destinationDir) {
        if (!fs::exists(sourceDir) || !fs::is_directory(sourceDir)) {
            throw std::runtime_error("Source directory " + sourceDir.string() + " does not exist or is not a directory");
        }
        
        if (fs::exists(destinationDir)) {
            fs::remove_all(destinationDir);
        }
        
        if (!fs::create_directories(destinationDir)) {
            throw std::runtime_error("Cannot create destination directory " + destinationDir.string());
        }
        
        for (const auto& dirEnt : fs::recursive_directory_iterator{sourceDir}) {
            const auto& path = dirEnt.path();
            auto relativePathStr = path.string();
            boost::replace_first(relativePathStr, sourceDir.string(), "");
            
            fs::path finalPath(destinationDir.string() + relativePathStr);
            fs::copy_file(path, finalPath);
        }
    }
} }
