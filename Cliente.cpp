typedef struct Comanda
{
	Cardapio itensCardapio;
	int quantidade;
	struct Comanda *prox;
};

typedef struct Cliente
{
	char nome[30];
	char livro[30];
	Comanda *comanda;
	float valorTotal;
};

typedef struct FilaCliente
{
	Cliente pedido;
	struct FilaCliente *prox;
};

Comanda *inicializaComanda()
{
	return NULL;
}

FilaCliente *inicializaCliente()
{
	return NULL;
}

float calcularPrecoComanda(Comanda *c)
{

	Comanda *p;
	float valor = 0;

	for (p = c; p != NULL; p = p->prox)
	{

		valor += p->itensCardapio.preco * p->quantidade;
	}
	return valor;
}

Comanda *insereComanda(Comanda *l, Cardapio cardapio, int quantidade)
{
	Comanda *novoElemento = (Comanda *)malloc(sizeof(Comanda));
	novoElemento->itensCardapio = cardapio;
	novoElemento->quantidade = quantidade;
	novoElemento->prox = l;
	return novoElemento;
}

FilaCliente *enfileraCliente(FilaCliente *l, Cliente pedido)
{

	if (l == NULL)
	{
		FilaCliente *novoElemento = (FilaCliente *)malloc(sizeof(FilaCliente));
		novoElemento->pedido = pedido;
		novoElemento->prox = NULL;
		return novoElemento;
	}
	else
	{
		l->prox = enfileraCliente(l->prox, pedido);
		return l;
	}
}

void listarItens(Comanda *l)
{
	Comanda *p;

	printf("****************************************\n");
	printf("***           Lista Itens         ***\n");
	printf("****************************************\n");

	if (l == NULL)
	{
		printf("\n******      Lista Vazia     ******\n");
	}
	else
	{

		for (p = l; p != NULL; p = p->prox)
		{
			printf("\nDescricao: %s", p->itensCardapio.descricao);
			printf("\nPreco: %f", p->itensCardapio.preco);
			printf("\nQuantidade: %d", p->quantidade);

			printf("\n****************************************\n");
		}
	}
}

void listarClientes(FilaCliente *l)
{

	FilaCliente *p;
	limparTela();
	printf("****************************************\n");
	printf("*** Lista de Pedidos de Clientes     ***\n");
	printf("****************************************\n");

	if (l == NULL)
	{
		printf("\n******      Lista Vazia     ******\n");
	}
	else
	{

		for (p = l; p != NULL; p = p->prox)
		{

			printf("****************************************\n");
			printf("***              Cliente              ***\n");
			printf("****************************************\n");

			printf("\nNome: %s", p->pedido.nome);
			printf("\nLivro: %s", p->pedido.livro);
			printf("\nValor a Pagar: %f\n", p->pedido.valorTotal);
			listarItens(p->pedido.comanda);
		}
	}
}

FilaCliente *desinfileraCliente(FilaCliente *fi)
{

	if (fi == NULL)
	{
		printf("\n******      Lista Vazia     ******\n");
		return NULL;
	}
	limparTela();
	printf("****************************************\n");
	printf("***              Cliente              ***\n");
	printf("****************************************\n");

	printf("\nNome: %s", fi->pedido.nome);
	printf("\nLivro: %s", fi->pedido.livro);
	printf("\nValor a Pagar: %f\n", fi->pedido.valorTotal);
	listarItens(fi->pedido.comanda);

	printf("\nPedido Finalizado\n");
	FilaCliente *temp = fi;
	fi = fi->prox;
	free(temp);

	return fi;
}

Comanda *preecherComanda(ListaCardapio *cardapio)
{
	limparTela();
	int i = 1, id, quantidade = 0;
	Cardapio itenCardapio;
	Comanda *c = inicializaComanda();
	while (i == 1)
	{

		listarCardapio(cardapio);

		printf("Escolha o Item Digitando o ID: ");

		scanf("%d", &id);
		itenCardapio = buscaCardapio(id, cardapio);
		limparTela();
		imprimirCardapio(itenCardapio);
		printf("Informe a Quantidade: ");
		scanf("%d", &quantidade);

		c = insereComanda(c, itenCardapio, quantidade);
		printf("\n* [1] - PEDIR MAIS ITENS    *\n");
		printf("* [0] - FINALIZAR PEDIDO      *\n");
		scanf("%d", &i);
	}
	return c;
}

FilaCliente *preechePedido(FilaCliente *c, ListaCardapio *cardapio, PilhaLivros *l)
{

	Cliente novoCliente;
	limparTela();
	printf("****************************************\n");
	printf("***          Inserir Pedido           ***\n");
	printf("****************************************\n");
	printf("**     Entre com os dados do Cliente    **\n");

	limparBuffer();
	printf("\nNome do Cliente: ");
	scanf("%[^\n]", &novoCliente.nome);
	limparBuffer();
	novoCliente.comanda = preecherComanda(cardapio);
	printf("\nValor Total da Comanda: %f \n", calcularPrecoComanda(novoCliente.comanda));

	novoCliente.valorTotal = calcularPrecoComanda(novoCliente.comanda);

	strcpy(novoCliente.livro, desempilharLivro(l));
	system("pause");
	return enfileraCliente(c, novoCliente);
}
