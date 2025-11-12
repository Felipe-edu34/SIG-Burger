#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "cliente.h"

#define ARQUIVO_CLIENTES "dados/clientes.dat"

void menu_clientes(void) {
    limpar_tela();
    printf("\n");
    printf("        ╔══════════════════════════════════════════════════╗\n");
    printf("        ║         SIG-BURGER - GESTÃO DE CLIENTES          ║\n");
    printf("        ╠══════════════════════════════════════════════════╣\n");
    printf("        ║                                                  ║\n");
    printf("        ║ ► 1. Cadastrar Cliente                           ║\n");
    printf("        ║ ► 2. Listar Clientes                             ║\n");
    printf("        ║ ► 3. Editar Cliente                              ║\n");
    printf("        ║ ► 4. Excluir Cliente                             ║\n");
    printf("        ║ ► 0. Voltar ao Menu Principal                    ║\n");
    printf("        ║                                                  ║\n");
    printf("        ╚══════════════════════════════════════════════════╝\n");
    printf("\n        Escolha uma opção: ");
}

void cadastrar_cliente(void) {
    Cliente cli;
    FILE* fp;
    
    limpar_tela();
    printf("\n");
    printf("        ╔══════════════════════════════════════════════════╗\n");
    printf("        ║            CADASTRAR NOVO CLIENTE                ║\n");
    printf("        ╚══════════════════════════════════════════════════╝\n\n");
    
    printf("        Nome completo: ");
    ler_string(cli.nome, sizeof(cli.nome));
    
    printf("        Telefone: ");
    ler_string(cli.telefone, sizeof(cli.telefone));
    
    printf("        Endereço completo: ");
    ler_string(cli.endereco, sizeof(cli.endereco));
    
    cli.status = 1;
    
    fp = fopen(ARQUIVO_CLIENTES, "ab");
    if (fp == NULL) {
        printf("\n Erro ao abrir arquivo!\n");
        pausar();
        return;
    }
    
    fwrite(&cli, sizeof(Cliente), 1, fp);
    fclose(fp);
    
    printf("\n Cliente cadastrado com sucesso!\n");
    pausar();
}

void cliente(void) {
    int opcao;
    
    do {
        menu_clientes();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                // cadastrar_cliente();
                break;
            case 2:
                // listar_clientes();
                break;
            case 3:
                // editar_cliente();
                break;
            case 4:
                // excluir_cliente();
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n");
                pausar();
                break;
            default:
                printf("\n Opção inválida! Tente novamente.\n");
                pausar();
        }
    } while(opcao != 0);
}

