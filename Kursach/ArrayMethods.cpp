#include <iostream>
#include <vector>
#include <fstream>
#include "ArrayMethods.h"

void am::printIntVec(std::vector<int> array) {
    std::cout << "Array contains: " << std::endl;
    for(int i = 0; i < array.size(); i++) std::cout << array.at(i) << " "; std::cout << std::endl;
}

void am::fillVecRandomInt(std::vector<int>& array, int amount){
    if(!array.empty()) array.clear();
    for(int i = 0; i < amount; i++) array.push_back(rand()%amount);
}

void am::fillManually(std::vector<int> &array, int amount) {
    if(!array.empty()) array.clear();
    for(int i = 0, obj; i < amount; i++) {
        std::cout << "Enter int to push: ";
        std::cin >> obj;
        array.push_back(obj);
    }
}

void am::fillFromFile(std::vector<int> &array, std::string fileName) {
    if(!array.empty()) array.clear();
    std::ifstream file(fileName);
    int num;
    if(file.is_open()){
        std::cout << "File contains: " << std::endl;
        while (file >> num) {
            array.push_back(num);
            std::cout << num << "; ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "File named [" << fileName << "] doesn't exist!" << std::endl;
        file.close();
        return;
    }
    std::cout << "Array filled successfully;" << std::endl;
    file.close();
}

void am::saveArray(std::vector<int> &array) {
    std::string fileName;
    std::cout << "Enter name of file to save: ";
    std::cin >> fileName;
    std::fstream file;
    file.open(fileName, std::fstream::out);
    if(file.is_open()){
        for(int i = 0; i < array.size(); i++){
            file << array.at(i) << " ";
        }

    } else {
        std::cout << "Error occurred;" << std::endl;
        file.close();
        return;
    }
    std::cout << fileName <<" was created;" << std::endl;
    file.close();
}