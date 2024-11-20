#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "login.h"
#include "menu.h"


#define LOGIN_MAX 30
#define PASSWORD_MAX 10
#define MAX_ATTEMPTS 3


void exibir_mensagem(const char *mensagem) {
    printf("%s\n", mensagem);
}

void capturar_entrada(const char *prompt, char *buffer, int tamanho) {
    printf("%s", prompt);
    scanf("%s", buffer);
}

void login() {
    setlocale(LC_ALL, "Portuguese");

    const char login[LOGIN_MAX] = "carlos";
    const char senha[PASSWORD_MAX] = "123";

    char usuario[LOGIN_MAX];
    char tentativa_senha[PASSWORD_MAX];
    int tentativas = 0;

    while (tentativas < MAX_ATTEMPTS) {
        capturar_entrada("Coloque seu usuario: ", usuario, LOGIN_MAX);
        capturar_entrada("Coloque sua senha: ", tentativa_senha, PASSWORD_MAX);

        if (strcmp(login, usuario) == 0 && strcmp(senha, tentativa_senha) == 0) {
            exibir_mensagem("Login bem-sucedido!");
            menu();
            return;
        }

        tentativas++;
        exibir_mensagem("Login ou senha inválidos. Tente novamente.");
    }

    exibir_mensagem("Número máximo de tentativas excedido. Encerrando o programa.");
    exit(1);
}
