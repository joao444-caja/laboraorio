    #include <stdio.h>


    char clientes[10][50];
    char produtos[10][50];
    int total_clientes = 0;
    int total_produtos = 0;


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