import matplotlib.pyplot as plt

# Input sizes
n = [1000, 2000, 4000, 6000, 8000, 10000]

# Enter actual execution times from C program
time_taken = [
    0.001,   # 1000
    0.004,   # 2000
    0.016,   # 4000
    0.036,   # 6000
    0.064,   # 8000
    0.100    # 10000
]

# Create graph
plt.figure(figsize=(10, 6))

plt.plot(n, time_taken, marker='o', linewidth=2)

plt.title("Bubble Sort - Time Complexity Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")

plt.grid(True)
plt.show()
