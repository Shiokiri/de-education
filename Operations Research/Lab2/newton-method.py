import csv
import numpy as np
import matplotlib.pyplot as plt

x = []
y = []
r1 = csv.reader(open("data2x.csv"))
for line in r1:
    x.append([1.0,float(line[0].split("  ")[1]),float(line[0].split("  ")[2])])
r2 = csv.reader(open("data2y.csv"))
for line in r2:
    y.append([float(line[0])])
x = np.array(x)
y = np.array(y)

def h(x:np.ndarray,theta:np.ndarray):
    return 1 / (1+np.exp(-np.dot(x, theta)))

def getGradient(theta:np.ndarray):
    return np.dot(x.T, (h(x,theta)-y)) / len(x)

def getHessian(theta:np.ndarray):
    return np.dot(np.dot(x.T,np.diag((h(x, theta) * (1-h(x, theta))).reshape(-1))), x) / len(x)

def L(theta:np.ndarray):
    return (np.linalg.norm(np.dot(y.T, np.log(h(x, theta))))+np.linalg.norm(np.dot((1-y).T, np.log(1-h(x, theta))))) / len(x)

def getNextTheta(theta:np.ndarray):
    return theta-np.dot(np.linalg.inv(getHessian(theta)), getGradient(theta))

eps = 1e-6
historyTheta = []
theta=np.array([[0.0], [0.0], [0.0]])
nextTheta=getNextTheta(theta)
while np.linalg.norm(nextTheta-theta) ** 2 >= eps:
    theta = nextTheta
    nextTheta = getNextTheta(theta)
    historyTheta.append(theta.copy())

print(theta)
print("预测能否被录取",h(np.array([1.0,20.0,80.0]),theta))

print("能被录取" if h(np.array([1.0,20.0,80.0]),theta) > 0.5 else "不能被录取")
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.xlabel('牛顿法迭代次数')
plt.ylabel('L')
x_data = []
y_data = []
for i in range(len(historyTheta)):
    x_data.append(i)
    y_data.append(L(historyTheta[i]))
plt.plot(x_data, y_data)
plt.show()