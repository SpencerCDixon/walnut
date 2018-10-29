//
//  Config.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "Config.hpp"
#include <iostream>
#include <exception>

namespace wn {
    Config::Config() : m_Table(nullptr) {
        try {
            m_Table = cpptoml::parse_file("walnut.toml");
            std::cout << "loaded default config walnut.toml" << std::endl;
        } catch (std::exception& e) {
            std::cout << "WALNUT ERROR: could not parse config file" << std::endl;
            // TODO: handle config parsing errors.
        }
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
    
    std::string Config::GetAssetPath() const {
        return GetStringWithBackup("assetDir", "assets");
    }
    
    std::string Config::GetIncludePath() const {
        return GetStringWithBackup("includeDir", "include");
    }

    std::string Config::GetStringWithBackup(const std::string& key, const std::string& backup) const {
        if (!m_Table) return backup;
        auto str = m_Table->get_as<std::string>(key);
        
        if (str) {
            std::cout << "found: '" << *str << "' for key " << key << std::endl;
            return *str;
        } else {
            std::cout << "using backup: '" << backup << "' for key " << key << std::endl;
            return backup;
        }
    }
}
