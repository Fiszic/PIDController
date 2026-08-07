import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("pid_simulation.csv")

plt.plot(data["time"], data["position"])
plt.xlabel("Time (s)")
plt.ylabel("Position")
plt.title("Robot Position")
plt.show()

plt.plot(data["time"], data["velocity"])
plt.xlabel("Time (s)")
plt.ylabel("Velocity")
plt.title("Robot Velocity")
plt.show()