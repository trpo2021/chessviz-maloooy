#include <libchessviz/desk.h>
#include <libchessviz/move.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void Checking_moves(FILE* file, unsigned int p, char Table_chess[9][9])
{
    int true = 1, false = 0;
    char move[20], Err_moves[20] = {},
                   key; 
    int Fact_move[4] = {}, Fact_pos = 0;
    unsigned Err_pos = 0;
    int Read_char = true, Read_number = false, Err_flag = false;

    do {
        fgets(move, 20, file);
        for (p = 3; p < strlen(move); p++) {
            key = move[p];

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
                default:
                    Err_flag = true;
                    break;
                }
                Fact_pos++;
                // printf("\n%d", Fact_pos);
                Read_number = true;
                Read_char = false;
            }
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
                default:
                    Err_flag = true;
                    break;
                }
                Fact_pos++;
                // printf("\n%d", Fact_pos);
                Read_number = false;
                Read_char = true;
            }
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
        } else {
            Err_moves[Err_pos] = move[0];
            Err_pos++;
            Err_flag = false;
        }
    } while (!feof(file));
    if (Err_pos > 0) {
        printf("Wrong moves in these lines: ");
        for (p = 0; p < Err_pos; p++) {
            printf("%c ", Err_moves[p]);
        }
    }
}
