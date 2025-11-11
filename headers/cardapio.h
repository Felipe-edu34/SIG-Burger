#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct {
    int codigo;
    char nome[50];
    char categoria[20];
    char descricao[100];
    float preco;
    int disponivel;
} Itemcardapio;

void tela_menu_principal();
void cardapio();

#endif // CARDAPIO_H