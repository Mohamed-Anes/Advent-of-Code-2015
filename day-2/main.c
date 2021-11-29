#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minOf2(int x,int y);
int minOf3(int x,int y, int z);
int maxOf2(int x,int y);
int maxOf3(int x,int y, int z);


int main()
{
    FILE *my_file = fopen("input.txt", "r");

    char *dimensions = malloc(sizeof(char) * 10);
    char temp;

    int l, w, h, x, y, z;
    long paper_length = 0, ribbon_length = 0;

    while((temp = getc(my_file)) != EOF){
        //getting dimensions
        dimensions[0] = temp;
        fscanf(my_file, "%s", dimensions + 1);

        l = atoi(dimensions);
        w = atoi(strchr(dimensions, 'x') + 1);
        h = atoi(strrchr(dimensions, 'x') + 1);

        printf("%dx%dx%d\n", l, w, h);
        //computing size of wrapping paper
        x = l*w;
        y = w*h;
        z = l*h;

        paper_length += 2*x + 2*y + 2*z;
        paper_length += minOf3(x, y, z);

        //computing length of ribbon
        ribbon_length += l*w*h;

        x = maxOf3(l, w, h);
        ribbon_length += l + l + w + w + h + h - x - x;

        }
    //continue size of wrapping paper, subtracting repeated value at end of loop
    paper_length -= 2*x + 2*y + 2*z;
    paper_length -= minOf3(x, y, z);

    //continue length of ribbon, subtracting repeated value at end of loop
    ribbon_length -= l*w*h;
    ribbon_length -= l + l + w + w + h + h - x - x;

    printf("%ld\n%ld", paper_length, ribbon_length);


    fclose(my_file);
    return 0;
    }



int minOf2(int x,int y){
    return (x > y)? y: x;
    }

int minOf3(int x, int y, int z){
    return minOf2(x, minOf2(y, z));
    }

int maxOf2(int x,int y){
    return (x < y)? y: x;
    }

int maxOf3(int x, int y, int z){
    return maxOf2(x, maxOf2(y, z));
    }

