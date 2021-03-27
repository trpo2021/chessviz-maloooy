#include <libchessviz/desk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int true = 1, false = 0;
    unsigned p, Err_pos = 0;
    char Table_chess[9][9] = {};
    //разметка поля
    Table_chess[0][1] = 'a', Table_chess[0][2] = 'b', Table_chess[0][3] = 'c',
    Table_chess[0][4] = 'd', Table_chess[0][5] = 'e', Table_chess[0][6] = 'f',
    Table_chess[0][7] = 'g', Table_chess[0][8] = 'h', Table_chess[1][0] = '1',
    Table_chess[2][0] = '2', Table_chess[3][0] = '3', Table_chess[4][0] = '4',
    Table_chess[5][0] = '5', Table_chess[6][0] = '6', Table_chess[7][0] = '7',
    Table_chess[8][0] = '8';
    //Белая комманда
    Table_chess[1][1] = 'R', Table_chess[1][2] = 'N', Table_chess[1][3] = 'B',
    Table_chess[1][4] = 'Q', Table_chess[1][5] = 'K', Table_chess[1][6] = 'B',
    Table_chess[1][7] = 'N', Table_chess[1][8] = 'R';
    for (p = 0; p < 8; p++) {
        Table_chess[2][p + 1] = 'P';
    }
    //Чёрная комманда
    Table_chess[8][1] = 'r', Table_chess[8][2] = 'n', Table_chess[8][3] = 'b',
    Table_chess[8][4] = 'q', Table_chess[8][5] = 'k', Table_chess[8][6] = 'b',
    Table_chess[8][7] = 'n', Table_chess[8][8] = 'r';
    for (p = 0; p < 8; p++) {
        Table_chess[7][p + 1] = 'p';
    }
    //открытие файла
    FILE* file;
    char Name_file[30];
    do {
        printf("\nEnter correct path or file name: ");
        scanf("%s", Name_file);
        if ((file = fopen(Name_file, "r")) != NULL)
            break;
        printf("\nERROR!"); //если путь или название файла не корректны
    } while (1);
    //запись, проверка и реализация ходов
    char move[20], Err_moves[20] = {},
                   key; //может запомнить 20 номеров строк с ошибками
    int Fact_move[4] = {}, Fact_pos = 0;
    int Read_char = true, Read_number = false, Err_flag = false;
    do {
        fgets(move, 20, file);
        for (p = 3; p < strlen(move); p++) {
            key = move[p];
            //анализируем столбец
            if (Read_char == true && key >= 'a' && key <= 'h') {
                switch (key) {
                case 'a':
                    Fact_move[Fact_pos] = 1;
                    break;
                case 'b':
                    Fact_move[Fact_pos] = 2;
                    break;
                case 'c':
                    Fact_move[Fact_pos] = 3;
                    break;
                case 'd':
                    Fact_move[Fact_pos] = 4;
                    break;
                case 'e':
                    Fact_move[Fact_pos] = 5;
                    break;
                case 'f':
                    Fact_move[Fact_pos] = 6;
                    break;
                case 'g':
                    Fact_move[Fact_pos] = 7;
                    break;
                case 'h':
                    Fact_move[Fact_pos] = 8;
                    break;
                }
                Fact_pos++;
                // printf("\n%d", Fact_pos);
                Read_number = true;
                Read_char = false;
            }
            //анализируем строку
            else if (Read_number == true && key >= '1' && key <= '9') {
                switch (key) {
                case '1':
                    Fact_move[Fact_pos] = 1;
                    break;
                case '2':
                    Fact_move[Fact_pos] = 2;
                    break;
                case '3':
                    Fact_move[Fact_pos] = 3;
                    break;
                case '4':
                    Fact_move[Fact_pos] = 4;
                    break;
                case '5':
                    Fact_move[Fact_pos] = 5;
                    break;
                case '6':
                    Fact_move[Fact_pos] = 6;
                    break;
                case '7':
                    Fact_move[Fact_pos] = 7;
                    break;
                case '8':
                    Fact_move[Fact_pos] = 8;
                    break;
                }
                Fact_pos++;
                // printf("\n%d", Fact_pos);
                Read_number = false;
                Read_char = true;
            }
            // Если полностью проанализировали ход передвигаем фигуру
            if (Fact_pos > 3 && Err_flag == false) {
                key = Table_chess[Fact_move[1]][Fact_move[0]];
                Table_chess[Fact_move[1]][Fact_move[0]] = ' ';
                Table_chess[Fact_move[3]][Fact_move[2]] = key;
                Fact_pos = 0;
            }
        }
        if (Err_flag == false) {
            printf("\n%s\n\n", move);
            Print_table(Table_chess);
        }
    } while (!feof(file));

    if (Err_flag == true) {
        printf(

                "Wrong moves in these lines: ");
        for (p = 0; p < Err_pos; p++) {
            printf("%c ", Err_moves[p]);
        }
    }
    // Print_table(Table_chess);
    system("PAUSE");
}
