#include <libchessviz/tools.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

FILE* Checking_Resources(FILE* file, char Name_file[30])
{
    do {
        printf("\nEnter correct path or file name: ");
        scanf("%s", Name_file);
        if ((file = fopen(Name_file, "r")) != NULL)
            break;
        printf("\nERROR!");
    } while (1);
    return file;
}
