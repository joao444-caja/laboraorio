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