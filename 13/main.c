#include <stdio.h>

FILE* file;

char filepath[] = "../../13/";
char filename[] = "default.txt";

void choose_name(){
    printf("Current name of file: %s", filename);
    puts("\nEnter name of file for write:");
    scanf("%s", &filename);
}

void create_file(){
    file = fopen(filename, "w");
    int a, b, c;
    puts("Enter length of the first side:");
    scanf("%d", &a);
    fprintf(file, "%d\n", a);
    puts("Enter length of the second side:");
    scanf("%d", &b);
    fprintf(file, "%d\n", b);
    puts("Enter length of the third side:");
    scanf("%d", &c);
    fprintf(file, "%d\n", c);
    fclose(file);
}

void read_data(){
    printf("Selected file: %s\n", filename);
    file = fopen(filename, "r");
    char s[100];
    while(!feof(file)){
        fgets(s,100,file);
        if(feof(file)) break;
        puts(s);
    }
    fclose(file);
}

void process_data(){
    file = fopen(filename, "r");
    int side1, side2, side3;
    fscanf (file, "%d %d %d", &side1, &side2, &side3);
    file = fopen(filename, "a");
    if(side1 == side2 && side2 == side3){
        printf("The Given triangle is equilateral\n");
        fputs("equilateral", file);
    }
    else if(side1 == side2 || side2 == side3 || side3 == side1){
        printf("The given triangle is isosceles\n");
        fputs("isosceles", file);
    }
    else if(side1+side2 < side3 || side1+side3 < side2 || side3+side2 < side1){
        printf("The given triangle doesn't exist\n");
        fputs("not_a_triangle", file);
    } else{
        printf("The given triangle is arbitrary\n");
        fputs("arbitrary", file);
    }
    fclose(file);
}

int main()
{
    while(1){
        puts("MENU:\n1.Choose name of file\n2.Create file\n3.Read data from file\n4.Process data from file\n5.Exit\nChoosen menu item: ");
        int item;
        scanf("%d", &item);
        if(item == 1){
            choose_name();
        }else if(item == 2){
            create_file();
        }else if(item == 3){
            read_data();
        }else if(item == 4){
            process_data();
        }else if(item == 5){
            break;
        }
    }
    return 0;
}

