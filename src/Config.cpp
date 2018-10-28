//
//  Config.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "Config.hpp"
#include <iostream>

Config::Config() : m_Table(cpptoml::parse_file("walnut.toml")) {
    std::cout << "loaded default config walnut.toml" << std::endl;
}

Config::~Config() {}

std::string Config::GetLayoutPath() const {
    return GetStringWithBackup("layoutDir", "layouts");
}

std::string Config::GetContentPath() const {
    return GetStringWithBackup("contentDir", "content");
}

std::string Config::GetDistPath() const {
    return GetStringWithBackup("distDir", "dist");
}

std::string Config::GetStringWithBackup(const std::string& key, const std::string& backup) const {
    auto str = m_Table->get_as<std::string>(key);
    
    if (str) {
        std::cout << "found: '" << *str << "' for key " << key << std::endl;
        return *str;
    } else {
        std::cout << "using backup: '" << backup << "' for key " << key << std::endl;
        return backup;
    }
}
