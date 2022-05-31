#include <iostream>
#include <fstream>

typedef struct university{
    char name[32];
    char details[32];
} University;

typedef struct faculty{
    char list[32];
    int score;
} Faculty;

typedef struct strct{
    University university;
    Faculty faculty;
} Strct;

void log_out(std::string str){
    std::cout << "\033[33m" << "[LOG]" << str << "\033[00m" << std::endl;
    return;
}

void struct_in(Strct &str){
    std::cout << "- University name: ";
    std::cin >> str.university.name;
    std::cout << "- Admission details: ";
    std::cin >> str.university.details;
    std::cout << "- Specialisation list: ";
    std::cin >> str.faculty.list;
    std::cout << "- Faculty minimal score: ";
    std::cin >> str.faculty.score;
}

void struct_out(Strct &str){
    std::cout << "- University name: " << str.university.name << std::endl;
    std::cout << "- Admission details: " << str.university.details << std::endl;
    std::cout << "- Specialisation list: " << str.faculty.list << std::endl;
    std::cout << "- Faculty minimal score: " << str.faculty.score << std::endl;
}

void new_file(std::fstream &fl, const std::string &path, int &counter){
    Strct str;
    fl.open(path,std::ios_base::out | std::ios::binary);
    log_out("You have to add at least one object.");
    char answer;
    while(answer != 'n'){
        struct_in(str);
        fl.write((char*)&str, sizeof(Strct));
        counter++;
        std::cout << "\033[33m" << "[LOG]" << "Continue?[y/n]: " << "\033[00m";
        std::cin >> answer;
    }
    fl.close();
    return;
}

void append_file(std::fstream &fl, const std::string &path, int &counter){
    Strct str;
    fl.open(path,std::ios_base::app);
    char answer;
    log_out("Pushing new objects: ");
    while(answer != 'n'){
        struct_in(str);
        fl.write((char*)&str, sizeof(Strct));
        std::cout << "\033[33m" << "[LOG]" << "Continue?[y/n]: " << "\033[00m";
        std::cin >> answer;
    }
    fl.close();
    return;
}

void replce_object(std::fstream &fl, const std::string &path, const int &counter){
    Strct str;
    int index = 0;
    fl.open(path, std::ios_base::in | std::ios::binary);

    std::cout << "\033[33m" << "[LOG]Type needed index: \033[00m";
    std::cin >> index;
    if(index-1 >= counter || index-1 < 0){
         log_out("Out of range.");
         return;
    }
    fl.seekp(sizeof(Strct) * (index-1));
    fl.read((char*)&str, sizeof(Strct));
    struct_out(str);

    log_out("Set new object: ");
    struct_in(str);
    fl.close();
    fl.open(path, std::ios_base::out | std::ios::binary);
    fl.seekp(sizeof(Strct) * (index-1));
    fl.write((char*)&str, sizeof(Strct));
    fl.close();
    return;
}

void read_file(std::fstream &fl, const std::string &path, int &counter){
    Strct str;
    fl.open(path, std::ios_base::in | std::ios::binary);
    log_out("File data:");
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str, sizeof(Strct));
        struct_out(str);
        std::cout << std::endl;
    }
}

int main(){
    int counter = 0;
    const std::string path = "file.b";
    std::fstream fl;
    new_file(fl, path, counter);
    replce_object(fl, path, counter);
    read_file(fl, path, counter);
}