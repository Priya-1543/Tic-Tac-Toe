#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// forward declaration of user defined functions
int player(char arr[3][3], int chance, char p_c); // take input from player & return 1 if he wins, else return 0
void print_array(char arr[3][3]);                 // print the array
int comp(char arr[3][3], int chance);             // generates random index
int main()
{
    char p1_n[20], p2_n[20], p1_c, p2_c;
    char arr[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    // Declaring a 3 by 3 zero array
    int win = 0;    // Win will become 1 if some one wins else remains zero ; controls the flow of while loop
    int chance = 0; // It will count the round no.
    int winner;     // Will store winner's number i.e 1 or 2
    int np = 0;     // number of players
    printf("\t\t\t Lets play TIC TAC TOE !!\n\n");
    printf("\t\t\t\t Guidelines:\n\t\t*Index is given by two space separated integers\n\t\t*The first integer represent the row number\n");
    printf("\t\t*Second integer represent the column number\n\t\t*Note the integer entered should be between [1,3]\n\n");
    printf("\t\t\t\t1x1 | 1x2 | 1x3\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t2x1 | 2x2 | 2x3\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t3x1 | 3x2 | 3x3\n");
    printf("\n\n");
lable1:
    printf("Enter 1 to play with computer and 2 to play with yourfriend");
    scanf("%d", &np);
    if (np == 1)
    {
        printf("->Enter the name of player :");
        scanf(" %s", &p1_n);
        printf("\n");
        printf("-> %s please enter your favourite character :", p1_n);
        scanf(" %c", &p1_c);
    }
    else if (np == 2)
    {
        printf("->Enter the name of player 1 :");
        scanf(" %s", &p1_n);
        printf("->Enter the name of player 2 :");
        scanf(" %s", &p2_n);
        printf("\n");
        printf("-> %s please enter your favourite character :", p1_n);
        scanf(" %c", &p1_c);
        printf("-> %s please enter your favourite character (except %c) :", p2_n, p1_c);
        scanf(" %c", &p2_c);
        printf("\n");
    }
    else
    {
        printf("Invalid value entered!!");
        goto lable1;
    }
    while (win == 0)
    {
        if (chance == 9)
        { // In case of tie condition
            break;
        }
        else if (chance % 2 == 0)
        {
            printf("->chance of %s\n", p1_n);
            win = player(arr, chance, p1_c);
            if (win == 1)
            {
                winner = 1;
            }
            print_array(arr);
            chance++;
        }
        else
        {
            if (np == 1)
            {
                printf("->chance of computer\n");
                win = comp(arr, chance);
                if (win == 1)
                {
                    winner = 3;
                }
                print_array(arr);
                chance++;
            }
            else
            {
                printf("->chance of %s\n", p2_n);
                win = player(arr, chance, p2_c);
                if (win == 1)
                {
                    winner = 2;
                }
                print_array(arr);
                chance++;
            }
        }
    }
    if (winner == 1)
    {
        printf("\t\tCongratulations %s !! You win :) \a", p1_n);
    }
    else if (winner == 2)
    {
        printf("\t\tCongratulations %s !! You win :) \a", p2_n);
    }
    else if (winner == 3)
    {
        printf("\t\tSorry you loose !!Good luck next time \a");
    }
    else
    {
        printf("\t\tIt was a tie!!\a");
    }
    return 0;
}
int player(char arr[3][3], int chance, char p_c)
{
    char pi, pj;
    char c;
lable2:
    printf("->Enter the index : ");
    scanf(" %d%c%d", &pi, &c, &pj);
    printf("\n");
    if ((pi > 3) || (pj > 3))
    {
        printf("->Enter a valid index !!!\n");
        goto lable2;
    }
    else if (arr[pi - 1][pj - 1] == '-')
    {
        arr[pi - 1][pj - 1] = p_c;
    }
    else
    {
        printf("->This index is already filled . Try again!\n");
        goto lable2;
    }
    while (chance >= 4)
    {
        if (((arr[0][0] == p_c) && (arr[1][0] == p_c)) && (arr[2][0] == p_c))
        {
            return 1; // first column
        }
        else if (((arr[0][1] == p_c) && (arr[1][1] == p_c)) && (arr[2][1] == p_c))
        {
            return 1; // second column
        }
        else if (((arr[0][2] == p_c) && (arr[1][2] == p_c)) && (arr[2][2] == p_c))
        {
            return 1; // third column
        }
        else if (((arr[0][0] == p_c) && (arr[0][1] == p_c)) && (arr[0][2] == p_c))
        {
            return 1; // first row
        }
        else if (((arr[1][0] == p_c) && (arr[1][1] == p_c)) && (arr[1][2] == p_c))
        {
            return 1; // second row
        }
        else if (((arr[2][0] == p_c) && (arr[2][1] == p_c)) && (arr[2][2] == p_c))
        {
            return 1; // third row
        }
        else if (((arr[0][0] == p_c) && (arr[1][1] == p_c)) && (arr[2][2] == p_c))
        {
            return 1; // left to right diagonal
        }
        else if (((arr[0][2] == p_c) && (arr[1][1] == p_c)) && (arr[2][0] == p_c))
        {
            return 1; // right to left diagonal
        }
        else
        {
            return 0;
        }
    }
    if (chance < 4)
    {
        return 0;
    }
}
int comp(char arr[3][3], int chance)
{
    srand((unsigned)time(0));
    int p2i, p2j;
    char p2_c = 'C';
lable:
    p2i = rand() % 4;
    p2j = rand() % 4;
    if ((p2i > 3) || (p2j > 3))
    {
        goto lable;
    }
    else if (arr[p2i - 1][p2j - 1] == '-')
    {
        arr[p2i - 1][p2j - 1] = p2_c;
    }
    else
    {
        goto lable;
    }
    while (chance >= 4)
    {
        if (((arr[0][0] == p2_c) && (arr[1][0] == p2_c)) && (arr[2][0] == p2_c))
        {
            return 1; // first column
        }
        else if (((arr[0][1] == p2_c) && (arr[1][1] == p2_c)) && (arr[2][1] == p2_c))
        {
            return 1; // second column
        }
        else if (((arr[0][2] == p2_c) && (arr[1][2] == p2_c)) && (arr[2][2] == p2_c))
        {
            return 1; // third column
        }
        else if (((arr[0][0] == p2_c) && (arr[0][1] == p2_c)) && (arr[0][2] == p2_c))
        {
            return 1; // first row
        }
        else if (((arr[1][0] == p2_c) && (arr[1][1] == p2_c)) && (arr[1][2] == p2_c))
        {
            return 1; // second row
        }
        else if (((arr[2][0] == p2_c) && (arr[2][1] == p2_c)) && (arr[2][2] == p2_c))
        {
            return 1; // third row
        }
        else if (((arr[0][0] == p2_c) && (arr[1][1] == p2_c)) && (arr[2][2] == p2_c))
        {
            return 1; // left to right diagonal
        }
        else if (((arr[0][2] == p2_c) && (arr[1][1] == p2_c)) && (arr[2][0] == p2_c))
        {
            return 1; // right to left diagonal
        }
        else
        {
            return 0;
        }
    }
    if (chance < 4)
    {
        return 0;
    }
}
void print_array(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (i != 0)
        {
            printf("-----------\n");
        }
        printf("\t\t");
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf(" %c ", arr[i][j]);
            }
            else
            {
                printf(" %c |", arr[i][j]);
            }
        }
        printf("\n");
        printf("\t\t");
    }
    printf("\n");
}
