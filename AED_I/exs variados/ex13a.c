void TPilha_ChecaPilha(TPilha *pPilha){
TPilha *pilhaaux;
TItem item,item2;
int i,x;

pilhaaux = (TPilha *) malloc(sizeof(TPilha));
TPilha_Inicia(pilhaaux);

item.Chave='z';

while((! TPilha_EhVazia(pPilha))&&(item.Chave!='C')){
            TPilha_Desempilha(&pPilha,&item);
	    if (item.Chave!='C')
            TPilha_Empilha(&pilhaaux,item2);}

for (i=0;i<TPilha_Tamanho(pPilha);i++){
        TPilha_Desempilha(pPilha,&item);
        TPilha_Desempilha(pilhaaux,&item2);
    if (TPilha_Tamanho(pPilha)==TPilha_Tamanho(pilhaaux) && (strcmp(item.Chave[i],item2.Chave[i]))!=0){
            x=0;}
            else{ x=1;
            Break;}}

        if (x<1)printf("a cadeia eh da forma xCy\n");
        else printf ("a cadeia nao eh da forma xCy\n");
        free(pilhaaux);
        return 0;}
