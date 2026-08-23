import matplotlib.pyplot as plt

# Input sizes
n = [10000, 50000, 100000, 500000, 1000000]

# Put the actual execution times from C program here
time_taken = [
    0.001,   # 10000
    0.005,   # 50000
    0.010,   # 100000
    0.050,   # 500000
    0.100    # 1000000
]

# Create graph
plt.figure(figsize=(10, 6))

plt.plot(n, time_taken, marker='o', linewidth=2)

plt.title("Linear Search - Time Complexity Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")

plt.grid(True)
plt.show()
