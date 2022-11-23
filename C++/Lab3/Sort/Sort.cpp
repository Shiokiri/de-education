#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<fstream>
#include<algorithm>
using namespace std;

constexpr int N = 30000;
int a[N+5];

template<typename T>
void quickSort(int l, int r, T arr[])
{
	int i = l, j = r;
	T mid = arr[(l + r) / 2];
	do {
		while (arr[i] < mid) i++;
		while (arr[j] > mid) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j) quickSort(l, j, arr);
	if (i < r) quickSort(i, r, arr);
}

template<typename T>
void bubbleSort(int l, int r, T arr[]) {
	for (int i = l; i <= r - 1; i++)
		for (int j = l; j <= r - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}
int main()
{
	srand(time(0));
	ofstream outp1("random.txt");
	for (int i = 1; i <= N; i++) outp1 << rand() << " ";
	outp1.close();
	ifstream re("random.txt");
	for (int i = 1; i <= N; i++) re >> a[i];
	re.close();
	cout << "请输入：1.快速排序 2.冒泡排序" << endl;
	char c = getchar();
	if (c == '1')
	{
		clock_t  t = clock();
		quickSort(1, N, a);
		ofstream outp2("quickSort.txt");
		for (int i = 1; i <= N; i++) outp2 << a[i] << " ";
		outp2.close();
		cout << "用时：" << ((double)clock() - t) / CLOCKS_PER_SEC << "s" << endl;
	}
		
	else if (c == '2')
	{
		clock_t  t = clock();
		bubbleSort(1, N, a);
		ofstream outp2("bubbleSort.txt");
		for (int i = 1; i <= N; i++) outp2 << a[i] << " ";
		outp2.close();
		cout << "用时：" << ((double)clock() - t) / CLOCKS_PER_SEC << "s" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
		return 0;
	}
	return 0;
}
