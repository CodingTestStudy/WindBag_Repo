#include <iostream>
#include <algorithm>

using namespace std;

int N, M, tmp;
int arr[100001];

int binary_search(int low, int high, int wanted)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == wanted) return 1;
		else if (arr[mid] < wanted)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return 0;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		arr[i] = tmp;
	}

	sort(arr, arr + N);

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> tmp;
		cout << binary_search(0, N - 1, tmp) << "\n";
	}


	return 0;
}