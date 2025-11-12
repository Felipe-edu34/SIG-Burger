#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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