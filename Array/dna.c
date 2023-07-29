#include <stdio.h>
#include <string.h>

int main()
{
    char dna[100];
    int i, length;

    printf("Masukan rantai primer : ");
    scanf("%s", dna);

    length = strlen(dna);

    char dna2[length + 1];

    for (i = 0; i < length; i++)
    {
        if (dna[i] == 'A')
        {
            dna2[i] = 'T';
        }
        else if (dna[i] == 'T')
        {
            dna2[i] = 'A';
        }
        else if (dna[i] == 'C')
        {
            dna2[i] = 'G';
        }
        else if (dna[i] == 'G')
        {
            dna2[i] = 'C';
        }
    }

    dna2[length] = '\0';

    printf("Rantai sekunder : ");
    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", dna2[i]);
    }

    return 0;
}
