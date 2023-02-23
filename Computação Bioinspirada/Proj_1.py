import pygad
import numpy
import matplotlib


def fitness_func(solution, solution_idx):
    output = ((2*solution[0]**4)-(3*solution[0]**3)+(7*solution[0])-5)
    if (output<=0):
        fitness = abs(output)+1
    else:
        fitness = 1/output
    return fitness

fitness_function = fitness_func

num_generations = 1000
num_parents_mating = 15

sol_per_pop = 30
num_genes = 1

init_range_low = -31
init_range_high = 32

parent_selection_type = "sss"
keep_parents = 1

crossover_type = "single_point"

mutation_type = "random"
mutation_percent_genes = 5

ga_instance = pygad.GA(num_generations=num_generations,
                       num_parents_mating=num_parents_mating,
                       fitness_func=fitness_function,
                       sol_per_pop=sol_per_pop,
                       num_genes=num_genes,
                       init_range_low=init_range_low,
                       init_range_high=init_range_high,
                       gene_type=float,
                       parent_selection_type=parent_selection_type,
                       keep_parents=keep_parents,
                       crossover_type=crossover_type,
                       mutation_type=mutation_type,
                       parallel_processing=2,
                       save_solutions=True,
                       mutation_percent_genes=mutation_percent_genes)

ga_instance.run()

solution, solution_fitness, solution_idx = ga_instance.best_solution()
print("Parameters of the best solution : {solution}".format(solution=solution))
print("Fitness value of the best solution = {solution_fitness}".format(solution_fitness=solution_fitness))

prediction = ((2*solution[0]**4)-(3*solution[0]**3)+(7*solution[0])-5)
print("Predicted output based on the best solution : {prediction}".format(prediction=prediction))

#print(ga_instance.initial_population)

ga_instance.plot_genes()
ga_instance.plot_fitness()