#include <stdio.h>
#define FILAS 14
#define POLTRONAS 10

char plateia[FILAS][POLTRONAS];

void incializarLugares()
{
    int i, j;
    for (i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < POLTRONAS; j++)
        {
            plateia[i][j] = '-';
        }
    }
}

void mostraPlateia()
{
    printf("LUGARES:\n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < POLTRONAS; j++)
        {
            printf("%4c", plateia[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    incializarLugares();

    printf("------CINEMA------");

    while (1)
    {
        printf("0 - Sair\n");
        printf("1 - ender ingresso\n");
        printf("2 - Mostrar plateia\n");
        printf("3 - Mostrar ocupação\n");

        int opcao;
        prinf("Qual sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            // Continuar as opções de cada valor
        }
    }
}