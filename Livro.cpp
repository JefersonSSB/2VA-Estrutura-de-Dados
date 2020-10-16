
typedef struct PilhaLivros{
   	char livro[30][30]; 
	int fim;
};


PilhaLivros inicializaLivro() {
	PilhaLivros l;
   l.fim = 0;
   return l;
}

PilhaLivros empilharLivro(PilhaLivros l, char nome[]) {
		
	strcpy(l.livro[l.fim++],nome);

return l;
}


PilhaLivros preecheLivro(PilhaLivros l){
	
	limparTela();
	char nome[30];
	printf("****************************************\n");
	printf("***          Inserir Livro           ***\n");
	printf("****************************************\n");
	printf("**     Entre com os dados do Livro    **\n");
	limparBuffer();
	printf("Nome: ");
	scanf("%[^\n]",&nome);
	limparBuffer();
	return  empilharLivro(l,nome); 	
}





void listarLivros(PilhaLivros l)
{
	int i;

	limparTela();
 	printf("****************************************\n");
	printf("***           Lista Livros         ***\n");
	printf("****************************************\n");
	
	if (l.fim == 0){
		printf("\n******      Lista Vazia     ******\n");
	}
	else{
	
 	for (i=0; i< l.fim;i++){
 	printf("\nNome: %s\n",l.livro[i]);
	}
	 
   
}
}

char*  desempilharLivro(PilhaLivros *l) {
	
	l->fim --;
   	return l->livro[l->fim];  
}

