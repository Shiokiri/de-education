#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

constexpr int N = 20;
int a[N + 5];
double b[N + 5];

template<typename T>
void SelectionSort(int l, int r, T arr[])
{
	for (int i = l; i <= r; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j <= r; j++)
			if (arr[j] < arr[min_pos])
				min_pos = j;
		std::swap(arr[i], arr[min_pos]);
	}
}

int main()
{
	srand(time(0));
	for (int i = 1; i <= N; i++) a[i] = rand() % 100;
	for (int i = 1; i <= N; i++) b[i] = (double)(rand()) / 100;
	cout << "int data items in original order" << endl;
	for (int i = 1; i <= N; i++) cout << a[i] << " ";
	cout << endl;
	cout << "int data items in ascending order" << endl;
	SelectionSort(1, N, a);
	for (int i = 1; i <= N; i++) cout << a[i] << " ";
	cout << endl;
	cout << "double data items in original order" << endl;
	for (int i = 1; i <= N; i++) cout << b[i] << " ";
	cout << endl;
	cout << "double data items in ascending order" << endl;
	SelectionSort(1, N, b);
	for (int i = 1; i <= N; i++) cout << b[i] << " ";
	cout << endl;
}