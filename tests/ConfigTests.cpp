//
//  ConfigTests.cpp
//  tests
//
//  Created by Spencer Dixon on 10/28/18.
//  Copyright © 2018 Spencer Dixon. All rights reserved.
//

#include <gtest/gtest.h>
#include "src/Config.hpp"

namespace {
    
//    // The fixture for testing class Foo.
//    class ConfigTest : public ::testing::Test {
//    protected:
//        // You can remove any or all of the following functions if its body
//        // is empty.
//
//        ConfigTest() {
//            // You can do set-up work for each test here.
//        }
//
//        ~ConfigTest() override {
//            // You can do clean-up work that doesn't throw exceptions here.
//        }
//
//        // If the constructor and destructor are not enough for setting up
//        // and cleaning up each test, you can define the following methods:
//
//        void SetUp() override {
//            // Code here will be called immediately after the constructor (right
//            // before each test).
//        }
//
//        void TearDown() override {
//            // Code here will be called immediately after each test (right
//            // before the destructor).
//        }
//
//        // Objects declared here can be used by all tests in the test case for Foo.
//    };
    
    TEST(ConfigTest, ProvidesFallbacksWhenNoFile) {
        wn::Config c;
        EXPECT_EQ(c.GetContentPath(), "content");
        EXPECT_EQ(c.GetLayoutPath(), "layouts");
        EXPECT_EQ(c.GetDistPath(), "dist");
    }
    
}  // namespace
