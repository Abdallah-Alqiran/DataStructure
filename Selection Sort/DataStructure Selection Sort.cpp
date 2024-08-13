#include <iostream>
#include <vector>

using namespace std;

void Swap(int &A, int &B)
{
	int temp = A;
	A = B;
	B = temp;
}

void SelectionSort(vector<int> &V, int N)
{
	for (int i = 0; i < N - 1; ++i)
	{
		int mn = i;

		for (int j = i + 1; j < N; ++j)
		{
			if (V[j] < V[mn])
			{
				mn = j;
			}
		}
		swap(V[i], V[mn]);
	}
}

void print(vector<int> V)
{
	cout << "The array after sorting descending = ";
	for (auto i : V)
		cout << i << ' ';
}

int main()
{
	int N;		cin >> N;
	vector<int> V(N);

	for (auto& i : V)
		cin >> i;

	SelectionSort(V, N);
	print(V);
}
