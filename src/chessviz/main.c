#include <libchessviz/desk.h>
#include <libchessviz/move.h>
#include <libchessviz/picture.h>
#include <libchessviz/tools.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned int p = 0;
    char Table_chess[9][9] = {};
    //
    Preparation(Table_chess); // ��������� ������ �� �����
    //
    FILE* file = 0;
    char Name_file[30];

    file = Checking_Resources(file, Name_file);
    //��������� �� �����  �� ���� � ������

    Checking_moves(file, p, Table_chess);

    Print_table(Table_chess);
    return 1;
}
