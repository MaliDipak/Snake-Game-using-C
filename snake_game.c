#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int height = 30, width = 30, game_over;
int x, y, fruit_x, fruit_y, score, flag;
int tail_x[100], tail_y[100];
int count_tail;

void setup()
{
    game_over = 0;
    x = width / 2;
    y = height / 2;

lable_1:
    fruit_x = rand() % width - 1;
    if (fruit_x == 0)
    {
        goto lable_1;
    }
lable_2:
    fruit_y = rand() % height - 1;
    if (fruit_y == 0)
    {
        goto lable_2;
    }

    score = 0;
}

void draw()
{
    int i, j;
    system("cls");
    //clrscr();         ==> it is not use at that time
    printf("________________________SNAKE-GAME_________________________\n");
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            if (j == 0 || i == 0 || j == height - 1 || i == width - 1)
            {
                printf("# ");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("%c ", 2);
                }
                else if (i == fruit_x && j == fruit_y)
                {
                    printf("@ ");
                }
                else
                {
                    int ch = 0;
                    for (int k = 0; k < count_tail; k++)
                    {
                        if (i == tail_x[k] && j == tail_y[k])
                        {
                            printf("%c ", 4);
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                    {
                        printf("  ");
                    }
                }
            }
        }

        printf("\n");
    }
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a': // press a for go to the left
            flag = 1;
            break;
        case 's': // press s for go to the right
            flag = 2;
            break;
        case 'w': // press w for go to the up
            flag = 3;
            break;
        case 'z': // press z for go to the down
            flag = 4;
            break;
        case 'q': // press q to quit the game
            game_over = 1;
            break;
        }
    }
}

void make_logic()
{

    int prevX = tail_x[0];
    int prevY = tail_y[0];
    int prev2X, prev2Y;
    tail_x[0] = x;
    tail_y[0] = y;

    for (int i = 1; i < count_tail; i++)
    {
        prev2X = tail_x[i];
        prev2Y = tail_y[i];
        tail_x[i] = prevX;
        tail_y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }
    if (x < 1 || x + 2 > width || y < 1 || y + 2 > height)
    {
        game_over = 1;
    }
    for (int sti = 0; sti < count_tail; sti++) // sti = snake touch itself
    {
        if (x == tail_x[sti] && y == tail_y[sti])
        {
            game_over = 1;
        }
    }

    if (x == fruit_x && y == fruit_y)
    {
    lable_3:
        fruit_x = rand() % width - 1;
        if (fruit_x == 0)
        {
            goto lable_3;
        }
    lable_4:
        fruit_y = rand() % height - 1;
        if (fruit_y == 0)
        {
            goto lable_4;
        }
        score += 10;
        count_tail++;
    }
}

void speed()
{
    int speed = 1000;
    for (int i = 0; i < speed; i++)
    {
        for (int i = 0; i < speed; i++)
        {
            /* we use loop for reducing the speed */
        }
    }
}

int main()
{
    char c11;

    setup();

    while (!game_over)
    {
        draw();
        input();
        make_logic();
        speed();
    }
    printf("  GAME_OVER\t\t\t\tYour_score_is :- %d", score);
    printf("\n\n\n");

    return 0;
}
