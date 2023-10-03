#include <stdio.h>
#define FILAS 14
#define POLTRONAS 10

// Definindo váriaveis globais
char plateia[FILAS][POLTRONAS];
int ocupadosMeia = 0;     
int ocupadosInteiras = 0; 

void incializarLugares() // Função para criar as poltronas, inicialmente ocupadas com "-"
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < POLTRONAS; j++)
        {

            plateia[i][j] = '-';
        }
    }
}

// Função para exibir todas as poltronas, sendo elas por "-", por número ou por "m" e "i"
void mostraPlateia(int mostrarNumeros) 
{
    printf("LUGARES:\n");

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < POLTRONAS; j++) // Passa por todas as poltronas da plateia
        {   
            if (mostrarNumeros){ // Verifica se deve exibir os números das poltronas ou o tipo de ingresso vendido
                if(plateia[i][j] == 'm' || plateia[i][j] == 'i'){
                    printf("%4c", ' ');}
                else{printf("%4d", i * POLTRONAS + j + 1); 
                }
            } else{
                if(plateia[i][j] == 'm' || plateia[i][j] == 'i'){
                    printf("%4c", plateia[i][j]);
                    }
                else {
                    printf("%4c", '-');
                }
            }
        }
        printf("\n");
    }
}

void venderIngresso()
{

    int poltrona;

    while (1)
    {
        mostraPlateia(1); // Inicia mostrando a plateia com os números das poltronas vagas

        printf("Escolha sua poltrona <1..%d>: ", FILAS * POLTRONAS);
        scanf("%d", &poltrona);

        if (poltrona < 1 || poltrona > FILAS * POLTRONAS)  // Verifica se a poltrona escolhida está vaga
        {
            printf("Poltrona que voce selecionou nao existe, porfavor escolha no intervado de <1..%d>. Tente novamente.", FILAS * POLTRONAS);
            continue;
        }

        int linha = (poltrona - 1) / POLTRONAS;
        int coluna = (poltrona - 1) % POLTRONAS;

        if (plateia[linha][coluna] == '-') // A poltrona escolhida estando vaga, prosseguimos com o código
        {

            char tipo;
            printf("Qual o tipo, <m>eia ou <i>nteira: ");
            scanf(" %c", &tipo);

            if (tipo == 'm' || tipo == 'i') // Verifica o tipo de ingresso e define na matriz de poltronas
            {
                plateia[linha][coluna] = tipo;
                printf("Compra feita com sucesso!\n");

                // Verifica o tipo do ingresso e soma a contagem de meias ou inteiras.
                if (tipo == 'm')
                {
                    ocupadosMeia++; 
                }
                else
                {
                    ocupadosInteiras++; 
                }

                mostraPlateia(1); // Mostra a plateia atualizada
                break;           // Sai do loop e volta para o meno anterior
            }
            else
            {
                printf("Tipo de ingresso invalido. Escolha 'm' para meia e 'i' para inteira\n");
            }
        }
        else
        {
            printf("Poltrona Ja ocupada. Escolha outra.\n");
        }
    }
}

void mostrarOcupacao() // Verifica o total de ingressos e mostra quantos estão disponíveis de cada tipo
{
    int totallingressos = FILAS * POLTRONAS;

    mostraPlateia(0);
    printf("\n");

    int livres = totallingressos - (ocupadosMeia + ocupadosInteiras);
    int vendidos = ocupadosMeia + ocupadosInteiras;

    printf("Plateia possui %d lugares\n", livres);
    printf("Foram vendidos: %d  \n", vendidos);
    printf("%d - meias\n", ocupadosMeia);
    printf("%d - inteiras\n", ocupadosInteiras);
    return;
}

// --------------PROGRAMA PRINCIPAL--------------------
int main()
{
    incializarLugares();

    printf("-------------CINEMA-------------\n\n");

    while (1)
    {
        // Inicia o menu validando a entrada do usuário e inicia a função correspondente
        printf("|-----------------------------------|\n");
        printf("|------------   MENU   -------------|\n");
        printf("|-----------------------------------|\n");
        printf("|  0  | - Sair                      |\n");
        printf("|  1  | - Vender ingresso/ Comprar  |\n");
        printf("|  2  | - Mostrar plateia           |\n");
        printf("|  3  | - Mostrar ocupacao          |\n");
        printf("|-----------------------------------|\n");

        int opcao;
        printf("Qual sua opcao:  ");
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
            mostraPlateia(1);
            break;
        case 3:
            mostrarOcupacao();
            break; 
        default:
            printf("Opcao invalida. Escolha entre 0, 1, 2 ou 3.\n");
        }
    }
    return 0;
}