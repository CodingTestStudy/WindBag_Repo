#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, tmp, order = 1;

int cand[30][3];

int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp;

		bool voted = false;

		// find cand
		for (int j = 0; j < N; j++)
		{
			if (cand[j][0] == tmp)
			{
				cand[j][1]++;
				voted = true;

				break;
			}
		}

		if (voted)
			continue;

		bool isFull = true;

		for (int j = 0; j < N; j++)
		{
			if (cand[j][0] == 0)
			{
				cand[j][0] = tmp;
				cand[j][1] = 1;

				cand[j][2] = order;
				order++;

				isFull = false;
				break;
			}
		}

		if (isFull)
		{
			int max = 1024;
			int index = -1;
			int cnt = 1;

			for (int j = 0; j < N; j++)
			{
				if (cand[j][1] < max)
				{
					max = cand[j][1];
					index = j;
					cnt = 1;
				}
				else if (cand[j][1] == max)
				{
					cnt++;
				}
			}

			// check there're more than one
			if (cnt > 1)
			{
				int oldest = 1000;

				for (int j = 0; j < N; j++)
				{
					if (cand[j][1] == max && cand[j][2] < oldest)
					{
						oldest = cand[j][2];
						index = j;
					}
				}

				cand[index][0] = tmp;
				cand[index][1] = 1;

				cand[index][2] = order;
				order++;
			}
			else
			{
				cand[index][0] = tmp;
				cand[index][1] = 1;

				cand[index][2] = order;
				order++;
			}

		}
	}

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		v.push_back(cand[i][0]);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}