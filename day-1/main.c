#include <stdio.h>
#include <stdlib.h>

int main()
{
    char temp;
    int floor = 0;

    FILE *my_file = fopen("input.txt", "r");

    int i = 0, counter = 0;
    while((temp = getc(my_file)) != EOF){
        floor += (temp == '(')? 1 :(-1);
        if(floor == -1){
            i++;
        }
        if(i == 0){
            counter++;
        }
    }

    printf("%d   %d", floor, counter);

    fclose(my_file);
    return 0;
}
