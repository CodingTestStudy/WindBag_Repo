#include <iostream>

using namespace std;

int N;
int cnt = 0;

int qloc[15];

bool calc(int row)
{
	bool isGood = true;

	for (int i = 0; i < row; ++i)
	{
		if (qloc[i] == qloc[row] || (row - i) == qloc[i] - qloc[row] || (row - i) == qloc[row] - qloc[i])
		{
			isGood = false;
			break;
		}
	}

	return isGood;
}

void test(int row)
{
	if (row == N)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			qloc[row] = i;
			if (calc(row))
			{
				test(row + 1);
			}
			qloc[row] = 0;
		}
	}
}

int main()
{
	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	
	test(0);

	cout << cnt;

	return 0;
}