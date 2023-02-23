import numpy as np

#artigo Particle swarm optimization for traveling salesman problem usado como base (KANGPING WANG, LAN HUANG, CHUN-GUANG ZHOU, WE1 PhG)

printer = 0 #1 print da evolucao

cities = [0, 1, 2, 3, 4, 5, 6, 7] #cidades 0-A, 1-B, ...
pop_size = 10 #tamanho da populacao
epochs = 500 #criterio de parada

phi2 = 0.22
phi1 = 0.78

#matriz com as distancias das cidades
adjacency_mat = np.array(
    [
        [0, 42, 61, 30, 17, 82, 31, 11],
        [42, 0, 14, 87, 28, 70, 19, 33],
        [61, 14, 0, 20, 81, 21, 8, 29],
        [30, 87, 20, 0, 34, 33, 91, 10],
        [17, 28, 81, 34, 0, 41, 34, 82],
        [82, 70, 21, 33, 41,0, 19, 32],
        [41, 19, 8, 91, 34, 19, 0, 59],
        [11, 33, 29, 10, 82, 32, 59, 0],
    ]
)

class Particle:
    def __init__(self, route):
        self.route = route  # cordenada
        self.swap_sequence = [] # velocidade
        self.best_fitness = np.Inf #melhor apitidao
        self.best_route = [] #melhor coordenada
        self.fitness = np.Inf #apitidao atual
        self.initial_ss()

    def initial_ss(self): #gera swap sequence inicial
        n = np.random.randint(len(self.route)+1)
        for swap in range(n):
            self.swap_sequence.append((np.random.randint(len(self.route)), np.random.randint(len(self.route))))

def init_population(pop): #inicia a populcao com as particulas contendo uma permutacao aleatoria das cidades como rota
    for i in range(pop_size):
        initial_route = list(np.random.permutation(cities))
        pop.append(Particle(initial_route))
    gbest_route = pop[0].route
    gbest_fitness = np.Inf

    return gbest_route, gbest_fitness

def fitness(route): #soma as distancias da rota para o fitness
    a = 0
    for i in range (len(route)-1):
        a += adjacency_mat[route[i], route[i + 1]]
    return a + int(adjacency_mat[route[i+1]][route[0]])


def basic_ss(r1, r2): #cria a basic swap sequence que leva A ao B (caminho de um ponto a outro)
    cp_r2 = r2.copy()
    result_ss = []
    for i in range (len(r1)):
        if r1[i] == r2[i]:
            return result_ss
        index = cp_r2.index(r1[i])
        result_ss.append((i, index))
        cp_r2[i], cp_r2[index] = cp_r2[index], cp_r2[i]
    return result_ss


class PSO:
    def __init__(self, fitness_function, init):

        self.population_size = pop_size
        self.population = []
        self.fitness_function = fitness_function
        self.gbest_route = []
        self.gbest_fitness = np.Inf
        self.init = init
        self.gbest_route, self.gbest_fitness  = self.init(self.population)

    def update_population(self):

        for part in self.population:
            fitness = self.fitness_function(part.route)
            part.fitness = self.fitness_function(part.route)
            if fitness < self.gbest_fitness:
                self.gbest_route=part.route.copy()
                self.gbest_fitness = part.fitness
            if fitness < part.best_fitness:
                part.best_fitness = fitness
                part.best_route = part.route

            gss = basic_ss(self.gbest_route, part.route) #global best e phi1
            lss = basic_ss(part.best_route, part.route) #local best e phi2
            lss_aux = lss.copy()
            gss_aux = gss.copy()

            for i in gss:
                rand = np.random.rand(1)
                if rand < phi1:
                    gss_aux.remove(i)
            gss = gss_aux

            
            for i in lss:
                rand = np.random.rand(1)
                if rand < phi2:
                    lss_aux.remove(i)
            lss = lss_aux
            
            rand = np.random.rand(1)
            if (rand<phi2): #leva em conta melhor seq local
                part.swap_sequence.extend(lss)

            elif (rand<phi1): #leva em conta melhor seq global
                part.swap_sequence.extend(gss)

            for swap in part.swap_sequence: #modifica coordenada
                part.route[swap[0]], part.route[swap[1]] = part.route[swap[1]], part.route[swap[0]]


def run(pso): #roda o algoritmo salvando a melhor rota
    for i in range(epochs):
        pso.update_population()
        if (printer == 1):
            print('\nRota',i ,'                dist')
            print( pso.gbest_route, pso.gbest_fitness)
    l = pso.gbest_route
    l.append(l[0])
    f.write(str(l)+' ' +str(pso.gbest_fitness)+'\n')


if __name__ == '__main__':
    f = open("TSP_PSO.txt", "w")
    for i in range(30):
        pso = PSO(fitness, init_population)
        run(pso)
    f.close()