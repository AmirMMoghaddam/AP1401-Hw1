
#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "book_inventory.h"
#include "regression.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        Data dataset = regression::read_database("fish.txt");
        std::cout << regression::cost_function(dataset, {0, 0, 0, 0}) << std::endl;
        std::cout << regression::cost_function(dataset, {1, 1, 1, 1}) << std::endl;
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}