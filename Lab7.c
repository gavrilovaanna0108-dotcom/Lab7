#include <stdio.h>
#include <math.h>
#include <locale.h>

int task1(char c);
int task2(float x, char c, float y);
int task3(int fjd, int k);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    char c;
    float x, y;
    int k, fjd;

    printf("Введите символы 'a' or '1': ");
    scanf("%c", &c);

    task1(c);

    printf("Введите выражение\n");
    scanf("%f%c%f", &x, &c, &y);

    task2(x, c, y);

    scanf("%d", &fjd);
    scanf("%d", &k);

    task3(fjd, k);

    return 0;
}

int task1(char c)
{
    switch (c)

    {

    case 'a':

        printf("Это буква.\n");

        break;

    case '1':

        printf("Это цифра.\n");

        break;

    default:

        printf("Неизвестный символ\n");
    }

    return 0;
}

int task2(float x, char c, float y)
{
    switch (c)
    {
    case '+':
        printf("=%f\n", x + y);
        break;

    case '-':
        printf("=%f\n", x - y);
        break;

    case '*':
        printf("=%f\n", x * y);
        break;

    case '/':
        if (y != 0.0f)
        {
            printf("=%.2f\n", x / y);
        }
        else
        {
            printf("деление на ноль невозможно!\n");
        }
        break;

    case '^':
        printf("=%f\n", pow(x, y));
        break;

    default:
        printf("неизвестная операция '%c'\n", c);
    }

    return 0;
}

int task3(int fjd, int k)
{
    int td = ((k - 1) + (fjd - 1)) % 7 + 1;
    printf("%d-й день года - это ", k);
    switch (td)
    {
    case 1: printf("Понедельник\n"); break;
    case 2: printf("Вторник\n"); break;
    case 3: printf("Среда\n"); break;
    case 4: printf("Четверг\n"); break;
    case 5: printf("Пятница\n"); break;
    case 6: printf("Суббота\n"); break;
    case 7: printf("Воскресенье\n"); break;
    }
    return 0;
}