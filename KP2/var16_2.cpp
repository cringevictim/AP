//ДА-12-16 Ніколаєв Роман, CLion

#include <iostream>

void largest_word(std::string str){
    int len = str.length();
    int start = 0, end = 0;
    int max = 0, current;
    std::string largest;
    while (end <= len){
        if (str[end] != '\0' && str[end] != ' ')//перевірка на відсутність пробілу чи кінеця строки
            end++;
        else{
            current = end - start;//довжина розглядаємого слова
            if (current > max){//визначаємо найбільше слово
                largest = str.substr(start, current);
                max = current;
            }
            end++;
            start = end;//кінець попереднього слова = початок наступного
        }
    }
    std::cout<<"Найбільше слово в тексті: "<< largest << "\nДовжина (для кирилиці подвоєна): " << largest.length();
}

int main(){
    std::string str;
    std::cout << "Введіть текст: ";//введення тексту
    std::getline(std::cin, str);
    largest_word(str);
}