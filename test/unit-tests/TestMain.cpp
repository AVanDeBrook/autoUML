/**
 * This is just a test/template for writing test cases in the future
 * and setting up the test suite.
 */

#include "gtest/gtest.h"

namespace {
    class TestMain : public ::testing::Test {
        protected:
            TestMain() {

            }

            ~TestMain() override {

            }

            void SetUp() override {

            }

            void TearDown() override {

            }

    };

    TEST_F(TestMain, DoesX) {

    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
