#include <stdio.h>
#include <stdlib.h>

struct Produto {
  int codigo;
  char nome[50];
  int quantidade;
  float preco;
};

struct ControleEstoque {
  struct Produto *produtos;
  int capacidade;
  int numProdutos;
};

void inicializar_sistema(struct ControleEstoque *controleEstoque,
                         int capacidadeInicial) {
  controleEstoque->produtos =
      malloc(capacidadeInicial * sizeof(struct Produto));
  controleEstoque->capacidade = capacidadeInicial;
  controleEstoque->numProdutos = 0;
}

void adicionar_produto(struct ControleEstoque *controleEstoque) {
  if (controleEstoque->numProdutos < controleEstoque->capacidade) {
    struct Produto novoProduto;

    printf("Informe o código do produto: ");
    scanf("%d", &novoProduto.codigo);

    printf("Informe a descrição do produto: ");
    scanf("%s", novoProduto.nome);

    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Informe o valor do produto: ");
    scanf("%f", &novoProduto.preco);

    controleEstoque->produtos[controleEstoque->numProdutos++] = novoProduto;

    printf("Produto adicionado com sucesso!\n");
  } else {
    printf("Capacidade máxima atingida. Não é possível adicionar mais "
           "produtos.\n");
  }
}

void imprimir_relatorio(struct ControleEstoque *controleEstoque) {
  printf("Relatório de Produtos no Estoque:\n");
  for (int i = 0; i < controleEstoque->numProdutos; i++) {
    printf("Código: %d, Descrição: %s, Quantidade: %d, Valor: R$%.2f\n",
           controleEstoque->produtos[i].codigo,
           controleEstoque->produtos[i].nome,
           controleEstoque->produtos[i].quantidade,
           controleEstoque->produtos[i].preco);
  }
}

void imprimir_relatorio_completo(struct ControleEstoque *controleEstoque) {
  printf("Relatório Completo de Produtos no Estoque:\n");
  printf("%-10s %-20s %-10s %-10s\n", "Código", "Descrição", "Quantidade",
         "Valor");

  for (int i = 0; i < controleEstoque->numProdutos; i++) {
    printf("%-10d %-20s %-10d %-10.2f\n", controleEstoque->produtos[i].codigo,
           controleEstoque->produtos[i].nome,
           controleEstoque->produtos[i].quantidade,
           controleEstoque->produtos[i].preco);
  }
}

void pesquisar_produto(struct ControleEstoque *controleEstoque) {
  int codigoPesquisa;
  printf("Informe o código do produto a ser pesquisado: ");
  scanf("%d", &codigoPesquisa);

  for (int i = 0; i < controleEstoque->numProdutos; i++) {
    if (controleEstoque->produtos[i].codigo == codigoPesquisa) {
      printf("Produto encontrado:\n");
      printf("Código: %d\n", controleEstoque->produtos[i].codigo);
      printf("Descrição: %s\n", controleEstoque->produtos[i].nome);
      printf("Quantidade: %d\n", controleEstoque->produtos[i].quantidade);
      printf("Valor: R$%.2f\n", controleEstoque->produtos[i].preco);
      return;
    }
  }

  printf("Produto com código %d não encontrado.\n", codigoPesquisa);
}

void pesquisar_produto_pelo_codigo(struct ControleEstoque *controleEstoque) {
  int codigoPesquisa;
  printf("Informe o código do produto a ser pesquisado: ");
  scanf("%d", &codigoPesquisa);

  for (int i = 0; i < controleEstoque->numProdutos; i++) {
    if (controleEstoque->produtos[i].codigo == codigoPesquisa) {
      printf("Produto encontrado:\n");
      printf("Código: %d\n", controleEstoque->produtos[i].codigo);
      printf("Descrição: %s\n", controleEstoque->produtos[i].nome);
      printf("Quantidade: %d\n", controleEstoque->produtos[i].quantidade);
      printf("Valor: R$%.2f\n", controleEstoque->produtos[i].preco);
      return;
    }
  }

  printf("Produto com código %d não encontrado.\n", codigoPesquisa);
}

void remover_produto(struct ControleEstoque *controleEstoque) {
  int codigoRemocao;
  printf("Informe o código do produto a ser removido: ");
  scanf("%d", &codigoRemocao);

  for (int i = 0; i < controleEstoque->numProdutos; i++) {
    if (controleEstoque->produtos[i].codigo == codigoRemocao) {
      for (int j = i; j < controleEstoque->numProdutos - 1; j++) {
        controleEstoque->produtos[j] = controleEstoque->produtos[j + 1];
      }
      controleEstoque->numProdutos--;

      printf("Produto removido com sucesso!\n");
      return;
    }
  }

  printf("Produto com código %d não encontrado. Não foi possível remover.\n",
         codigoRemocao);
}

int main() {
  struct ControleEstoque controleEstoque;
  inicializar_sistema(&controleEstoque, 10);

  int opcao;

  do {
    printf("\n*** Menu ***\n");
    printf("1. Adicionar Produto\n");
    printf("2. Imprimir Relatório\n");
    printf("3. Imprimir Relatório Completo\n");
    printf("4. Pesquisar Produto\n");
    printf("5. Pesquisar Produto pelo Código\n");
    printf("6. Remover Produto\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      adicionar_produto(&controleEstoque);
      break;
    case 2:
      imprimir_relatorio(&controleEstoque);
      break;
    case 3:
      imprimir_relatorio_completo(&controleEstoque);
      break;
    case 4:
      pesquisar_produto(&controleEstoque);
      break;
    case 5:
      pesquisar_produto_pelo_codigo(&controleEstoque);
      break;
    case 6:
      remover_produto(&controleEstoque);
      break;
    case 7:
      printf("Saindo do programa. Obrigado!\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 7);

  free(controleEstoque.produtos);

  return 0;
}
