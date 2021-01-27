#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
string arr[10];

pair<int, char> point[26];
vector<pair<int, char>> v;
int sum = 0;

bool comp(pair<int, char> p1, pair<int, char> p2)
{
	return p1.first > p2.first;
}

int main()
{
	cin >> N;

	for (int i = 0; i < 26; ++i)
	{
		point[i].first = 0;
		point[i].second = 'A' + i;
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];

		int tmp = 1;
		for (int j = arr[i].size() - 1; 0 <= j; --j)
		{
			point[((char)arr[i][j] - 'A')].first += tmp;
			tmp *= 10;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (point[i].first != 0)
		{
			v.push_back(point[i]);
		}
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; ++i)
	{
		char number = 9;
		for (int j = 0; j < v.size(); ++j)
		{
			replace(arr[i].begin(), arr[i].end(), v[j].second, (char) (number + '0'));
			number--;
		}
		
		sum += stoi(arr[i]);
	}

	cout << sum;

	return 0;
}