import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def read_output_file(file_path):
    iterations = []
    with open(file_path, 'r') as file:
        lines = file.readlines()
        i = 0
        while i < len(lines):
            iteration_num = int(lines[i].strip())
            ranks_data = []

            # Continue reading rank data lines until an exception is encountered
            while True:
                try:
                    i += 1
                    # If the end of the file is reached, break the outer loop as well
                    if i >= len(lines):
                        break
                    rank, x, y, z = map(float, lines[i].strip().split())
                    ranks_data.append([x, y, z])
                except ValueError:
                    # When a ValueError is encountered, it means we've reached the end of the rank data lines for the current iteration
                    break

            # If the end of the file was reached, don't append an iteration with no rank data
            if ranks_data:
                iterations.append((iteration_num, ranks_data))

    return iterations



def plot_iterations(iterations_data):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    for iteration_num, ranks_data in iterations_data:
        for rank, coordinates in enumerate(ranks_data):
            x, y, z = coordinates
            ax.scatter(x, y, z, marker='o', label=f'Iteration {iteration_num}, Rank {rank + 1}')

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('All Iterations')
    ax.legend()

    plt.show()

# Change the file_path to the actual path of your text file
file_path = 'GeneticAlgorithm.txt'

# Read data from the text file
iterations_data = read_output_file(file_path)

# Plot all iterations on the same graph
plot_iterations(iterations_data)
