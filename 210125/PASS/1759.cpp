#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
char ch[15], ans[16], tmp;
bool selected[15];

int num_of_m;
int total;

void work(int cur, int start, int end)
{
	if (cur == L)
	{
		int z = 0, m = 0;

		for (int j = 0; j < L; ++j)
		{
			if (ans[j] == 'a' || ans[j] == 'e' || ans[j] == 'i' || ans[j] == 'o' || ans[j] == 'u')
				m++;
			else
				z++;
		}

		if (z > 1 && m > 0)
		{
			ans[L + 1] = '\0';
			cout << ans << "\n";
			return;
		}
		else
		{
			return;
		}
	}
	else
	{
		for (int i = start; i < end; ++i)
		{
			ans[cur] = ch[i];
			work(cur + 1, i + 1, end);
			ans[cur] = 0; // 사실 의미 없음	
		}
	}
	
}

int main()
{
	cin >> L;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> tmp;
		ch[i] = tmp;
	}

	sort(ch, ch + C);

	work(0, 0, C);

	return 0;
}