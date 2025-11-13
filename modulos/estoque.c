#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "estoque.h"

#define ARQUIVO_ESTOQUE "estoque.dat"

void menu_estoque(){
    limpar_tela();
        printf("╔══════════════════════════════════════════════════╗\n");
        printf("║               MÓDULO DE ESTOQUE                  ║\n");
        printf("╠══════════════════════════════════════════════════╣\n");
        printf("║                                                  ║\n");
        printf("║ ► 1. Cadastrar Produto                           ║\n");
        printf("║ ► 2. Editar Produto                              ║\n");
        printf("║ ► 3. Pesquisar Produto                           ║\n");
        printf("║ ► 4. Excluir Produto                             ║\n");
        printf("║                                                  ║\n");
        printf("║ ► 0. Voltar ao Menu Principal                    ║\n");
        printf("║                                                  ║\n");
        printf("╚══════════════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
}



int confirma_dados_estoque(Produto* prod) {
    char confirm;
    limpar_tela();
    exibir_item(prod);
    printf("Os dados do item novo do estoque estão corretos? (S/N): ");
    scanf(" %c", &confirm);
    limparBuffer();

    if (confirm == 'S' || confirm == 's') {
        return 1;
    } else {
        return 0;
    }
}



void exibir_item_estoque(Produto* prod){

    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║             ITEM CADASTRADO (VISUALIZAÇÃO)       ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║ Nome:        %s\n", prod->nome);
    printf("║ Categoria:   %s\n", prod->categoria);
    printf("║ quantidade:   %i\n", prod->quantidade);
    printf("║ validade:       %s\n", prod->validade);
    printf("╚══════════════════════════════════════════════════╝\n");
}



void gravar_item_estoque(Produto* prod){


    FILE *arq_item = fopen(ARQUIVO_ESTOQUE, "ab");              // Abre o arquivo em modo anexar (append)
    if (arq_item == NULL) {
        return;
    }

    fwrite(prod, sizeof(Produto), 1, arq_item);
    fclose(arq_item);
}


void cadastrar_item(){

    Produto* prod;
    limpar_tela();
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║           CADASTRAR PRODUTO AO ESTOQUE           ║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n");

    printf("► Nome do Produto: ");
    ler_string(prod->nome, sizeof(prod->nome));

    printf("► Categoria: ");
    ler_string(prod->categoria, sizeof(prod->categoria));

    printf("► Quantidade inicial: ");
    if (scanf("%d", &prod->quantidade) != 1 || prod->quantidade < 0) {
        limparBuffer();
        printf("\nQuantidade inválida.\n");
        pausar();
        return;
    }
    limparBuffer();

    printf("► Validade (dd/mm/aaaa): ");
    ler_string(prod->validade, sizeof(prod->validade));

    prod->ativo = 1;

    if (!confirma_dados_produto(prod)) {
        printf("\nCadastro cancelado pelo usuário.\n");
        pausar();
        return;
    }

    gravar_produto(prod);
    printf("\n Produto cadastrado com sucesso!\n");
    pausar();
}

