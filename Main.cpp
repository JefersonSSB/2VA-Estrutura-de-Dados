#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include "Util.cpp"
#include "Cardapio.cpp"
#include "Livro.cpp"
#include "Cliente.cpp"



ListaCardapio* TesteCardapio(ListaCardapio* l){
	ListaCardapio* cardapio = inicializaCarpadio();
	Cardapio iten1, iten2, iten3 ;
	
	iten1.id= 1;
	strcpy(iten1.descricao,"Salgado");
	iten1.preco = 3.50;
	
	iten2.id= 2;
	strcpy(iten2.descricao,"Suco");
	iten2.preco = 1.50;
	
	iten3.id= 3;
	strcpy(iten3.descricao,"Cafe");
	iten3.preco = 1.00;
	
	l = insereCardapio(l,iten1);
	l = insereCardapio(l,iten2);
	l = insereCardapio(l,iten3);
	return l;
		
}


PilhaLivros TesteLivro(PilhaLivros l){

	l = empilharLivro(l,"Livro 1");
	l = empilharLivro(l,"Livro 2");
	l = empilharLivro(l,"Livro 3");
	l = empilharLivro(l,"Livro 4");
	l = empilharLivro(l,"Livro 5");
	
	return l;		
}



int main(){
	
	int opcao;
	ListaCardapio* cardapio = inicializaCarpadio();
	FilaCliente* cliente = inicializaCliente();
	PilhaLivros livro = inicializaLivro();
	
	
//Prenchimento para teste
	
	cardapio = TesteCardapio(cardapio);
	livro = TesteLivro(livro);
	
//Prenchimento para teste
	while(1){
	
limparTela();

	printf("****************************************\n");
	printf("***       Lanchonete Uegeniana       ***\n");
	printf("****************************************\n");
	
	printf("* [1] - VER CARDAPIO       	       *\n");
	printf("* [2] - PREENCHER  COMANDA             *\n");
	printf("* [3] - LISTAR COMANDAS      	       *\n");
	printf("* [4] - FINALIZAR PEDIDO       	       *\n");
	
	printf("****************************************\n");
	printf("****************************************\n");
	
	printf("* [5] - INSERIR ITENS NO CARDAPIO      *\n");
	printf("* [6] - INSERIR LIVRO       	       *\n");
	printf("* [7] - LISTAR LIVROS	     	       *\n");
	printf("****************************************\n");
	printf("* [0] - SAIR		               *\n");
	printf("****************************************\n");
  
  printf ("Digite uma das Opcoes: ");
  scanf("%d", &opcao);
  limparBuffer();

	switch (opcao)
	{
	
	case 1:
		listarCardapio(cardapio);
   		system("pause");
   	break;

   	case 2:
   	cliente = preechePedido(cliente,cardapio,&livro);
   	break;
   	
   	case 3:
   		listarClientes(cliente);
   		system("pause");
   	break;
   	
   	case 4:
  		cliente = desinfileraCliente(cliente);
  		system("pause");
   	break;
   	
   	case 5:
   		cardapio = preecheCardapio(cardapio);
   	break;
   	
   	case 6:
   		livro = preecheLivro(livro);
   	break;
   	
   	case 7:
   		listarLivros(livro);
   		system("pause");
   	break;

   default:
   		exit(1);
	}
}
return 0;
}

