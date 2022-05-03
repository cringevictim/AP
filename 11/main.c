#include <stdio.h>

//Input:
//200
//aaee eeaa aaaa eeee bbbb bbee aabb bbaa eebb abobuse ae ab be eb ba aa ee aa
//Expected result: 3

int main()
{
    int len;
    printf("Enter the maximum size of string: ");
    scanf("%d", &len);
    len=len+1;

    char str[len];
    for(int i = 0; i < len; i++)
    {
        str[i] = ' ';
    }

    char c;
    printf("Enter the string: ");
    scanf("%c", &c);
    fgets(str, len, stdin);
    printf("String: %s", str);

    int check_a, check_e, counter = 0;
    for(int i = 0; i<len; i++)
    {
        if(str[i] == 32 || str[i] == 0 || str[i] == 10)
        {
            check_a = 0, check_e = 0;
        }
        if(str[i] == 'a')
        {
            if(i == 0 || str[i-1] == 32)
            {
                check_a = 1;
            }
        }
        if(str[i] == 'e')
        {
            if(i == len || str[i+1] == 32 || str[i+1] == 10)
            {
                check_e = 1;
            }
        }
        if(check_a == 1 && check_e == 1)
        {
            counter = counter + 1;
        }
        //printf("\nCycle: %d, check_a: %d, check_e: %d, char: %c, char_int: %d", i, check_a, check_e, str[i], str[i]);
    }
    printf("\nAmount: %d", counter);
    return 0;
}