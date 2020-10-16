#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cardapio
{
	int id;
	char descricao[30];
	float preco;
};

typedef struct ListaCardapio
{
	Cardapio cardapio;
	int quantidade;
	struct ListaCardapio *prox;
};

ListaCardapio *inicializaCarpadio()
{
	return NULL;
}

ListaCardapio *insereCardapio(ListaCardapio *l, Cardapio cardapio)
{
	ListaCardapio *novoElemento = (ListaCardapio *)malloc(sizeof(ListaCardapio));
	novoElemento->cardapio = cardapio;
	novoElemento->prox = l;

	return novoElemento;
}

ListaCardapio *preecheCardapio(ListaCardapio *l)
{

	Cardapio novoCardapio;
	limparTela();
	printf("****************************************\n");
	printf("***          Inserir Cardapio           ***\n");
	printf("****************************************\n");
	printf("**     Entre com os dados do Cardapio    **\n");

	printf("ID: ");
	scanf("%d", &novoCardapio.id);
	limparBuffer();
	printf("\nDescricao: ");
	scanf("%[^\n]", &novoCardapio.descricao);
	limparBuffer();
	printf("\nPreco: ");
	scanf("%f", &novoCardapio.preco);
	limparBuffer();

	return insereCardapio(l, novoCardapio);
	;
}

Cardapio buscaCardapio(int id, ListaCardapio *l)
{
	ListaCardapio *p;
	p = l;
	while (p != NULL && p->cardapio.id != id)
	{
		p = p->prox;
	}
	return p->cardapio;
}

void imprimirCardapio(Cardapio cardapio)
{

	printf("**********    Dados do Cardapio   *******\n");
	printf("ID: %d", cardapio.id);
	printf("\nDescricao: %s", cardapio.descricao);
	printf("\nPreco: %f", cardapio.preco);
	printf("\n****************************************\n");
}

void listarCardapio(ListaCardapio *l)
{
	ListaCardapio *p;

	limparTela();
	printf("****************************************\n");
	printf("***           Lista Cardapio         ***\n");
	printf("****************************************\n");

	if (l == NULL)
	{
		printf("\n******      Lista Vazia     ******\n");
	}
	else
	{

		for (p = l; p != NULL; p = p->prox)
		{
			imprimirCardapio(p->cardapio);
		}
	}
}
