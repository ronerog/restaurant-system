#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "clear.h"

void menu() {
    float total = 0;
    char listapedido[50][50];
    int length = 0;
    int quant = 0;
    char pedido[50];
    int confirma;
    setlocale(LC_ALL, "");
    clear_screen();

    int opcao;

        do {
        printf("            Menu            \n");
        printf("1- Hamburguer: R$ 25,00\n");
        printf("2- Pizza: R$ 39,00\n");
        printf("3- Batata Frita: R$ 10,00\n");
        printf("4- Onion Rings: R$ 12,00\n");
        printf("0- Finalizar pedido\n");


        printf("Selecione um item ou aperte 0 para finalizar o pedido: \n");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Tente novamente.\n");
            return;
        }

        switch (opcao) {
            case 1:
                printf("Hamburguer selecionado.\n");
                printf("Selecione a quantidade.\n");
                scanf("%i", &quant);
                total += 25.00 * quant;
                sprintf(pedido, "%i - Hamburguer: R$ %.2f", quant, quant * 25.00);
                strcpy(listapedido[length], pedido);
                length++;
                break;
            case 2:
                printf("Pizza selecionada.\n");
                printf("Selecione a quantidade\n");
                scanf("%i", &quant);
                total += 39.00 * quant;
                sprintf(pedido, "%i - Pizza: R$ %.2f", quant, quant * 39.00);
                strcpy(listapedido[length], pedido);
                length++;
                break;
            case 3:
                printf("Batata Frita selecionada.\n");
                printf("Selecione a quantidade\n");
                scanf("%i", &quant);
                total += 10.00 * quant;
                sprintf(pedido, "%i - Batata Frita: R$ %.2f", quant, quant * 10.00);
                strcpy(listapedido[length], pedido);
                length++;
                break;
            case 4:
                printf("Onion Rings selecionado.\n");
                printf("Selecione a quantidade\n");
                scanf("%i", &quant);
                total += 12.00 * quant;
                sprintf(pedido, "%i - Onion Rings: R$ %.2f", quant, quant * 12.00);
                strcpy(listapedido[length], pedido);
                length++;
                break;
            case 0:
                printf("Itens do pedido:\n");
                for (int i = 0; i < length; i++) {
                    printf("%s\n", listapedido[i]);
                }
                printf("Total: R$ %.2f\n", total);

                printf("Confirmar pedido?\n");
                printf("1- Sim\n");
                printf("2- Nao\n");
                scanf("%i", &confirma);
                if(confirma == 1) {
                printf("Pedido realizado com sucesso.\n");
                printf("Bom apetite!\n");
                } else if(confirma == 2) {
                printf("Pedido cancelado.\n");
                } else {
                printf("Opcao invalida! Tente novamente.\n");
                }
                return;
            default:
                break;
        }
    } while (opcao != 0);
}
