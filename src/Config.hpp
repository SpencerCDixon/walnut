//
//  Config.hpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#ifndef Config_hpp
#define Config_hpp

#include <string>
#include "cpptoml/cpptoml.h"

namespace wn {
    class Config {
    public:
        Config();
        ~Config();
        
        std::string GetLayoutPath() const;
        std::string GetContentPath() const;
        std::string GetDistPath() const;
        std::string GetAssetPath() const;
        std::string GetIncludePath() const;
        
    private:
        std::shared_ptr<cpptoml::table> m_Table;
        
    private:
        std::string GetStringWithBackup(const std::string& key, const std::string& backup) const;
    };
}

#endif /* Config_hpp */
