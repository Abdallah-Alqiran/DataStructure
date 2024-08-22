#include <iostream>
#include <vector>

using namespace std;

void merge(int l, int r, int md, vector<int> &V)
{
	vector<int> temp;

	int low = l;
	int high = md + 1; 

	while (low <= md && high <= r)
	{
		if (V[low] > V[high])
		{
			temp.push_back(V[high]);
			high++;
		}
		else
		{
			temp.push_back(V[low]);
			low++;
		}
	}

	while (low <= md)
	{
		temp.push_back(V[low]);
		low++;
	}

	while (high <= r)
	{
		temp.push_back(V[high]);
		high++;
	}

	for (int i = l, j = 0; i <= r; ++i, ++j)
	{
		V[i] = temp[j];
	}
}

void print(vector<int> V)
{
	for (auto i : V)
		cout << i << ' ';
}


void mergeSort(int l, int r, vector<int> &V)
{
	if (r > l)
	{
		int md = l + (r - l) / 2;
		mergeSort(l,md,V);
		mergeSort(md + 1, r, V);

		merge(l,r,md,V);
	}
}


int main()
{
	int N;		cin >> N;
	vector<int> V(N);

	for (auto& i : V)
		cin >> i;

	mergeSort(0,N-1,V);
	print(V);

}

