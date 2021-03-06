//
//  File.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace wn { namespace util {
    std::vector<std::string> filesWithExtension(const std::string& dir, const std::string& pattern);
    void copyDirectoryRecursively(const boost::filesystem::path& sourceDir, const boost::filesystem::path& destinationDir);
} }

#endif /* File_hpp */
