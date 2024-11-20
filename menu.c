#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "login.h"

#define MAX_ITEMS 50
#define MAX_DESC 50

typedef struct {
    char descricao[MAX_DESC];
    float preco_total;
    int quantidade;
} Pedido;

void exibir_menu();
int selecionar_opcao();
void adicionar_item(Pedido pedidos[], int *length, float *total, char *descricao, float preco);
void exibir_pedido(Pedido pedidos[], int length, float total);
void confirmar_pedido(float total);
void selecionar_refrigerante(Pedido pedidos[], int *length, float *total);
int encontrar_item(Pedido pedidos[], int length, char *descricao);

void menu() {
    Pedido pedidos[MAX_ITEMS];
    int length = 0;
    float total = 0;
    int opcao;

    setlocale(LC_ALL, "Portuguese");

    do {
        exibir_menu();
        opcao = selecionar_opcao();

        switch (opcao) {
            case 1:
                adicionar_item(pedidos, &length, &total, "Hamburgao", 30.00);
                break;
            case 2:
                adicionar_item(pedidos, &length, &total, "Frangolino", 26.00);
                break;
            case 3:
                adicionar_item(pedidos, &length, &total, "Batata Frita", 10.00);
                break;
            case 4:
                adicionar_item(pedidos, &length, &total, "Onion Rings", 12.00);
                break;
            case 5:
                selecionar_refrigerante(pedidos, &length, &total);
                break;
            case 0:
                exibir_pedido(pedidos, length, total);
                confirmar_pedido(total);
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void exibir_menu() {
    printf("            Menu            \n");
    printf("1- Hamburgao: R$ 30,00\n");
    printf("(Pao, Queijo Prato, Hamburguer Bovino de 160g, Alface e Tomate.)\n");
    printf("2- Frangolino: R$ 26,00\n");
    printf("(Pao, Peito de Frango empanado, picles e maionese da casa.)\n");
    printf("3- Batata Frita: R$ 10,00\n");
    printf("4- Onion Rings: R$ 12,00\n");
    printf("(Cebolas empanadas e fritas. Acompanha molho rose.)\n");
    printf("5- Refrigerante: R$ 5,00\n");
    printf("0- Finalizar pedido\n");
    printf("Selecione um item ou aperte 0 para finalizar o pedido: \n");
}

int selecionar_opcao() {
    int opcao;
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida! Tente novamente.\n");
        return -1;
    }
    return opcao;
}

int encontrar_item(Pedido pedidos[], int length, char *descricao) {
    for (int i = 0; i < length; i++) {
        if (strcmp(pedidos[i].descricao, descricao) == 0) {
            return i;
        }
    }
    return -1;
}

void adicionar_item(Pedido pedidos[], int *length, float *total, char *descricao, float preco) {
    int quantidade;
    printf("\n%s selecionado.\n", descricao);
    printf("Selecione a quantidade:\n");
    scanf("%d", &quantidade);

    int index = encontrar_item(pedidos, *length, descricao);

    if (index != -1) {
        pedidos[index].quantidade += quantidade;
        pedidos[index].preco_total += preco * quantidade;
        printf("Quantidade atualizada para %d. Total: R$ %.2f\n", pedidos[index].quantidade, pedidos[index].preco_total);
    } else {
        pedidos[*length].quantidade = quantidade;
        strcpy(pedidos[*length].descricao, descricao);
        pedidos[*length].preco_total = preco * quantidade;
        (*length)++;
        printf("Item adicionado com sucesso!\n");
    }

    *total += preco * quantidade;
    system("cls");
}

void exibir_pedido(Pedido pedidos[], int length, float total) {
    printf("\nItens do pedido:\n");
    for (int i = 0; i < length; i++) {
        printf("%d - %s: R$ %.2f\n", pedidos[i].quantidade, pedidos[i].descricao, pedidos[i].preco_total);
    }
    printf("Total: R$ %.2f\n", total);
}

void confirmar_pedido(float total) {
    int confirma;
    printf("\nConfirmar pedido?\n");
    printf("1- Sim\n");
    printf("2- Nao\n");
    scanf("%d", &confirma);

    if (confirma == 1) {
        printf("Pedido realizado com sucesso.\nBom apetite!\n");
    } else if (confirma == 2) {
        printf("Pedido cancelado.\n");
    } else {
        printf("Opcao invalida! Tente novamente.\n");
    }
}

void selecionar_refrigerante(Pedido pedidos[], int *length, float *total) {
    int tipo, quantidade;
    char descricao[MAX_DESC];

    do {
        printf("\nRefrigerante selecionado.\n");
        printf("Escolha o tipo:\n1- Coca-Cola\n2- Guarana\n");
        scanf("%d", &tipo);
        if (tipo == 1) {
            strcpy(descricao, "Coca-Cola");
            break;
        } else if (tipo == 2) {
            strcpy(descricao, "Guarana");
            break;
        } else {
            printf("Opcao Invalida. Por favor, escolha 1 ou 2.\n");
        }
    } while (tipo != 1 && tipo != 2);

    adicionar_item(pedidos, length, total, descricao, 5.00);
}
