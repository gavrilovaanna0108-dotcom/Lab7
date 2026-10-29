#include <stdio.h>
#include <math.h>
#include <locale.h>

int task1(char c);
int task2(float x, char c, float y, float *result);
int task3(int fjd, int k);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    char c;
    float x, y;
    int k, fjd;

    if (scanf("%c", &c) == 1) {
        int type = task1(c);
        if (type == 1) {
            printf("Это цифра.\n");
        } else if (type == 2) {
            printf("Это буква.\n");
        } else {
            printf("Неизвестный символ\n");
        }
    }

    if (scanf("%f%c%f", &x, &c, &y) == 3) {
        float calc_res = 0.0f;
        int status = task2(x, c, y, &calc_res);
        
        if (status == 0) {
            printf("= %f\n", calc_res);
        } else if (status == 1) {
            printf("Деление на ноль невозможно!\n");
        } else {
            printf("Неизвестная операция '%c'\n", c);
        }
    }

    if (scanf("%d %d", &fjd, &k) == 2) {
        int day_of_week = task3(fjd, k);
        
        printf("%d-й день года - это ", k);
        switch (day_of_week)
        {
            case 1: printf("Понедельник\n"); break;
            case 2: printf("Вторник\n"); break;
            case 3: printf("Среда\n"); break;
            case 4: printf("Четверг\n"); break;
            case 5: printf("Пятница\n"); break;
            case 6: printf("Суббота\n"); break;
            case 7: printf("Воскресенье\n"); break;
        }
    }

    return 0;
}

int task1(char c)
{
    int ans;

    switch (c)
    {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ans = 1;
            break;
        default:
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                ans = 2;
            }
            else
            {
                ans = 0;
            }
            break;
    }
    return ans;
}

int task2(float x, char c, float y, float *result)
{
    switch (c)
    {
        case '+':
            *result = x + y;
            return 0;
        case '-':
            *result = x - y;
            return 0;
        case '*':
            *result = x * y;
            return 0;
        case '/':
            if (y == 0.0f) {
                return 1;
            }
            *result = x / y;
            return 0;
        case '^':
            *result = powf(x, y);
            return 0;
        default:
            return 2;
    }
}

int task3(int fjd, int k)
{
    return ((k - 1) + (fjd - 1)) % 7 + 1;
}
