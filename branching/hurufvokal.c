#include <stdio.h>

int main()
{
    char huruf;

    printf("Masukkan huruf: ");
    scanf("%c", &huruf);

    if (huruf == 'a' || huruf == 'A' || huruf == 'e' || huruf == 'E' || huruf == 'i' || huruf == 'I' || huruf == 'o' || huruf == 'O' || huruf == 'u' || huruf == 'U')
    {
        printf("Huruf %c adalah huruf Vokal dan bukan merupakan huruf konsonan\n", huruf);
    }
    else
    {
        printf("Huruf %c adalah huruf Konsonan dan bukan merupakan huruf vokal\n", huruf);
    }

    return 0;
}