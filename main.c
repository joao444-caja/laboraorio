    #include <stdio.h>
    #include <string.h>

    #define MAX_CLIENTES 100
    #define MAX_PRODUTOS 100
    #define MAX_VENDAS 100

    typedef struct {
        int id;
        char nome[50];
        char cpf[15];
    } Cliente;

    typedef struct {
        int id;
        char nome[50];
        float preco;
        int estoque;
    } Produto;

    typedef struct {
        int id_produto;
        int quantidade;
        float valor_unitario;
    } ItemVenda;

    typedef struct { 
        int id_venda;
        int id_cliente;
        ItemVenda itens[MAX_VENDAS];
        float total_vendas;
        int total_itens;
    } Venda;

    Cliente clientes[MAX_CLIENTES];
    Produto produtos[MAX_PRODUTOS];
    Venda vendas[MAX_VENDAS];

    int total_clientes = 0;
    int total_produtos = 0;
    int total_vendas = 0;

    Cliente* buscar_cliente(int id) { 
    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].id == id) {
            return &clientes[i];
        }
    }
    return NULL; 
    }
    
    Produto* buscar_produto(int id) {
        for (int i = 0; i < total_produtos; i++) {
            if (produtos[i].id == id) {
                return &produtos[i];
            }
        }
        return NULL;
    }
        void cadastrar_venda() {
            if (total_vendas >= MAX_VENDAS) {
                printf("Limite de vendas atingido.\n");
                return;
            } 

            Venda v_nova; 
            v_nova.id_venda = total_vendas + 1;
            printf("Digite o ID do cliente: ");
            scanf("%d", &v_nova.id_cliente);

             Cliente* cliente_encontrado = buscar_cliente(v_nova.id_cliente); 
    if (cliente_encontrado == NULL) {   
        printf("Cliente com ID %d não encontrado. Venda cancelada.\n", v_nova.id_cliente); 
        return; 
    }

            v_nova.total_itens = 0;
            v_nova.total_vendas = 0.0;

            char continuar = 's';
            while (continuar == 's' && v_nova.total_itens < MAX_VENDAS) {
                ItemVenda item;
                printf("Digite o ID do produto: ");
                scanf("%d", &item.id_produto);

                Produto* produto_encontrado = buscar_produto(item.id_produto);
                if (produto_encontrado == NULL) {
                    printf("Produto com ID %d não encontrado.\n", item.id_produto);
                    continue;
                }

                printf("Digite a quantidade: ");
                scanf("%d", &item.quantidade);

                if (item.quantidade > produto_encontrado->estoque) {
                    printf("Quantidade solicitada maior que o estoque disponível.\n");
                    continue;
                }

                item.valor_unitario = produto_encontrado->preco;
                v_nova.itens[v_nova.total_itens++] = item;

                v_nova.total_vendas += item.quantidade * item.valor_unitario;
                produto_encontrado->estoque -= item.quantidade; // atualiza o estoque

                printf("Deseja adicionar mais um item? (s/n): ");
                scanf(" %c", &continuar);
            }
            {
                vendas[total_vendas++] = v_nova; // adiciona a venda ao array de vendas
                printf("Venda cadastrada com sucesso! ID da venda: %d, Total: %.2f\n", v_nova.id_venda, v_nova.total_vendas);
            }
            
        }
        void cadastrar_produto() {
            Produto p;
            p.id = total_produtos + 1;
            printf("Digite o nome do produto: ");
            scanf("%s", p.nome);
            printf("Digite o preço unitario: ");
            scanf("%f", &p.preco);
            printf("Digite a quantidade em estoque: ");
            scanf("%d", &p.estoque);
            produtos[total_produtos++] = p;
            printf("Produto %s cadastrado com sucesso!\n", p.nome);
        }
    void listar_produtos() {
        for (int i = 0; i < total_clientes; i++) {
                printf("id: %d, Nome: %s, Preço: %.2f, Estoque: %d\n", 
                    produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                }
        }
        void listar_clientes() {
            for (int i = 0; i < total_clientes; i++) {
                printf("ID: %d, Nome: %s, CPF: %s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
            }
        }

    void cadastrar_cliente() {
            Cliente c;
            c.id = total_clientes + 1;
            printf("Digite o nome do cliente: ");
            scanf("%s", c.nome);
            printf("Digite o CPF do cliente: ");
            scanf("%s", c.cpf);
            clientes[total_clientes++] = c;
            printf("Cliente %s cadastrado com sucesso!\n", c.nome);
        }

    void listar_venda() { 
        if (total_vendas == 0) {
        printf("Nenhuma venda cadastrada.\n");
        return;
    }
    printf("\n--- Lista de Vendas ---\n");
    for (int i = 0; i < total_vendas; i++) {
        Venda v = vendas[i];
        printf("Venda ID: %d, Cliente ID: %d, Total: %.2f\n", v.id_venda, v.id_cliente, v.total_vendas);
        Cliente* cliente_ptr = buscar_cliente(v.id_cliente);
        if (cliente_ptr != NULL) {
            printf("  Cliente: %s (CPF: %s)\n", cliente_ptr->nome, cliente_ptr->cpf);
        } else {
            printf("  Cliente: (ID %d - Não encontrado)\n", v.id_cliente);
        }

        printf("  Itens da Venda (%d):\n", v.total_itens);
        for (int j = 0; j < v.total_itens; j++) {
            ItemVenda item = v.itens[j];
            Produto* produto_ptr = buscar_produto(item.id_produto);
            if (produto_ptr != NULL) {
                printf("    - Produto: %s (ID: %d), Quantidade: %d, Valor Unitário: %.2f, Subtotal: %.2f\n",
                       produto_ptr->nome, item.id_produto, item.quantidade, item.valor_unitario,
                       item.quantidade * item.valor_unitario);
            } else {
                printf("    - Produto ID: %d (Não encontrado), Quantidade: %d, Valor Unitário: %.2f\n",
                       item.id_produto, item.quantidade, item.valor_unitario);
            }
        }
    }
    }

    void excluir_cliente() {
        printf("Digite o ID do cliente a ser excluído: ");
        int id;
        scanf("%d", &id);
        for (int i = 0; i < total_clientes; i++) {
            if (clientes[i].id == id) {
                for (int j = i; j < total_clientes - 1; j++) {
                    clientes[j] = clientes[j + 1];
                }
                total_clientes--;
                printf("Cliente com ID %d excluído com sucesso.\n", id);
                return;
            }
        }
        printf("Cliente com ID %d não encontrado.\n", id);
    }

    void excluir_produto() {
        printf("Digite o ID do produto a ser excluído: ");
        int id;
        scanf("%d", &id);
        for (int i = 0; i < total_produtos; i++) {
            if (produtos[i].id == id) {
                for (int j = i; j < total_produtos - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                total_produtos--;
                printf("Produto com ID %d excluído com sucesso.\n", id);
                return;
            }
        }
        printf("Produto com ID %d não encontrado.\n", id);
    }

    void excluir_venda() {
        printf("Digite o ID da venda a ser excluída: ");
        int id;
        scanf("%d", &id);
        for (int i = 0; i < total_vendas; i++) {
            if (vendas[i].id_venda == id) {
                for (int j = i; j < total_vendas - 1; j++) {
                    vendas[j] = vendas[j + 1];
                }
                total_vendas--;
                printf("Venda com ID %d excluída com sucesso.\n", id);
                return;
            }
        }
        printf("Venda com ID %d não encontrada.\n", id);
    }

    int main() {
    int opcao;
        do {
            printf("\n\033[1;32m---   ---  MENU  ---  ---\033[0m\n");
            printf("\033[1;32m--1. Cadastrar Cliente\033[0m\n");
            printf("\033[1;32m--2. Cadastrar Produto\033[0m\n");
            printf("\033[1;32m--3. Cadastrar Venda\033[0m\n");
            printf("\033[1;32m--4. Listar Vendas\033[0m\n");
            printf("\033[1;32m--5. Listar Clientes\033[0m\n");
            printf("\033[1;32m--6. Listar Produtos\033[0m\n");
            printf("\033[1;32m--7. Excluir venda\033[0m\n");
            printf("\033[1;32m--8. Excluir cliente\033[0m\n");
            printf("\033[1;32m--9. Excluir produto\033[0m\n");
            printf("\033[1;31m--0. Sair\033[0m\n");
            printf("\033[38;5;208m--Escolha uma opcao: \033[0m");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: cadastrar_cliente(); break;
                case 2: cadastrar_produto(); break;
                case 3: cadastrar_venda(); break;
                case 4: listar_venda(); break;
                case 5: listar_clientes(); break;
                case 6: listar_produtos(); break;
                case 7: excluir_venda(); break;
                case 8: excluir_cliente(); break;
                case 9: excluir_produto(); break;
                case 0: printf("\033[38;5;208mSaindo do programa.\033[0m\n"); break;
                default: printf("Opcao invalida.\n"); break;
            }
        } while (opcao != 0);
        
        return 0;
        }
