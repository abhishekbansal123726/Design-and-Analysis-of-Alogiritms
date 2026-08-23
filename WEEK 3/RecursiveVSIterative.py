import matplotlib.pyplot as plt

methods = [
    "Recursive",
    "Iterative"
]

# C program ke actual times yahan daalo
times = [
    0.020,
    0.010
]

plt.figure(figsize=(8,5))

plt.bar(methods, times)

plt.title("Recursive vs Iterative Factorial")
plt.xlabel("Method")
plt.ylabel("Execution Time (seconds)")

plt.grid(axis="y")

plt.show()
