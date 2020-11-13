import matplotlib.pyplot as plt
import numpy as np
import random as rd
import networkx as nx

dT = 0.01 # Passo da integração númerica
TMax = 1000 # Tempo de simulação
Paises = 10 # Quantidade de países
Conexoes = Paises # Quantidade de conexões para obtenção de grau médio 2
G = nx.generators.random_graphs.dense_gnm_random_graph(Paises, Conexoes, seed=136124) # Geração da rede com seed continua, ou seja, mesmas conexões para todas simulações

#nx.draw_spring(G,with_labels=True) # Plot do grafo
#plt.show()

Prob = True # Escolha de Modelo: False = Determinístico; True = Estocástico.

# População inicial de cada país
N0 = 100000
N1 = 1000000
N2 = 200000
N3 = 300000
N4 = 500000
N6 = 200000
N5 = 900000
N7 = 800000
N8 = 100000
N9 = 700000

# Vetores de populações iniciais
N = [N0,N1,N2,N3,N4,N5,N6,N7,N8,N9]
S = [N0*1,N1*1,N2*1,N3*0.999,N4*1,N5*1,N6*1,N7*1,N8*1,N9*1]
I = [N0*0,N1*0,N2*0,N3*0.001,N4*0,N5*0,N6*0,N7*0,N8*0,N9*0]
R = np.zeros((Paises))

# Taxas de infecção de cada país
r0 = 0.000001
r1 = 0.0000002
r2 = 0.0000015
r3 = 0.000001
r4 = 0.0000005
r5 = 0.00000025
r6 = 0.0000009
r7 = 0.0000003
r8 = 0.000002
r9 = 0.0000002
r = [r0,r1,r2,r3,r4,r5,r6,r7,r8,r9]

# Taxas de recuperação de cada país 
a0 = 1/15
a1 = 1/15
a2 = 1/15
a3 = 1/15
a4 = 1/15
a5 = 1/15
a6 = 1/15
a7 = 1/15
a8 = 1/15
a9 = 1/15
a = [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9]

# Taxas de susceptibilidade a reinfecção de cada país 
f0 = 0.001
f1 = 0.01
f2 = 0.002
f3 = 0.003
f4 = 0.005
f5 = 0.009
f6 = 0.002
f7 = 0.008
f8 = 0.001
f9 = 0.007
f = [f0,f1,f2,f3,f4,f5,f6,f7,f8,f9]

# Taxas de visitação entre os países
v01 = 0.00035
v10 = 0.000055
v15 = 0.00005
v19 = 0.00006
v24 = 0.00003
v25 = 0.000035
v28 = 0.00002
v34 = 0.00005
v36 = 0.0000003
v37 = 0.0001
v39 = 0.00018
v42 = 0.00017
v43 = 0.00015
v51 = 0.00027
v52 = 0.00018
v63 = 0.000075
v73 = 0.00007
v82 = 0.0004
v91 = 0.000015
v93 = 0.000025
v = [[0,v01,0,0,0,0,0,0,0,0],
    [v10,0,0,0,0,v15,0,0,0,v19],    
    [0,0,0,0,v24,v25,0,0,v28,0],    
    [0,0,0,0,v34,0,v36,v37,0,v39],
    [0,0,v42,v43,0,0,0,0,0,0],
    [0,v51,v52,0,0,0,0,0,0,0],
    [0,0,0,v63,0,0,0,0,0,0],
    [0,0,0,v73,0,0,0,0,0,0],
    [0,0,v82,0,0,0,0,0,0,0],
    [0,v91,0,v93,0,0,0,0,0,0]]

