#include <iostream>
#include <vector>
#include <bits/stdc++.h>

typedef struct university{
    char name[32];
    int details;
} University;

typedef struct faculty{
    char list[32];
    int score;
} Faculty;

typedef struct strct{
    University university;
    Faculty faculty;
} Strct;

void log_out(const std::string &str){
    std::cout << "\033[33m" << "[LOG]" << str << "\033[00m" << std::endl;
}

void struct_in(Strct &str){
    std::cout << "(without spaces)" << std::endl;
    std::cout << "- University name: ";
    std::cin >> str.university.name;
    std::cout << "- Admission details (int): ";
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

void menu(){
    log_out("Menu:");
    std::cout << "0: Exit." << std::endl;
    std::cout << "1: Create an array and a new file using array data." << std::endl;
    std::cout << "2: Append existing file." << std::endl;
    std::cout << "3: Replace object in file." << std::endl;
    std::cout << "4: Remove object in file." << std::endl;
    std::cout << "5: Read data." << std::endl;
    std::cout << "6: Call 1." << std::endl;
    std::cout << "7: Call 2." << std::endl;
    std::cout << "8: Call 3." << std::endl;
    std::cout << "- Choose an option: ";
}

void create_array(std::vector<Strct> &array, int &counter){
    array.clear();
    Strct str;
    char answer;
    while(answer != 'n'){
        struct_in(str);
        array.push_back(str);
        counter++;
        std::cout << "\033[33m" << "[LOG]" << "Continue?[y/n]: " << "\033[00m";
        std::cin >> answer;
    }
}

void new_file(std::fstream &fl, const std::string &path, int &counter, std::vector<Strct> &array){
    std::remove("file.b");
    counter = array.size();
    fl.open(path,std::ios_base::out | std::ios::binary);
    for(int i = 0; i < counter; i++){
        fl.write((char*)&array[i], sizeof(Strct));
    }
    fl.close();
    log_out("New file was created");
}

void append_file(std::fstream &fl, const std::string &path, int &counter){
    Strct str;
    fl.open(path,std::ios_base::app);
    char answer;
    log_out("Append file with new objects: ");
    while(answer != 'n'){
        struct_in(str);
        fl.write((char*)&str, sizeof(Strct));
        counter++;
        std::cout << "\033[33m" << "[LOG]" << "Continue?[y/n]: " << "\033[00m";
        std::cin >> answer;
    }
    fl.close();
}

void replace_object(std::fstream &fl, const std::string &path, const int &counter){
    log_out("Replacing object.");
    Strct str, str_to_replace, str_new;
    int index = 0;
    std::cout << "\033[33m" << "[LOG]Type needed index: \033[00m";
    std::cin >> index;
    if(index-1 >= counter || index-1 < 0){
         log_out("Out of range.");
         fl.close();
         return;
    }

    fl.open(path, std::ios_base::in | std::ios::binary);
    for(int i = 0; i < index; i++) fl.read((char*)&str_to_replace, sizeof(Strct));
    fl.close();
    struct_out(str_to_replace);
    log_out("Set new object: ");
    struct_in(str_new);
    std::fstream fl_new;
    fl.open(path, std::ios_base::in | std::ios::binary);
    fl_new.open("new_file.b", std::ios_base::out | std::ios::binary);
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str, sizeof(Strct));
        if(i == index-1){
            fl_new.write((char*)&str_new, sizeof(Strct));
        } else fl_new.write((char*)&str, sizeof(Strct));
    }
    fl.close();
    fl_new.close();
    std::remove("file.b");
    std::rename("new_file.b", "file.b");
}

void remove_object(std::fstream &fl, const std::string &path, int &counter){
    log_out("Removing object.");
    Strct str, str_to_remove;
    int index = 0;
    std::cout << "\033[33m" << "[LOG]Type needed index: \033[00m";
    std::cin >> index;
    if(index-1 >= counter || index-1 < 0){
        log_out("Out of range.");
        fl.close();
        return;
    }

    fl.open(path, std::ios_base::in | std::ios::binary);
    for(int i = 0; i < index; i++) fl.read((char*)&str_to_remove, sizeof(Strct));
    fl.close();
    struct_out(str_to_remove);
    std::fstream fl_new;
    fl.open(path, std::ios_base::in | std::ios::binary);
    fl_new.open("new_file.b", std::ios_base::out | std::ios::binary);
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str, sizeof(Strct));
        if(i != index-1){
            fl_new.write((char*)&str, sizeof(Strct));
        }
    }
    counter--;
    fl.close();
    fl_new.close();
    std::remove("file.b");
    std::rename("new_file.b", "file.b");
}

void read_file(std::fstream &fl, const std::string &path, int &counter){
    Strct str;
    fl.open(path, std::ios_base::in | std::ios::binary);
    log_out("File data:");
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str, sizeof(Strct));
        std::cout << "- Index: " << i+1 << std::endl;
        struct_out(str);
        std::cout << "---------------------------------" << std::endl;
    }
    fl.close();
}

std::string call_1(std::fstream &fl, const std::string &path, int &counter){
    int score;
    std::string result;
    std::cout << "Enter minimal score: ";
    std::cin >> score;

    Strct str;
    fl.open(path, std::ios_base::in | std::ios::binary);
    log_out("Call results:");
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str, sizeof(Strct));
        if(str.faculty.score >= score){
            result.append(str.university.name);
            result.append(": ");
            result.append(str.faculty.list);
            result.append("\n");
        }
    }
    fl.close();
    return result;
}

bool operator<(const Strct &a, const Strct &b){
    if(a.faculty.score > b.faculty.score){
        return true;
    } else if(a.faculty.score < b.faculty.score){
        return false;
    } else if(a.university.details > b.university.details){
        return true;
    } else if(a.university.details < b.university.details){
        return false;
    } else return false;
}

void call_2(std::fstream &fl, const std::string &path, int &counter){
    std::vector<Strct> array;
    Strct str;
    fl.open(path, std::ios_base::in | std::ios::binary);
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str,sizeof(Strct));
        array.push_back(str);
    }
    std::sort(array.begin(), array.end());
    fl.close();
    new_file(fl, path, counter, array);
    read_file(fl, path, counter);
}

std::string call_3(std::fstream &fl, const std::string &path, int &counter){
    std::string result = "University name(s): ";
    int score;
    Strct str;
    std::cout << "Enter the score: ";
    std::cin >> score;
    fl.open(path, std::ios_base::in | std::ios::binary);
    for(int i = 0; i < counter; i++){
        fl.read((char*)&str,sizeof(Strct));
        if(str.faculty.score >= score){
            result.append(str.university.name);
            result.append(", ");
        }
    }
    fl.close();
    return result;
}

int main(){
    std::remove("file.b");
    int counter = 0;
    const std::string path = "file.b";
    std::fstream fl;
    std::vector<Strct> array;

    int choice = 1;
    while(choice != 0){
        menu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                create_array(array, counter);
                new_file(fl, path, counter, array);
                break;
            }
            case 2: {
                append_file(fl, path, counter);
                break;
            }
            case 3: {
                replace_object(fl, path, counter);
                break;
            }
            case 4: {
                remove_object(fl, path, counter);
                break;
            }
            case 5: {
                read_file(fl, path, counter);
                break;
            }
            case 6: {
                std::cout << call_1(fl, path, counter) << std::endl;
                break;
            }
            case 7: {
                call_2(fl, path, counter);
                break;
            }
            case 8: {
                std::cout << call_3(fl, path, counter) << std::endl;
                break;
            }
            default: {
                log_out("Invalid option");
                break;
            }
        }
    }
    return 0;
}