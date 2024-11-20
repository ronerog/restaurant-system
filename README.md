# Sistema de Gerenciamento de Pedidos

Este é um sistema simples de gerenciamento de pedidos em C, que permite selecionar itens de um menu, adicionar ao pedido, atualizar quantidades, visualizar o pedido atual e confirmar a compra.

## 📋 Funcionalidades

- **Exibição de Menu:** Mostra os itens disponíveis com descrição e preço.
- **Adicionar Itens:** Permite adicionar itens ao pedido, verificando se já foram selecionados anteriormente.
- **Atualizar Quantidade:** Caso o item já esteja no pedido, a quantidade e o total são atualizados automaticamente.
- **Exibição de Pedido:** Lista todos os itens adicionados, incluindo quantidade e preço total.
- **Confirmação de Pedido:** Finaliza o pedido ou permite cancelá-lo.

## 🛠️ Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

- **`main.c`:** Ponto de entrada do programa.
- **`menu.c`:** Contém as funções para gerenciar o menu e os pedidos.
- **`login.c`:** Implementa o sistema de login para acessar o menu.
- **`menu.h` e `login.h`:** Cabeçalhos que definem as funções utilizadas.

## 🚀 Como Executar

1. Certifique-se de ter um compilador C instalado (ex.: `gcc`).
2. Clone este repositório:
   ```
   git clone https://github.com/seu-usuario/sistema-pedidos.git
   cd sistema-pedidos
   ```
3. Compile o código:
```
gcc main.c menu.c login.c -o sistema-pedidos
```
4. Execute o programa:
```
./sistema-pedidos
```

## 🚀 Como Executar (caso esteja no windows)

1. Clone este repositório:
   ```
   git clone https://github.com/seu-usuario/sistema-pedidos.git
   cd sistema-pedidos
   ```
2. Abra a pasta do repositório e execute o arquivo:
```
RESTAURANT-SYSTEM.exe
```

## 🗂️ Estrutura do Código
*Principais Funções*
- menu(): Exibe o menu principal e gerencia a interação com o usuário.
- adicionar_item(Pedido pedidos[], int *length, float *total, char *descricao, float preco): Adiciona um item ao pedido ou atualiza sua quantidade caso já esteja na lista.
- exibir_pedido(Pedido pedidos[], int length, float total): Mostra os itens adicionados ao pedido com os valores totais.
- confirmar_pedido(float total): Finaliza ou cancela o pedido.
- selecionar_refrigerante(Pedido pedidos[], int *length, float *total): Permite selecionar tipos específicos de refrigerantes.

## Tipos Definidos
- Item: Representa os itens disponíveis no menu, com descrição e preço.
- Pedido: Representa os itens selecionados pelo cliente, incluindo descrição, preço total e quantidade.

## 📝 Licença
Este projeto está sob a licença MIT. Sinta-se à vontade para usar, modificar e distribuir.
