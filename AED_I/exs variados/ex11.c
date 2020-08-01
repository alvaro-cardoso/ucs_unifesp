void TArvore_Imprime(TArvore Arvore, int i){
TArvore filho;
TLista *filhos;

filhos = TLista TArvore_ListaDescendentes(Arvore);

printf("( %c ", Arvore->Dados.Chave);
while(!TLista_Ehvazia(filhos)){
	TLista_RetiraPrimeiro(filhos,&filho);
	TArvore_Imprime(filho,i);
	}
printf(")");,

}