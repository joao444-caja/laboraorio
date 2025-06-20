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
    int total_vendas;
    int total_itens;
} Venda;

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Venda vendas[MAX_VENDAS];

int total_clientes = 0;
int total_produtos = 0;
int total_vendas = 0;

       void cadastrar_venda() {
        Venda v;
        v.id_venda = total_vendas + 1;
        printf("Digite o ID do cliente: ");
        scanf("%d", &v.id_cliente);
        v.total_itens = 0;
        v.total_vendas = 0.0;

        char continuar = 's';
        while(continuar == 's' && v.total_itens < MAX_VENDAS) {
            ItemVenda item;
            printf("Digite o ID do produto: ");
            scanf("%d", &item.id_produto);
            printf("Digite a quantidade: ");
            scanf("%d", &item.quantidade);

            Produto p = produtos[item.id_produto - 1];
            item.valor_unitario = p.preco;
            v.itens[v.total_itens] = item;
            v.total_vendas += item.valor_unitario * item.quantidade;

            v.total_itens++;

            printf("Deseja adicionar mais um item? (s/n): ");
            scanf(" %c", &continuar);
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

int main() {
  int opcao;
    do {
        printf("\nMENU\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Cadastrar Venda\n");
        printf("4. Listar Clientes\n");
        printf("5. Listar Produtos\n");
        printf("6. Excluir Cliente\n");
        printf("7. Excluir Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar_cliente(); break;
            case 2: cadastrar_produto(); break;
            case 3: cadastrar_venda(); break;
            case 4: listar_clientes(); break;
            case 5: listar_produtos(); break;
            case 6: excluir_cliente(); break;
            case 7: excluir_produto(); break;
            case 0: printf("Saindo do programa.\n"); break;
            default: printf("Opcao invalida.\n"); break;
        }
    } while (opcao != 0);
    
    return 0;
    }
