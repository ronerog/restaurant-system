#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "login.h"
#include "menu.h"

void login() {
    setlocale(LC_ALL, "");

    char login[30] = "carlos";
    char pass[10] = "123";

    char usuario[30];
    char senha[10];

    printf("Coloque seu usuario: ");
    scanf("%9s", usuario);
    printf("Coloque sua senha: ");
    scanf("%19s", senha);

    if (strcmp(login, usuario) == 0 && strcmp(pass, senha) == 0) {
        printf("Login bem-sucedido!\n");
        menu();
    } else {
        printf("Login ou senha inválidos\n");
    }
}
