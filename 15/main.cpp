#include <iostream>
#include <fstream>
#include <string>

typedef struct {
    std::string name[16];
    std::string second_name[16];
    std::string third_name[16];
} Student;

void is_open(std::fstream &file, std::string &filename){
    if (!file.is_open()){
        std::cout << "Error: File " << filename << " doesn't open." << std::endl;
        exit(1);
    }
}

int main()
{
    Student str;
    std::string line, source_name = "data.txt", result_name = "result.txt";
    std::fstream source(source_name, std::ios_base::in);
    std::fstream result(result_name, std::ios_base::out);

    is_open(source, source_name);
    is_open(result, result_name);

    int flag = 0;
    while (source >> line) {
        int i = 0;
        if (flag == 0) {
            str.second_name[i] = line;
            flag = 1;
        }
        else if (flag == 1) {
            str.name[i] = line;
            flag = 2;
        }
        else {
            str.third_name[i] = line;
            flag = 0;
            result << str.name[i] << " ";
            result << str.third_name[i] << " ";
            result << str.second_name[i] << std::endl;
            i++;
        }
    }
    source.close();
    result.close();
    std::cout << "Success!" << std::endl;
    return 0;
}