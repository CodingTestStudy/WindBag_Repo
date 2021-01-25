#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int R, C;

int map[50][50];
int flood[50][50];
int hedge[50][50];
int c;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int sx, sy, desx, desy;

vector<pair<int, int>> v;

int main()
{
	cin >> R;
	cin >> C;

	getchar();

	for (int y = 0; y < R; ++y)
	{
		for (int x = 0; x < C; ++x)
		{
			c = getchar();
			map[x][y] = c;

			if (c == '*')
			{
				v.push_back(pair<int, int>(x, y));
			}

			else if (c == 'S')
			{
				sx = x, sy = y;
			}

			else if (c == 'D')
			{
				desx = x, desy = y;
			}
		}
		getchar();
	}

	// water_bfs
	for (int i = 0; i < v.size(); ++i)
	{
		queue<pair<int, int>> q;
		q.push(pair<int, int>(v[i].first, v[i].second));

		while (!q.empty())
		{
			int x = q.front().first, y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j], ny = y + dy[j];

				if (!(nx < 0 || nx >= C || ny < 0 || ny >= R) && (map[nx][ny] == '.'))
				{
					if (flood[nx][ny] == 0 || flood[nx][ny] > flood[x][y] + 1)
					{
						flood[nx][ny] = flood[x][y] + 1;
						q.push(pair<int, int>(nx, ny));
					}
				}
			}
		}
	}

	// 고슴도치 bfs
	queue<pair<int, int>> q;
	q.push(pair<int, int>(sx, sy));

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int j = 0; j < 4; ++j)
		{
			int nx = x + dx[j], ny = y + dy[j];

			if (!(nx < 0 || nx >= C || ny < 0 || ny >= R) && (map[nx][ny] == '.' || map[nx][ny] == 'D'))
			{
				if ((flood[nx][ny] > hedge[x][y] + 1) || flood[nx][ny] == 0)
				{
					if (hedge[nx][ny] == 0)
					{
						hedge[nx][ny] = hedge[x][y] + 1;
						q.push(pair<int, int>(nx, ny));
					}
				}
			}
		}
	}

	if (hedge[desx][desy])
	{
		cout << hedge[desx][desy];
	}
	else
	{
		cout << "KAKTUS";
	}

	return 0;
}