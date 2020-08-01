int Ciclo(TGrafo *pGrafo, TVertice v){

    if(pGrafo->Adj[v].Tamanho == 0){
        printf("\n O Vertice selecionado nao possui nenhuma adj\n");
        return 0;
    }
    else{

    TVertice aux;
	int i,num_ver,check=0;

    num_ver = TGrafo_NVertices(pGrafo);
    aux = pGrafo->Adj[v].Primeiro->Item.Vertice;

        for(i=0; i<num_ver; i++){
		while(pGrafo->Adj[aux].Tamanho!=0){

            		if(aux == v){
                	check = 1;
                	break;
                    }

            aux = pGrafo->Adj[aux].Primeiro->Item.Vertice;
        	}
	}

        if(check == 1){
            return 1;
            }

        else return 0;
	}
}
