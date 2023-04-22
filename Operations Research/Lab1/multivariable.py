import csv
import numpy as np
import matplotlib.pyplot as plt

x = []
y = []
r1 = csv.reader(open("data2_x.csv"))
for line in r1:
    x.append([1.0,float(line[0].split("   ")[1]),float(line[0].split("   ")[2])])
r2 = csv.reader(open("data2_y.csv"))
for line in r2:
    y.append([float(line[0])])

x = np.array(x)
y = np.array(y)

sigma = [np.std(x[:,i]) for i in range(3)]
mu = [np.mean(x[:,i]) for i in range(3)]
x[:,1] = (x[:,1]-mu[1])/sigma[1]
x[:,2] = (x[:,2]-mu[2])/sigma[2]

def J(theta: np.ndarray):
    return (np.linalg.norm(np.dot(x,theta)-y)**2)/(len(x)*2)

def getGradient(theta: np.ndarray):
    return np.dot(x.T, (np.dot(x,theta)-y))/len(x)

eps = 1e-6
def getAlpha(theta: np.ndarray, d: np.ndarray):
    l = 0.001
    r = 10
    while (r-l > eps):
        ll = l+(r-l)*0.382
        rr = l+(r-l)*0.618
        if (J(theta+ll*d) < J(theta+rr*d)):
            r = rr
        else:
            l = ll
    return l

historyTheta = []
theta =np.array([[0.0],[0.0],[0.0]])
d=-getGradient(theta)
alpha=getAlpha(theta,d)

while np.linalg.norm(d) > eps:
    theta = theta+alpha*d
    d = -getGradient(theta)
    alpha = getAlpha(theta,d)
    historyTheta.append(theta.copy())

print(theta)
print("1650平方英尺3卧室的房子的价格：", np.dot(np.array([1.0,(1650.0-mu[1]) / sigma[1], (3.0-mu[2]) / sigma[2]]), theta))

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
