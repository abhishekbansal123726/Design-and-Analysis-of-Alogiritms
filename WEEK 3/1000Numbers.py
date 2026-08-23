import matplotlib.pyplot as plt

algorithms = [
    "Linear Search",
    "Binary Search",
    "Bubble Sort",
    "Insertion Sort",
    "Quick Sort"
]

# C program ke actual times yahan daalo
times = [
    0.001,
    0.0001,
    0.005,
    0.003,
    0.001
]

plt.figure(figsize=(10,6))

plt.bar(algorithms, times)

plt.title("Algorithm Execution Time")
plt.xlabel("Algorithms")
plt.ylabel("Execution Time (seconds)")

plt.xticks(rotation=20)
plt.grid(axis="y")

plt.show()
