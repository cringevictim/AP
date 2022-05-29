#include <iostream>

int main(){
    std::cout << "Input string: ";
    std::string str;
    getline(std::cin, str);
    if(*str.end() != ' ') str.push_back(' ');
    int counter = 0, tmp_counter = 0;
    std::cout << "Words: ";
    for(int i = 0; i < str.size(); i++){
        if(str.at(i) == ',' || str.at(i) == '.'){//рахування к-ті знаків пунктуації
            counter++;
        }
        if(str.at(i) == ' ' || str.at(i) == ',' || str.at(i) == '.'){//індикатор кінця слова
            if(tmp_counter != 0 && tmp_counter%2 == 0){//умова виведення слова
                for(int j = tmp_counter; j > 0; j--){//цикл виведення окремого слова
                    std::cout << str.at(i-j);
                }
                std::swap(str.at(i-tmp_counter), str.at(i-1));//зміна місць першої і останньої літери в слові
                std::cout << ", ";
            }
            tmp_counter = 0;
        } else tmp_counter++;
    }
    std::cout << "\nCounter: " << counter << std::endl;
    std::cout << "Result string: " << str << std::endl;
}