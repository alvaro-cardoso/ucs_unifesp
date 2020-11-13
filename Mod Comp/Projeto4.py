import matplotlib.pyplot as plt
import numpy as np

DT = 0.01 # Passo para cada atualização
TMax = 365 # Tempo total de simulação

N = 10000 # População total
S = N - 10 # População inicial de susceptiveis
I = N - S # População incial de infectados
R = 0 # População inicial de recuperados
# Array das populações e do tempo
S_array = [S]
I_array = [I]
R_array = [R]
t_array = [0]

r = 0.000025 # Taxa de contaminação
a = 1/15 # Taxa de recuperação 

pico = 0 
diaPico = 0
# Laço para atualizar as classificações da população
for t in np.arange(DT, TMax, DT):
    # Variação das populações
    dS = (-r*S*I) * DT
    dI = (r*S*I - a*I) * DT
    dR = (a*I) * DT

    # Atualização das populações
    S += dS
    I += dI
    R += dR

    if I > pico: # Atualiza a quantidade e dia do pico de infectados
        diaPico = t 
        pico = I

    S_array.append(S)
    I_array.append(I)
    R_array.append(R)
    t_array.append(t)

print(pico)

plt.plot(t_array,S_array)
plt.title('Individuos Susceptiveis')
plt.show()
plt.plot(t_array,I_array)
plt.scatter(diaPico,pico) # Marca o pico
plt.annotate(str(int(pico)),xy=(diaPico,pico)) # Escreve a quantidade do pico
plt.title('Individuos Infectados')
plt.ylim(top=N) # Limitar o y para melhor vizualização do achatamento
plt.show()
plt.plot(t_array,R_array)
plt.title('Individuos Recuperados')
plt.show()

