#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    const int size = 10;
    int array[size] = {8,2,6,4,5,1,7,8,0,9};
    std::sort_heap(array, (array+size-1));

    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }

    return 0;
}