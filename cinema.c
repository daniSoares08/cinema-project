#include <stdio.h>
#define FILAS 14
#define POLTRONAS 10

char plateia[FILAS][POLTRONAS];
int vendidosMeia = 0; // Contador começando em 0 
int vendidosInteira = 0; // Contador começando em 0 

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

void venderIngresso(){

    mostraPlateia();
    int poltrona;

    while (1){
        printf("Escolha sua poltrona <1..%d>: ", FILAS * POLTRONAS);
        scanf("%d" , &poltrona);

        if (poltrona < 1 || poltrona > FILAS * POLTRONAS){
            printf("Poltrona que você selecionou não existe, porfavor escolha no intervado de <1..%d>. Tente novamente.", FILAS * POLTRONAS);
            continue;
        }
        
        int linha = (poltrona - 1) / POLTRONAS;
        int coluna = (poltrona - 1) / POLTRONAS;

        if (plateia [linha][coluna] == '-'){
            
            char tipo;
            printf("Qual o tipo, <m>eia ou <i>nteira: ");
            scanf(" %c", &tipo);

            if (tipo == 'm'|| tipo == 'i'){
                plateia[linha][coluna] = tipo;
                printf("Compra feita com sucesso!\n");

                if (tipo == 'm'){
                    vendidosMeia++;
                } else {
                    vendidosInteira++;
                }
            } else {
                printf("Tipo de ingresso invalido. Escolha 'm' para meia e 'i' para inteira\n");
            }
        }   else {
            printf("Poltrona Já ocupada. Escolha outra.\n");

        }
    }
}


void mostrarOcupacao(){
    int totalIngressos = FILAS * POLTRONAS;
    int ocupados = vendidosMeia = vendidosInteira;
    int livres = totalIngressos - ocupados;

    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < POLTRONAS; j++){
            if (plateia[i][j] == 'm' || plateia[i][j] == 'i'){
                printf("%2c ", plateia[i][j]);
            }
            else{
                printf("_ ");
            }
        }
        printf("\n");
    }

    printf("Plateia possui %d lugares\n", totalIngressos);
    printf("Foram vendidos %d ingressos, sendo:\n", ocupados);
    printf("%d - meias\n",vendidosMeia);
    printf("%d - inteiras\n", vendidosInteira);
}

int main()
{
    incializarLugares();

    printf("------CINEMA------");

    while (1)
    {
        printf("0 - Sair\n");
        printf("1 - Vender ingresso\n");
        printf("2 - Mostrar plateia\n");
        printf("3 - Mostrar ocupação\n");

        int opcao;
        printf("Qual sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 0:
                printf("Obrigado por usar o nosso sistema!\n");
                return 0;
            case 1:
                venderIngresso();
                break;
            case 3:
                mostrarOcupacao();
                break;
            default:
                printf("Opção invalida. Escolha entre 0, 1, ou 3.\n");  
        }
    }
    return 0;
}