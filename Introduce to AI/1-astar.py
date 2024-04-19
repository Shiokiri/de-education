import numpy as np


class State:
    def __init__(self, state, directionFlag=None, parent=None, f=0, g=0):
        self.state = state
        self.direction = ['up', 'down', 'right', 'left']
        if directionFlag:
            self.direction.remove(directionFlag)
        self.parent = parent
        self.f = f
        self.g = g

    def getDirection(self):
        return self.direction

    def setF(self, f):
        self.f = f
        return

    # 打印结果
    def showInfo(self):
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                print(self.state[i, j], end=' ')
            print("")

        print('->')
        return

    # 获取0点
    def getZeroPos(self):
        postion = np.where(self.state == 0)
        return postion

    # 1 曼哈顿距离
    # 2 h=0
    # 3 将位置不符数码数目的总和与 3 倍数码逆转数目相加
    def getFunctionValue(self):
        cur_node = self.state.copy()
        fin_node = self.answer.copy()
        dist = 0
        N = len(cur_node)

        for i in range(N):
            for j in range(N):
                if cur_node[i][j] != fin_node[i][j]:
                    index = np.argwhere(fin_node == cur_node[i][j])
                    x = index[0][0]  # x point
                    y = index[0][1]  # y point
                    dist += (abs(x - i) + abs(y - j))
        return dist + self.g

    # def getFunctionValue(self):
    #     cur_node = self.state.copy()
    #     fin_node = self.answer.copy()
    #     dist = 0
    #     N = len(cur_node)
    #
    #     for i in range(N):
    #         for j in range(N):
    #             if cur_node[i][j] != fin_node[i][j]:
    #                 index = np.argwhere(fin_node == cur_node[i][j])
    #                 x = index[0][0]
    #                 y = index[0][1]
    #                 if cur_node[x][y]== fin_node[i][j]:
    #                     dist += 2
    #                 else:
    #                     dist += 1
    #
    #     return dist + self.g

    def nextStep(self):
        if not self.direction:
            return []
        subStates = []
        boarder = len(self.state) - 1
        # 获取0点位置
        x, y = self.getZeroPos()
        # 向左
        if 'left' in self.direction and y > 0:
            s = self.state.copy()
            tmp = s[x, y - 1]
            s[x, y - 1] = s[x, y]
            s[x, y] = tmp
            news = State(s, directionFlag='right', parent=self, g=self.g+1)
            news.setF(news.getFunctionValue())
            subStates.append(news)
        # 向上
        if 'up' in self.direction and x > 0:
            # it can move to upper place
            s = self.state.copy()
            tmp = s[x - 1, y]
            s[x - 1, y] = s[x, y]
            s[x, y] = tmp
            news = State(s, directionFlag='down', parent=self, g=self.g+1)
            news.setF(news.getFunctionValue())
            subStates.append(news)
        # 向下
        if 'down' in self.direction and x < boarder:
            # it can move to down place
            s = self.state.copy()
            tmp = s[x + 1, y]
            s[x + 1, y] = s[x, y]
            s[x, y] = tmp
            news = State(s, directionFlag='up', parent=self, g=self.g+1)
            news.setF(news.getFunctionValue())
            subStates.append(news)
        # 向右
        if self.direction.count('right') and y < boarder:
            # it can move to right place
            s = self.state.copy()
            tmp = s[x, y + 1]
            s[x, y + 1] = s[x, y]
            s[x, y] = tmp
            news = State(s, directionFlag='left', parent=self, g=self.g+1)
            news.setF(news.getFunctionValue())
            subStates.append(news)

        return subStates

    # A* 迭代
    def solve(self):
        # openList
        openTable = []
        # closeList
        closeTable = []
        o = []
        openTable.append(self)
        while len(openTable) > 0:
            # 下一步的点移除open
            print("---openTable---")
            for element in openTable:
                print(element.state)
            print()

            print("---closeTable---")
            for element in closeTable:
                print(element.state)
            print()

            n = openTable.pop(0)
            path = []
            if (n.state == n.answer).all():
                while n.parent and n.parent != originState:
                    path.append(n.parent)
                    n = n.parent
                path.reverse()
                if o is None:
                    o=path;
                else:
                    if len(o)>len(path):
                        o=path
                return path
            # 加入close
            closeTable.append(n)
            # 确定下一步点
            subStates = n.nextStep()

            openTable.extend(subStates)

            openTable.sort(key=compareNum)
        else:
            return None,None


def compareNum(state):
    return state.f


if __name__ == '__main__':
    originState = State(np.array([[2, 8, 3], [1, 6, 4], [7, 0, 5]]))
    State.answer = np.array([[1, 2, 3], [8, 0, 4], [7, 6, 5]])

    s = State(state=originState.state)
    path = s.solve()
    if path:
        for node in path:
            node.showInfo()
        print(State.answer)
        print("Total steps is %d" % len(path))


