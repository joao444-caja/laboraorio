# laboraorio
#include <stdio.h>


char clientes[10][50];
char produtos[10][50];
int total_clientes = 0;
int total_produtos = 0;

void cadastrar_cliente() {
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[total_clientes]);
    printf("Cliente %s cadastrado com sucesso!\n", clientes[total_clientes]);
    total_clientes++;
}
void cadastrar_produto() {
    char produto;
    printf("Digite o nome do produto: ");
    scanf("%s", produtos[total_produtos]);
    printf("Produto %s cadastrado com sucesso!\n", produtos[total_produtos]);
    total_produtos++;
}
void cadastrar_venda() {
    char cliente[50], produto[50];
    int quantidade;
    printf("Digite o nome do cliente: ");
    scanf("%s", cliente);
    printf("Digite o nome do produto: ");
    scanf("%s", produto);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);
    printf("Venda cadastrada com sucesso! Cliente: %s, Produto: %s, Quantidade: %d\n", cliente, produto, quantidade);
}
void listar_clientes() {
   if (total_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("Clientes cadastrados:\n");
        for (int i = 0; i < total_clientes; i++) {
            printf("%s\n", clientes[i]);
        }
    }
}
void listar_produtos() {
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("Produtos cadastrados:\n");
        for (int i = 0; i < total_produtos; i++) {
            printf("%s\n", produtos[i]);
        }
    }
}

int main() {
int opcao = -1;
do {
    printf("MENU\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Produto\n");
    printf("3. Cadastrar Venda\n");
    printf("4. Listar Clientes\n");
    printf("5. Listar Produtos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        cadastrar_cliente();
    } else if (opcao == 2) {
        cadastrar_produto();
    } else if (opcao == 3) {
        cadastrar_venda();
    } else if (opcao == 4) {
        listar_clientes();
    } else if (opcao == 5) {
        listar_produtos();
    } else if (opcao != 0) {
        printf("Opcao invalida. Tente novamente.\n");
    }
}
while (opcao != 0);
printf("Saindo do programa\n");
return 0;
}
