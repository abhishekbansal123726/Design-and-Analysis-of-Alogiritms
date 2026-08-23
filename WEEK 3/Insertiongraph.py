import matplotlib.pyplot as plt

n = [1000, 2000, 4000, 6000, 8000, 10000]

# Replace with actual times from C program
time_taken = [
    0.001,
    0.004,
    0.016,
    0.036,
    0.064,
    0.100
]

plt.figure(figsize=(10, 6))

plt.plot(n, time_taken, marker='o', linewidth=2)

plt.title("Insertion Sort - Time Complexity Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")

plt.grid(True)
plt.show()
