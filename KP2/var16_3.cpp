//ДА-12-16 Ніколаєв Роман, CLion

#include <iostream>
#include <ctime>

int sum_iterat(int *arr, int size){ //ітеративний метод
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(arr[i]%2 == 1){//сумуємо тільки непарні елементи
            sum = sum + arr[i];
        }
    }
    return sum;
}

int sum_rekurs(int *arr, int size) //рекурсивний метод
{
    if (size <= 0)//умова виходу з рекурсії
        return 0;
    if(arr[size-1] % 2 == 1){//якщо розглядаємий елемент непарний - повертаємо суму
        return (sum_rekurs(arr, size - 1) + arr[size - 1]);
    }
    else{//інакше - пропускаємо елемент
        return sum_rekurs(arr, size -1);
    }
}

int main(){
    srand(time(NULL));
    const int size = 20;//розмір масиву
    int arr[size];
    std::cout << "Масив: ";
    for(int i = 0; i < size; i++){//заповнення випадковими значеннями і вивід масиву
        arr[i] = rand()%9+1;
        std::cout << arr[i] << " ";
    }
    std::cout << "\nСума непарних елементів ітераційним методом: " << sum_iterat(arr, size) << std::endl; //виклик функцій
    std::cout << "Сума непарних елементів рекурсивним методом: " << sum_rekurs(arr, size) << std::endl;
}