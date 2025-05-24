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

evoid cadastrar_cliente() {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[total_clientes]);
        printf("Cliente %s cadastrado com sucesso!\n", clientes[total_clientes]);
        total_clientes++;
    }