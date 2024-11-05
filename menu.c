#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "clear.h"

void menu() {
    float total = 0;  // Inicializa o total do pedido
    char listapedido[50][50] = {0};  // Inicializa a lista do pedido
    setlocale(LC_ALL, "");
    clear_screen();

    int opcao;


        printf("            Menu            \n");
        printf("1- Hamburguer: R$ 25,00\n");
        printf("2- Pizza: R$ 39,00\n");
        printf("3- Batata Frita: R$ 10,00\n");
        printf("4- Onion Rings: R$ 12,00\n");
        printf("0- Finalizar pedido\n");
        printf("Escolha uma opcao: ");


        do {
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Tente novamente.\n");
            return;
        }
        switch (opcao) {
            case 1:
                printf("Hamburguer selecionado.\n");
                printf("Selecione outro item ou aperte 0 para finalizar o pedido.\n");
                total += 25.00;
                strcpy(listapedido[0], "1- Hamburguer: R$ 25,00");
                break;
            case 2:
                printf("Pizza selecionada.\n");
                printf("Selecione outro item ou aperte 0 para finalizar o pedido.\n");
                total += 39.00;
                strcpy(listapedido[1], "2- Pizza: R$ 39,00");
                break;
            case 3:
                printf("Batata Frita selecionada.\n");
                printf("Selecione outro item ou aperte 0 para finalizar o pedido.\n");
                total += 10.00;
                strcpy(listapedido[2], "3- Batata Frita: R$ 10,00");
                break;
            case 4:
                printf("Onion Rings selecionado.\n");
                printf("Selecione outro item ou aperte 0 para finalizar o pedido.\n");
                total += 12.00;
                strcpy(listapedido[3], "4- Onion Rings: R$ 12,00");
                break;
            case 0:
                printf("Finalizando pedido...\n");
                printf("Total: R$ %.2f\n", total);
                printf("Itens do pedido:\n");
                for (int i = 0; i < 4; i++) {
                    if (strlen(listapedido[i]) > 0) {
                        printf("%s\n", listapedido[i]);
                    }
                }
                return;
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}
