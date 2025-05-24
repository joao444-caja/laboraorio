 void cadastrar_produto() {
        char produto;
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[total_produtos]);
        printf("Produto %s cadastrado com sucesso!\n", produtos[total_produtos]);
        total_produtos++;
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