import numpy as np
import matplotlib.pyplot as plt
import math

DT = 0.01 #Delta T
TMax = 120 #Tempo de simulação
v0 = 50 #Velocidade Inicial   
y0 = 75 #Posição Inicial em Y
x0 = 25 #Posição Inicial em X
k = 0.5 #Coeficiente de Atrito
g = -9.8 #Constante Gravitacional
theta = (math.pi)/6 #Ângulo de Lançamento
m = 10 #Massa do Corpo

vx = v0*(math.cos(theta)) #Velocidade Inicial em X
vy = v0*(math.sin(theta)) #Velocidade Inicial em Y
vx_array = [vx] #Vetor Velocidade em X
vy_array = [vy] #Vetor Velocidade em Y
v_array = [v0] #Vetor Velocidade em Total
Sy_array = [y0] #Vetor Posição em X
Sx_array = [x0] #Vetor Posição em Y
t_array = [0] #Vetor do tempo
Et_array = [None] #Vetor da Energia Total
Ep_array = [None] #Vetor da Energia Potencial
Ec_array = [None] #Vetor da Energia Total
Q_array = [None] #Vetor da Energia Térmica
Ec = 0.5*m*math.pow(v0,2) #Calcula energia cinética
Et = Ec #Temos somente energia cinética no começo do lançamento
y = y0 # Atribuir posição inicial
x = x0 # Atribuir posição inicial

#Loop do tempo
for t in np.arange(DT, TMax, DT):
    # Velocidade em x
    vx = vx+((-k/m)*vx)*DT

    # Velocidade em y
    vy = vy+(g-((k/m)*vy))*DT

    # Velocidade Total
    v = math.sqrt(math.pow(vx,2) + math.pow(vy,2))

    # Deslocamento em y
    y = y + vy*(DT)

    # Deslocamento em x
    x = x + vx*(DT)

    # Energia cinética
    Ec = 0.5*m*math.pow(v,2)

    # Energia potencial
    Ep = m*(-g)*y #modulo de g

    # Energia térmica(calor)/Energia perdida
    Q = Et - (Ec+Ep)

    # Energia total
    Et =  Q + Ec + Ep

    #Condicional para rebater o corpo quando atinge o chão    
    if y <= 0:
        vy = -vy*0.5 # Escolha da perda de velocidade
        y = 0

    #if y==0:
        #break

    #Atribuição de valores nos vetores
    Sx_array.append(x)
    Sy_array.append(y)
    vx_array.append(vx)
    vy_array.append(vy)
    Et_array.append(Et)
    Ep_array.append(Ep)
    Ec_array.append(Ec) 
    Q_array.append(Q)
    v_array.append(v)
    t_array.append(t)

#Funções Gráfico
plt.plot(t_array, v_array)
plt.title('Velocidade')
plt.xlabel('Tempo')
plt.ylabel('Velocidade')
plt.show()
plt.plot(Sx_array, Sy_array)
plt.title('Deslocamento')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()
plt.plot(t_array, Et_array)
plt.title('Energia total')
plt.xlabel('Tempo')
plt.ylabel('Energia')
plt.yticks (np.arange(0, 200000, 40000)) #Marcadores para melhor compreensão do gráfico
plt.show()
plt.plot(t_array, Ep_array)
plt.title('Energia potencial')
plt.xlabel('Tempo')
plt.ylabel('Energia')
plt.show()
plt.plot(t_array, Ec_array)
plt.title('Energia cinética')
plt.xlabel('Tempo')
plt.ylabel('Energia')
plt.show()
plt.plot(t_array, Q_array)
plt.title('Energia térmica')
plt.xlabel('Tempo')
plt.ylabel('Energia')
plt.show()