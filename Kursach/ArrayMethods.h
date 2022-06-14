#pragma once
#include <vector>
#include <iostream>

namespace am{
    void printIntVec(std::vector<int> array);

    void fillVecRandomInt(std::vector<int>& array, int amount);

    void fillManually(std::vector<int>& array, int amount);

    void fillFromFile(std::vector<int>& array, std::string fileName);
}
