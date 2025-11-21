#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "pedido.h"
#include "cardapio.h"

#define ARQUIVO_PEDIDOS "dados/pedidos.dat"

void menu_pedidos() {
    limpar_tela();
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║                 MÓDULO PEDIDOS                   ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║                                                  ║\n");
    printf("║ ► 1. Cadastrar Pedido                            ║\n");
    printf("║ ► 2. Listar Pedidos                              ║\n");
    printf("║ ► 3. Editar Pedido                               ║\n");
    printf("║ ► 4. Pesquisar Pedido                            ║\n");
    printf("║ ► 5. Excluir Pedido                              ║\n");
    printf("║ ► 0. Voltar ao Menu Principal                    ║\n");
    printf("║                                                  ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}

int gerar_numero_pedido() {
    FILE *arq;
    Pedido ped;
    int maior_numero = 0;

    arq = fopen(ARQUIVO_PEDIDOS, "rb");
    if (arq == NULL) {
        return 1;
    }

    while (fread(&ped, sizeof(Pedido), 1, arq) == 1) {
        if (ped.numero_pedido > maior_numero) {
            maior_numero = ped.numero_pedido;
        }
    }
    fclose(arq);

    return maior_numero + 1;
}

int confirma_dados_pedido(Pedido* ped) {
    char confirm;
    limpar_tela();
    exibir_pedido(ped);
    printf("\nOs dados do pedido estão corretos? (S/N): ");
    scanf(" %c", &confirm);
    limparBuffer();

    if (confirm == 'S' || confirm == 's') {
        return 1;
    } else {
        return 0;
    }
}

void exibir_pedido(Pedido* ped) {
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║              DETALHES DO PEDIDO                  ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║ Número:      #%d\n", ped->numero_pedido);
    printf("║ Cliente:     %s\n", ped->nome_cliente);
    printf("║ Telefone:    %s\n", ped->telefone_cliente);
    
    if (ped->eh_delivery) {
        printf("║ Tipo:        DELIVERY\n");
        printf("║ Endereço:    %s\n", ped->endereco_entrega);
    } else {
        printf("║ Tipo:        CONSUMO NO LOCAL\n");
    }
    
    printf("║ Data:        %s\n", ped->data);
    printf("║ Status:      %s\n", ped->status);
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║ ITENS DO PEDIDO:\n");
    printf("║\n");
    
    for (int i = 0; i < ped->total_itens; i++) {
        printf("║ • %dx %s\n", 
               ped->itens[i].quantidade, 
               ped->itens[i].item.nome);
        printf("║   R$ %.2f x %d = R$ %.2f\n", 
               ped->itens[i].item.preco,
               ped->itens[i].quantidade,
               ped->itens[i].item.preco * ped->itens[i].quantidade);
        printf("║\n");
    }
    
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║ Subtotal:         R$ %.2f\n", ped->valor_total - ped->taxa_entrega);
    
    if (ped->eh_delivery) {
        printf("║ Taxa de Entrega:  R$ %.2f\n", ped->taxa_entrega);
    }
    
    printf("║ Valor Total:      R$ %.2f\n", ped->valor_total);
    printf("╚══════════════════════════════════════════════════╝\n");
}