# Probabilidade de visitação entre os países (Modelo Estocástico)
p01 = 0.3
p10 = 0.2
p15 = 0.4
p19 = 0.35
p24 = 0.45
p25 = 0.3
p28 = 0.45
p34 = 0.5
p36 = 0.25
p37 = 0.1
p39 = 0.6
p42 = 0.55
p43 = 0.25
p51 = 0.45
p52 = 0.3
p63 = 0.2
p73 = 0.4
p82 = 0.5
p91 = 0.6
p93 = 0.55
p = [[0,p01,0,0,0,0,0,0,0,0],
    [p10,0,0,0,0,p15,0,0,0,p19],    
    [0,0,0,0,p24,p25,0,0,p28,0],    
    [0,0,0,0,p34,0,p36,p37,0,p39],
    [0,0,p42,p43,0,0,0,0,0,0],
    [0,p51,p52,0,0,0,0,0,0,0],
    [0,0,0,p63,0,0,0,0,0,0],
    [0,0,0,p73,0,0,0,0,0,0],
    [0,0,p82,0,0,0,0,0,0,0],
    [0,p91,0,p93,0,0,0,0,0,0]]

# Vetores para as populações de cada país a cada passo da simulação
S_array = [[S[0]],[S[1]],[S[2]],[S[3]],[S[4]],[S[5]],[S[6]],[S[7]],[S[8]],[S[9]]]
I_array = [[I[0]],[I[1]],[I[2]],[I[3]],[I[4]],[I[5]],[I[6]],[I[7]],[I[8]],[I[9]]]
R_array = [[0],[0],[0],[0],[0],[0],[0],[0],[0],[0]]

# Vetor do tempo da simulação
t_array = [0]

# Vetores de pico de infectados e dia do pico
pico = np.zeros((Paises))
diaPico = np.zeros((Paises))

# Vetores de variações de populações dos países
dS = np.zeros((Paises))
dI = np.zeros((Paises))
dR = np.zeros((Paises))

for t in np.arange(dT, TMax, dT): # Loop da simulação
    for n in range(Paises): # Loop de atualização de cada país
        Migracao = 0 # Valor da população de infectados que viaja para países vizinhos
        for Vizinho in nx.Graph.neighbors(G,n): # Loop das viagens para países vizinhos
            if np.random.random_sample() <= p[Vizinho][n] and Prob == True: # Modelo Estocástico 
                Migracao+=v[n][Vizinho]*I[Vizinho]
                I[Vizinho]-=v[n][Vizinho]*I[Vizinho]
            if not Prob: # Modelo Determinístico
                Migracao+=v[n][Vizinho]*I[Vizinho]
                I[Vizinho]-=v[n][Vizinho]*I[Vizinho]

        # Vetores de variações das populações do país
        dS[n] = (-r[n]*S[n]*(I[n]+Migracao)+f[n]*R[n])*dT
        dI[n] = (r[n]*S[n]*(I[n]+Migracao)-a[n]*I[n])*dT
        dR[n] = (a[n]*I[n]-f[n]*R[n])*dT

        # Atualização das populações do país
        S[n] += dS[n]
        I[n] += dI[n]
        R[n] += dR[n]

        # Identifica os picos e o dia do mesmo
        if I[n] > pico[n]:
            diaPico[n] = t
            pico[n] = I[n]

        # Coloca as populações em vetores para plot dos gráficos
        S_array[n].append(S[n])
        I_array[n].append(I[n])
        R_array[n].append(R[n])
    t_array.append(t)

for i in range(Paises): # Loop de plot dos gráficos de cada país
    plt.suptitle('País ' + str(i))
    plt.subplot(221)
    plt.plot(t_array,S_array[i])
    plt.title('Individuos Susceptiveis')
    plt.subplot(222)
    plt.plot(t_array,I_array[i])
    plt.title('Individuos Infectados')
    plt.scatter(diaPico[i],pico[i]) # Marca o pico
    plt.annotate(str(int(pico[i])),xy=(diaPico[i],pico[i])) # Escreve a quantidade do pico
    plt.ylim(top=N[i])
    plt.subplot(223)
    plt.plot(t_array,R_array[i])
    plt.title('Individuos Recuperados')
    plt.show()