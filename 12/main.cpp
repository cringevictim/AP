#include <iostream>
int main()
{
    std::string input("ПОЛИЛИ_ЛИЛИЮ");
    std::cout << input << std::endl;
    int counter = 1;
    while(input.find("ЛИ") != std::string::npos){
        input.replace(input.find("ЛИ"),4,"СТО"+std::to_string(counter));
        counter++;
    }
    std::cout << input << std::endl;
    return 0;
}