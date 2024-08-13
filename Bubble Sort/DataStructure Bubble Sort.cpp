#include <iostream>

using namespace std;

int arr[] = {3,4,6,1,6,10,23,12,4,3,2};

// descending Bubble sort
void BubbleSort(int arr[], int N)
{
	for (int i = 0; i < N - 1; ++i)
	{
		bool check = true;
		for (int j = 0; j < N - 1 - i; ++j)
		{
			// if you make > to < you will sort accending
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				check = false;
			}
		}
		if (check)
			break;
	}
}

void print(int arr[], int N)
{
	cout << "The array after sorting decsending\n";
	for (int i = 0; i < N; ++i)
		cout << arr[i] << ' ';
}

int main()
{
	int N = sizeof(arr) / sizeof(arr[0]);
	

	BubbleSort(arr, N);
	print(arr, N);
}

