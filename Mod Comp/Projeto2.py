import numpy as np
import matplotlib.pyplot as plt
import math

# Modelo Lotka-Volterra
DT = 0.01 # Passo para cada atualização
TMax = 1000 # Tempo total de simulação

#valor inicial das populações (Respectivas cores nos gráficos)
onca = 1 # Amarelo
veado = 1 # Marrom
lobog = 1 # Laranja
caititu = 5 # Preto
morango = 30  # Vermelho
grama = 30 # Verde

# Parâmetros
p1 = 0.2  # Decrescimento da onça
p2 = 0.001 # onca come lobo
p3 = 0.05  # onca come veado 
p4 = 0.1  # Decrescimento do lobo
p5 = 0.001  # Lobo é comido pela onça
p6 = 0.001  # Lobo come veado
p7 = 0.01  # Lobo come caititu
p8 = 0.005  # Lobo come morango
p9 = 0.1  # Decrescimento do veado
p10 = 0.001 # Veado é comido pela onça
p11 = 0.001 # Veado é comido pelo lobo
p12 = 0.1 # Veado come grama
p13 = 0.1 # Decrescimento do caititu
p14 = 0.001 # Caititu é comido pelo lobo
p15 = 0.01 # Caititu come morango
p16 = 0.04 # Caititu come grama
p17 = 0.5 # Crescimento do morango
p18 = 0.005 # Morango é comido pelo lobo
p19 = 0.01 # Morango é comido pelo caititu
p20 = 0.5 # Crescimento da grama
p21 = 0.1 # Grama é comido pelo veado
p22 = 0.01 # Grama é comido pelo caititu
k1 = 10 # Termologistico do crescimento do morango
k2 = 10 # Termo logistico do crescimento da grama

# Vetores de cada animal com os valores iniciais de cada população
onca_array = [onca]
lobog_array = [lobog]
veado_array = [veado]
caititu_array = [caititu]
morango_array = [morango]
grama_array = [grama]

# Inicia vetor do tempo com 0
t_array = [0]

# Matriz de adjacência com as constantes
m = [[p1,p2,p3,0,0,0],[p5,p4,p6,p7,p8,0],[p10,p11,p9,0,0,p12],[0,p14,0,p13,p15,p16],[0,p18,0,p19,p17,0],[0,0,p21,p22,0,p20]]

# Simulação de estação e quantidade de chuva (Afeta 100% a grama e 33% o morango)
estacao = 1 # 0 para não considerar e 1 para considerar
duracao = 0.1 # Extensão da estação
efetividade = 0.1 # efetividade de chuva

# Simulação de temporada de caça aos veados
temporada = 0 # 0 para não considerar e 1 para considerar
caca = 0.1 # Efetividade da caça
comeco = TMax/5 # Dia de ínicio
fim = TMax/2 # Dia de término

# Simulação da extinção abrupta dos caititus
extincao = 0 # 0 para não considerar e 1 para considerar
data = TMax/2 # Data de extinsão da espécie

# Laço para atualizar as populações de cada integrante da cadeia
for t in np.arange(DT, TMax, DT):

    dt_onca = onca * (-m[0][0] + m [0][1] * lobog + m[0][2] * veado) * DT #A0 - Eq Variação populacional da onça
    dt_loboguara = lobog * (-m[1][1] - m[1][0] * onca + m[1][2] * veado + m[1][3] * caititu + m[1][4] * morango) * DT #B0 - Eq Variação populacional do loboguará

    if(temporada == 1 and t >= comeco and t <= fim):
        dt_veado = veado * (-m[2][2] - m[2][0] * onca - m[2][1] * lobog + m[2][5] * grama - caca) * DT #C0 - Eq Variação populacional do veado considerando a caça
    else:
        dt_veado = veado * (-m[2][2] - m[2][0] * onca - m[2][1] * lobog + m[2][5] * grama) * DT #C0 - Eq Variação populacional do veado

    if(extincao == 1 and t == data):
        caititu = 0 # Acaba a população de caititus
        dt_caititu = 0
    else:
        dt_caititu = caititu * (-m[3][3] - m[3][1] * lobog + m[3][4]* morango + m[3][5] * grama) * DT #D0 - Eq Variação populacional do caititu

    if(estacao == 1): # Eq de variação considerando as estações
        dt_morango = morango * (m[4][4] - (m[4][4] * morango) / k1 - m[4][1] * lobog - m[4][3] * caititu + (efetividade/3)*math.sin(duracao*t)) * DT #E0 - Eq Variação populacional do morango
        dt_grama = grama * (m[5][5] - (m[5][5] * grama) / k2 - m[5][2] * veado - m[5][3] * caititu + efetividade*math.sin(duracao*t)) * DT #F0 - Eq Variação populacional da grama
    else:
        dt_morango = morango * (m[4][4] - (m[4][4] * morango) / k1 - m[4][1] * lobog - m[4][3] * caititu) * DT #E0 - Eq Variação populacional do morango
        dt_grama = grama * (m[5][5] - (m[5][5] * grama) / k2 - m[5][2] * veado - m[5][3] * caititu) * DT #F0 - Eq Variação populacional da grama

    # Atualização da populações
    onca += dt_onca
    lobog += dt_loboguara
    veado += dt_veado
    caititu += dt_caititu
    morango += dt_morango
    grama += dt_grama

    # Colocando os valores de populações nos vetores de cada espécie
    onca_array.append(onca)
    lobog_array.append(lobog)
    veado_array.append(veado)
    caititu_array.append(caititu)
    morango_array.append(morango)
    grama_array.append(grama)

    t_array.append(t)

# Plot dos graficos de cada população com sua respectiva cor
plt.plot(t_array, onca_array, color='yellow' )
plt.plot(t_array, lobog_array, color='orange' )
plt.plot(t_array, veado_array,color='brown' )
plt.plot(t_array, caititu_array,color='black' )
plt.plot(t_array, morango_array,color='red')
plt.plot(t_array, grama_array,color='green' )

plt.grid(True) # Grid no gráfico
plt.title('População - Presa-Predador') # Título do gráfico
plt.legend(['Onça', 'Lobo Guará', 'Veado Campeiro', 'Caititu', 'Morango Silvestre', 'Grama'], loc = 'upper right') # Define a legenda do gráfico
plt.show()

# Plot dos gráficos de Phase-Space
""" plt.plot(onca_array,veado_array)
plt.xlabel('Onça')
plt.ylabel('Veado Campeiro')
plt.show()
plt.plot(onca_array,veado_array)
plt.xlabel('Onça')
plt.ylabel('Lobo guará')
plt.show()
plt.plot(lobog_array,veado_array)
plt.xlabel('Lobo guará')
plt.ylabel('Veado Campeiro')
plt.show()
plt.plot(lobog_array,caititu_array)
plt.xlabel('Lobo guará')
plt.ylabel('Caititu')
plt.show()
plt.plot(lobog_array,morango_array)
plt.xlabel('Lobo guará')
plt.ylabel('Morango')
plt.show()
plt.plot(caititu_array,morango_array)
plt.xlabel('Caititu')
plt.ylabel('Morango')
plt.show()
plt.plot(caititu_array,grama_array)
plt.xlabel('Caititu')
plt.ylabel('Grama')
plt.show()
plt.plot(veado_array,grama_array)
plt.xlabel('Veado Campeiro')
plt.ylabel('Grama')
plt.show() """