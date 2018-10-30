//
//  Middleware.cpp
//  walnut
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include "Middleware.hpp"

namespace wn {
    std::ostream& operator<<(std::ostream& os, const wn::PageMetadata& pm) {
        os << "PageMetadata:\n";
        os << "  path: " << pm.path << '\n';
        os << "  extension: " << pm.extension << '\n';
        os << "  layout: " << pm.layout << '\n';
        os << "  slug: " << pm.slug << '\n';
        os << "  title: " << pm.title << '\n';
        return os;
    }
    
    PageMetadata::PageMetadata(std::string path, std::string extension, std::shared_ptr<cpptoml::table> table) :
     path(path), extension(extension), m_Table(table) {
         layout = *(table->get_as<std::string>("layout"));
         slug = *(table->get_as<std::string>("slug"));
         title = *(table->get_as<std::string>("title"));
    }
    
    std::string PageMetadata::Value(std::string key) {
        auto value = m_Table->get_as<std::string>(key);
        if (value) {
            return *value;
        }
        
        // Not found, ok to silently fail.
        return "";
    }
}
