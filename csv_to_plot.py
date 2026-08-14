import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("robot_simulation.csv")

plt.plot(data["time"], data["x"], label='X Position', color = 'blue', linestyle='-')
plt.plot(data["time"], data["y"], label='Y Position', color = 'red', linestyle='--')
plt.xlabel("Time (s)")
plt.ylabel("Position")
plt.title("Robot Position")
plt.show()

plt.plot(data["time"], data["v_x"], label = 'X Velocity', color = 'blue', linestyle='-')
plt.plot(data["time"], data["v_y"], label = 'Y Velocity', color = 'red', linestyle='--')
plt.xlabel("Time (s)")
plt.ylabel("Velocity")
plt.title("Robot Velocity")
plt.show()

plt.plot(data["time"], data["x_error"], label = 'X Error', color = 'blue', linestyle='-')
plt.plot(data["time"], data["y_error"], label = 'Y Error', color = 'red', linestyle='--')
plt.xlabel("Time (s)")
plt.ylabel("Error")
plt.title("Robot Error")
plt.show()