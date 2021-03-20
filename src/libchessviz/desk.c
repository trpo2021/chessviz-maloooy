#include <libchessviz/chessviz.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print_table(char Table[9][9]) // Отрисовка доски
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c", Table[i][j]);
        }
        printf("\n");
    }
}
