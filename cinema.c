
#include <stdio.h>
#define FILAS 14
#define POLTRONAS 10

char plateia[FILAS][POLTRONAS];
int ocupadosMeia = 0;     // Contador começando em 0
int ocupadosInteiras = 0; // Contador começando em 0

void incializarLugares()
{
    for (int i = 0; i < FILAS; i++)
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

void venderIngresso()
{

    int poltrona;

    while (1)
    {

        mostraPlateia();
        printf("Escolha sua poltrona <1..%d>: ", FILAS * POLTRONAS);
        scanf("%d", &poltrona);

        if (poltrona < 1 || poltrona > FILAS * POLTRONAS)
        {
            printf("Poltrona que você selecionou não existe, porfavor escolha no intervado de <1..%d>. Tente novamente.", FILAS * POLTRONAS);
            continue;
        }

        int linha = (poltrona - 1) / POLTRONAS;
        int coluna = (poltrona - 1) % POLTRONAS;

        if (plateia[linha][coluna] == '-')
        {

            char tipo;
            printf("Qual o tipo, <m>eia ou <i>nteira: ");
            scanf(" %c", &tipo);

            if (tipo == 'm' || tipo == 'i')
            {
                plateia[linha][coluna] = tipo;
                printf("Compra feita com sucesso!\n");

                if (tipo == 'm')
                {
                    ocupadosMeia++;
                }
                else
                {
                    ocupadosInteiras++;
                }

                mostraPlateia(); // Mostra a plateia atualizada
                break;           // Sai do loop e volta para o meno anterior
            }
            else
            {
                printf("Tipo de ingresso invalido. Escolha 'm' para meia e 'i' para inteira\n");
            }
        }
        else
        {
            printf("Poltrona Já ocupada. Escolha outra.\n");
        }
    }
}

void mostrarOcupacao()
{
    int totallingressos = FILAS * POLTRONAS;

    mostraPlateia();
    printf("\n");

    int livres = totallingressos - (ocupadosMeia + ocupadosInteiras);
    int vendidos = ocupadosMeia + ocupadosInteiras;

    printf("Plateia possui %d lugares\n", livres);
    printf("Foram vendidos: %d  \n", vendidos);
    printf("%d - meias\n", ocupadosMeia);
    printf("%d - inteiras\n", ocupadosInteiras);
    return;
}

int main()
{
    incializarLugares();

    printf("------CINEMA------\n");

    while (1)
    {
        printf("---------------MENU---------------\n");
        printf("0 - Sair\n");
        printf("1 - Vender ingresso/ Comprar\n");
        printf("2 - Mostrar plateia\n");
        printf("3 - Mostrar ocupação\n");
        printf("------------------------------------\n");

        int opcao;
        printf("Qual sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Obrigado por usar o nosso sistema!\n");
            return 0;
        case 1:
            venderIngresso();
            break;
        case 2:
            mostraPlateia();
            break;
        case 3:
            mostrarOcupacao();
            break; // Necesssario pois estava exibindo a msg de erro apos clicar no 03
        default:
            printf("Opção invalida. Escolha entre 0, 1, 2 ou 3.\n");
        }
    }
    return 0;
}