#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

void printPrettyPower(int uglyPower)
{
    int prettyDigits[10];
    prettyDigits[0] = 0x2070;
    prettyDigits[1] = 0x00B9;
    prettyDigits[2] = 0x00B2;
    prettyDigits[3] = 0x00B3;
    prettyDigits[4] = 0x2074;
    prettyDigits[5] = 0x2075;
    prettyDigits[6] = 0x2076;
    prettyDigits[7] = 0x2077;
    prettyDigits[8] = 0x2078;
    prettyDigits[9] = 0x2079;

    setlocale(LC_CTYPE, "");

    int sizeOfDigit = 30;
    int* result = malloc(sizeOfDigit);
    int index = 0;
    for (index = 0; index < sizeOfDigit && uglyPower != 0; index++)
    {
        result[index] = uglyPower % 10;
        uglyPower = (uglyPower - uglyPower % 10) / 10;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        wprintf(L"%lc", prettyDigits[result[i]]);
    }
}

int main(int argc, char const *argv[])
{
    int numberOfPowers = 0;
    printf("Введите количество разных степеней: ");
    scanf("%d", &numberOfPowers);

    int* powersAndOdds = malloc(sizeof(int) * 3 * numberOfPowers);
    printf("Введите знаки, коэффициенты и степени: ");
    for (int i = 0; i < numberOfPowers; i++)
    {
        scanf("%ls %d %d", &powersAndOdds[i], &powersAndOdds[i + 1], &powersAndOdds[i + 2]);
    }
    
    for (int i = 0; i < numberOfPowers; i++)
    {
        printf("%c%dx", powersAndOdds[i], powersAndOdds[i + 1]);
        printPrettyPower(powersAndOdds[i + 2]);
    }
    return 0;
}
