#include <iostream>
#include <algorithm>

#define MAX		2000000000

typedef long long ll;

using namespace std;

ll X, Y, Z;

int binary_search_win(ll start, ll end)
{
	ll mid;

	while (end >= start)
	{
		mid = (end + start) / 2;
		if ((ll) 100 * (Y + (mid - X)) / mid == Z)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	if (start > MAX)
		return -1;

	return start - X;
}

int main()
{
	cin >> X >> Y;

	Z = (ll) 100 * Y / X;

	cout << binary_search_win(X, MAX);
	
	return 0;
}