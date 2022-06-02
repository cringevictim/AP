#include <iostream>

#define PRINT_ERROR(reason) \
    std::cerr << "An error occured in file " << __FILE__ \
    << " in function " << __func__ << " on line " << __LINE__ << ". " \
    << "Reason: " << (reason) << std::endl

float div(float &a, float &b){
    if(!b) {
        PRINT_ERROR("Division by zero");
        exit(1);
    }
    else return a/b;
}

int main()
{
    float a = 10, b = 0, result;
    result = div(a,b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}