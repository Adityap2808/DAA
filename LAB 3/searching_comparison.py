import matplotlib.pyplot as plt

# Example data (replace with your actual output)
input_sizes = [10, 100, 1000, 10000, 100000]
linear_comparisons = [10, 100, 1000, 10000, 100000]      # Replace with your LinComp values
binary_comparisons = [4, 7, 10, 14, 17]                  # Replace with your BinComp values

plt.plot(input_sizes, linear_comparisons, marker='o', label='Linear Search')
plt.plot(input_sizes, binary_comparisons, marker='s', label='Binary Search')

plt.xlabel('Input Size (n)')
plt.ylabel('Number of Comparisons')
plt.title('Searching Algorithms: Comparisons vs Input Size')
plt.legend()
plt.grid(True)
plt.xscale('log')  # Optional: log scale for better visualization
plt.show()