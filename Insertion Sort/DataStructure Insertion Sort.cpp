#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &V, int N)
{
	for (int i = 1; i < N; ++i)
	{
		int num = V[i];
		int j = i-1;
		// if you want to sort accending just make > to <
		while (j >= 0 && V[j] > num)
		{
			V[j + 1] = V[j];
			j--;
		} 
		
		V[j+1] = num;
	}
}

void print(vector<int> V)
{
	for (auto i : V)
		cout << i << ' ';
}

int main()
{
	vector<int> V = { 1,4,2,62,6,8,23,12,643,3 };
	int N = V.size();

	InsertionSort(V, N);
	print(V);

}