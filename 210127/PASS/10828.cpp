#include <iostream>
#include <string>

using namespace std;

class stack 
{
private :
	int stack_s[10001];
public :
	int length;

	stack()
	{
		length = 0;
	}
	void push(int X)
	{
		stack_s[length] = X;
		length++;
	}

	void pop()
	{
		if (length)
		{
			cout << stack_s[length - 1] << "\n";
			length--;
		}
		else
		{
			cout << -1 << "\n";
		}
	}

	void size()
	{
		cout << length << "\n";
	}

	void empty()
	{
		if (length)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << 1 << "\n";
		}
	}

	void top()
	{
		if (length)
		{
			cout << stack_s[length - 1] << "\n";
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

	stack stk;

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
		else if (str == "top")
		{
			stk.top();
		}
	}

	return 0;
}