import numpy as np

city = [0, 1, 2, 3, 4, 5, 6, 7] #cidades 0-A, 1-B, ...

printer = 0 #1 print da evolucao

num_city  = 8 #num de cidades

pop_size = 1000 #tamanho da populacao

best = None #melhor

gen_number = 10000000 #numero de geracoes


#matriz com as distancias das cidades

city_cost = np.array(
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


#inicia a populcao com um permutacao aleatoria
def init_population(city, pop_size):
    arr = np.array([np.random.permutation(city) for ind in range(pop_size)])
    pop = np.array(np.column_stack((arr,arr[:, 0])))
    return pop

#funcao de fitness que calcula a distacia da rota
def fitness(gene):
    return sum(
    [
        city_cost[gene[i], gene[i + 1]]
        for i in range(len(gene) - 1)
    ])

#crossover com chance de mutacao e chance dos filhos serem uma copia dos pais
def crossover(pop_list,fitness_list, p_cross=0.1, p_mut=0.1):
    children = []
    children_fitness_list = []


    for i in range(0, pop_size-1, 2):
        temp = np.array([-1,-1,-1,-1,-1,-1,-1,-1, -1])
        temp2 = np.array([-1,-1,-1,-1,-1,-1,-1,-1, -1])
        rand = np.random.rand(1)


        if rand < p_cross: #filhos copia dos pais
            children.append(pop_list[i])
            children_fitness_list.append(fitness_list[i])
            children.append(pop_list[i+1])
            children_fitness_list.append(fitness_list[i+1])


        else: #gera um filho com as primeira e ultimas posicoes de um pai e o intervalo do meio de outro
            for j in range(2, 6, 1):
                temp[j] = pop_list[i][j]
            cont = 0
            for k in range(len(temp)-1):
                if temp[k] == -1:
                    while pop_list[i+1][cont] in temp:
                        cont += 1
                    temp[k] = pop_list[i+1][cont]
            temp[len(temp)-1] = temp[0]

            if rand < p_mut: #troca duas cidades aleatoriasde posicao na rota
                a, b = np.random.choice(len(temp), 2)
                temp[a], temp[b] = (temp[b],temp[a])

            children.append(temp)
            children_fitness_list.append(fitness(temp))

            #gera outro filho com as primeira e ultimas posicoes de um pai e o intervalo do meio de outro
            for j in range(2, 6, 1):
                temp2[j] = pop_list[i+1][j]
            cont = 0
            for k in range(num_city):
                if temp2[k] == -1:
                    while pop_list[i][cont] in temp2:
                        cont += 1
                    temp2[k] = pop_list[i][cont]
            temp2[len(temp2)-1] = temp2[0]
            if rand < p_mut:
                a, b = np.random.choice(len(temp2), 2)
                temp2[a], temp2[b] = (temp2[b],temp2[a])
            children.append(temp2)
            children_fitness_list.append(fitness(temp2))

    return(children,children_fitness_list)


#inicia a evolucao salvando o melhor fitness e sua rota
def ga_start():

    pop = init_population(city, pop_size)
    pop_list = []
    fitness_list = []
    gen_list = []
    generation = 1
    pop_list = list(pop)

    for i in range(pop_size):
        fitness_list.append(fitness(pop[i]))
        gen_list.append(generation)

    best_id = fitness_list.index(min(fitness_list))
    best = pop_list[best_id]
    best_fit = min(fitness_list)
    if printer == 1:
        print("Geracao 0")
        print("Gene                Fitness")
        for obj in range(len(pop_list)):
            print(pop_list[obj],fitness_list[obj])
        for i in range(1, gen_number, 1):
            pop_list,fitness_list = crossover(pop_list,fitness_list)
            a = min(fitness_list)
            b = best_fit
            if(a<=b):
                best_id = fitness_list.index(min(fitness_list))
                best = pop_list[best_id]
                best_fit = min(fitness_list)
            print("Geracao", i)
            print("Gene                Fitness")
            for obj in range(len(pop_list)):
                print(pop_list[obj],fitness_list[obj])
    f.write(str(best)+' ' +str(best_fit)+'\n')



if __name__ == "__main__":
    f = open("TSP_GA.txt", "w")
    for i in range(30):
        ga_start()
    f.close()