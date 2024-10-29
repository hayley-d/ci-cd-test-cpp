#include <gtest/gtest.h>
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"

#include <memory>

class building_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();
        Building* building;

        void SetUp() override {
            building = new Building(300,taxAuth);
        }

        void TearDown() override {
            delete building;
        }
};

// Test Constructor
TEST_F(building_test, ConstructorSetCorrectValues) {
    EXPECT_EQ(building->getCost(),300);
}


