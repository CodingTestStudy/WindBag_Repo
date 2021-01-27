#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M, tmp;
int min_dist = 1234567890;

int map[50][50];
vector<pii> home, store, candidate;
int home_size, candidate_size;

void get_distance()
{
	candidate_size = candidate.size();

	int tmp_sum = 0;
	int tmp_dis;
	for (int i = 0; i < home_size; ++i)
	{
		tmp_dis = 1234567890;
		for (int j = 0; j < candidate_size; ++j)
		{
			tmp_dis = min(tmp_dis, abs(home[i].first - candidate[j].first) + abs(home[i].second - candidate[j].second));
		}
		tmp_sum += tmp_dis;
		if (tmp_sum > min_dist)	return;
	}

	if (min_dist > tmp_sum)
		min_dist = tmp_sum;

	return;
}

void select(int start, int end, int remain)
{
	if (remain == 0)
	{
		get_distance();
		return;
	}

	for (int i = start; i < end; ++i)
	{
		candidate.push_back(store[i]);
		select(i + 1, end, remain - 1);
		candidate.pop_back();
	}

	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			cin >> tmp;
			map[y][x] = tmp;

			if (tmp == 1)
				home.push_back(make_pair(x, y));
			else if (tmp == 2)
				store.push_back(make_pair(x, y));
		}
	}

	home_size = home.size();

	select(0, store.size(), M);

	cout << min_dist;

	return 0;
}