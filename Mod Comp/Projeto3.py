import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import random as rd

TAM = 100 # População
m = 2*TAM # Quantidade de arestas necesárias para grau minimo 4 do grafo com população TAM
G = nx.generators.random_graphs.dense_gnm_random_graph(TAM, m, seed=134450) # Geração do grafo aleatório 

#nx.draw_spring(G,with_labels=True) # Plot do grafo gerado

TMax = 100 # Dias de simulação
estado = np.zeros((TAM,TMax), dtype=int) # Estados para as vértices
# -1: Morto, 0: Susceptivel e 1: Infectado
duracao = np.zeros((TAM,TMax), dtype=int) # Vetor para tempo da vértice com doença
imunidade = np.zeros((TAM,TMax), dtype=int) # Vetor para tempo de imunidade
uptime = 5 # Tempo até o indivíduo ser curado
downtime = 5 # Tempo de imunidade
p_infec = 0.1 # Probabilidade de Infecção
p_morte = 0.03 # Probabilidade de Morte
zero = rd.randint(0,TAM-1) # Gerador aleatório para determinar o paciente
estado[zero][0] = 1 # Flag de pessoa infectada
duracao[zero][0] = uptime # Duração da doença do primeiro paciente

t_array = [0]
for t in range(1, TMax): # Loop para a simulação
    for i in range(TAM): # Loop de verificação de mortos e atualização de tempo de imunidade
        if(estado[i][t-1]==-1):
            estado[i][t] = -1
        else:
            if(imunidade[i][t-1]>0): # Desconta tempo de imunidade, caso esteja imune e não esteja morto
                imunidade[i][t] = imunidade[i][t-1] - 1

    for n in range(TAM): # Loop de análise de cada vértice
        if estado[n][t-1] == 1: # Se ja possui a doença
            if np.random.random_sample()<=p_morte: # Possui uma chance de morrer
                G.remove_node(n) # Remove do grafo o node que representa a pessoa morta
                estado[n][t] = -1 # Atualiza estado para morto
            else:
                duracao[n][t] = duracao[n][t-1] - 1 # Diminui o tempo da vértice com a doença
                if(duracao[n][t]==0): # Se duração da doença acabar, vira imune e estado não infectado
                    imunidade[n][t] = downtime
                    estado[n][t] = 0

        Viz_infectado = False 
        if G.has_node(n) and imunidade[n][t]==0: # Se n ainda estiver no grafo e não estiver imune
            for Vizinho in nx.Graph.neighbors(G,n): # Olha os vizinhos de n e verifica estado dele
                if(estado[Vizinho][t-1] == 1):
                    Viz_infectado = True # Se possui vizinho infectado
                    break
        
            if np.random.random_sample()<=p_infec and Viz_infectado and estado[n][t-1]==0: # Se possui vizinho infectado e probalidade aceitável
                estado[n][t] = 1 # Vértice infectada
                duracao[n][t] = uptime # Duração do contágio
            else:
                estado[n][t] = estado[n][t-1] # Continua infectado

    continua = False # Flag para continuar o plot dos dias da simulação
    
    for i in range(TAM): # Loop análise se ainda há infectados
        if(estado[i][t]==1):
            continua = True

    if not continua: # Para a simulação quando não há mais infectados
        break

plt.matshow(estado) # Plot da matriz de estados
plt.xlim(0,t)
plt.show()
