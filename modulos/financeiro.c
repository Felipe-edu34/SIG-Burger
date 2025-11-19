#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "financeiro.h"

#define ARQUIVO_FINANCEIRO "dados/financeiro.dat"

void menu_financeiro() {
    limpar_tela();
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║               MÓDULO FINANCEIRO                  ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║                                                  ║\n");
    printf("║ ► 1. Registrar Transação                         ║\n");
    printf("║ ► 2. Listar Transações                           ║\n");
    printf("║ ► 3. Editar Transação                            ║\n");
    printf("║ ► 4. Excluir Transação                           ║\n");
    printf("║ ► 5. Relatório Financeiro                        ║\n");
    printf("║ ► 0. Voltar ao Menu Principal                    ║\n");
    printf("║                                                  ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}