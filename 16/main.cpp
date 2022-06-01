#include <stdio.h>
#define PRINT printf("This text is on line %d, name of file: %s\n",__LINE__,__FILE__);
#define N 5


int main()
{
    PRINT;
#line 10
    PRINT;
#line 20 "HELLO.cpp"
    PRINT;
    int mas[N];
    for (int i = 0; i < N; i++) {
        mas[i] = i;
        printf("mas[%d] = %d\n", i, i);
    }
    PRINT;
}