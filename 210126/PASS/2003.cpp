#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, M, tmp;
int start, ender, answer = 0;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	start = 0, ender = 0;

	while (true)
	{
		answer = 0;

		for (int i = start; i < ender; ++i)
		{
			answer += v[i];
		}

		if (answer < M)
		{
			ender++;
		}
		else if (answer == M)
		{
			cnt++;
			start++;
			ender++;
		}
		else
		{
			start++;
		}

		if (ender > N)
			break;
	}

	cout << cnt;

	return 0;
}