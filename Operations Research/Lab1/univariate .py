import csv
import numpy as np
import matplotlib.pyplot as plt

x = []
y = []
r1 = csv.reader(open("data1_x.csv"))
r2 = csv.reader(open("data1_y.csv"))
for line in r1:
    x.append([1.0, float(line[0])])
for line in r2:
    y.append([float(line[0])])
x = np.array(x)
y = np.array(y)

eps = 1e-8
def judge(NextTheta: np.ndarray, Theta: np.ndarray):
    return np.linalg.norm(NextTheta - Theta) ** 2 < eps


alpha = 0.01
def getTheta(theta: np.ndarray):
    nextTheta = theta - alpha / len(x) * np.dot(x.T, (np.dot(x, theta) - y))
    return nextTheta


theta = np.array([[0.0], [0.0]])
nextTheta = getTheta(theta)

historyTheta = []
while not judge(nextTheta, theta):
    historyTheta.append(theta.copy())
    theta = nextTheta.copy()
    nextTheta = getTheta(theta)

def h(theta: np.ndarray, x: np.ndarray):
    return np.dot(x, theta)

print(theta)
print("3.5岁小孩的预测身高为：", h(theta, np.array([1.0, 3.5])))
print("7岁小孩的预测身高为：", h(theta, np.array([1.0, 7.0])))

def J(theta: np.ndarray):
    return (np.linalg.norm(h(theta, x) - y) ** 2) * len(x) / 2

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.xlabel('迭代次数')
plt.ylabel('目标函数J(θ)')
x_data = []
y_data = []
for i in range(len(historyTheta)):
    x_data.append(i)
    y_data.append(J(historyTheta[i]))
plt.plot(x_data, y_data)
plt.show()