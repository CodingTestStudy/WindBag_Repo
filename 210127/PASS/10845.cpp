#include <iostream>
#include <string>

#define MAXL	 20001

using namespace std;

class queue
{
private:
	int queue_s[MAXL];
public:
	int start;
	int end;

	queue()
	{
		start = 0;
		end = 0;
	}
	void push(int X)
	{
		queue_s[end % (MAXL + 1)] = X;
		end++;
	}

	void pop()
	{
		if (end - start)
		{
			cout << queue_s[start % (MAXL + 1)] << "\n";
			start++;
		}
		else
		{
			cout << -1 << "\n";
		}
	}

	void size()
	{
		cout << end - start << "\n";
	}

	void empty()
	{
		if (end - start)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << 1 << "\n";
		}
	}

	void front()
	{
		if (end - start)
		{
			cout << queue_s[start % (MAXL + 1)] << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}

	void back()
	{
		if (end - start)
		{
			cout << queue_s[(end - 1) % (MAXL + 1)] << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
};

int N;
string str;

int main()
{
	cin >> N;

	queue stk;

	getchar();

	for (int i = 0; i < N; i++)
	{
		getline(cin, str);

		if (str.rfind("push") == 0)
		{
			stk.push(stoi(str.substr(5)));
		}
		else if (str == "pop")
		{
			stk.pop();
		}
		else if (str == "size")
		{
			stk.size();
		}
		else if (str == "empty")
		{
			stk.empty();
		}
		else if (str == "front")
		{
			stk.front();
		}
		else if (str == "back")
		{
			stk.back();
		}
	}

	return 0;
}