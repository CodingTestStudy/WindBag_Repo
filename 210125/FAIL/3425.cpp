#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool isError;
	stack<long long> stk;

	string s;
	vector<string> commands;
	vector<int> numbers;

	while (true)
	{
		commands.clear();
		numbers.clear();

		while (true)
		{
			getline(cin, s);

			if (s == "" || s == "\n")
				continue;

			if (s == "END" || s == "QUIT")
				break;
			
			commands.push_back(s);
		}

		if (s == "QUIT")
			break;
		
		int N, tmp;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			numbers.push_back(tmp);
		}

		for (int i = 0; i < numbers.size(); i++)
		{
			isError = false;
			while (!stk.empty())
			{
				stk.pop();
			}

			stk.push(numbers[i]);

			for (vector<string>::iterator iter = commands.begin(); iter != commands.end(); iter++)
			{
				string tmps = *iter;

				if (tmps.length() > 3)
				{
					stk.push(stoi(tmps.substr(4)));
				}
				else if (tmps == "POP")
				{
					if (!stk.empty())
					{
						isError = true;
						break;
					}

					stk.pop();
				}
				else if (tmps == "INV")
				{
					if (stk.size() == 0)
					{
						isError = true;
						break;
					}
					else
					{
						long long tmp = stk.top();
						stk.pop();
						stk.push(-tmp);
					}
				}
				else if (tmps == "DUP")
				{
					if (stk.size() == 0)
					{
						isError = true;
						break;
					}
					stk.push(stk.top());
				}
				else if (tmps == "SWP")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();
					long long tmp2 = stk.top();
					stk.pop();
					stk.push(tmp2);
					stk.push(tmp1);
				}
				else if (tmps == "ADD")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();
					long long tmp2 = stk.top();
					stk.pop();
					if (labs(tmp1 + tmp2) > 1000000000)
					{
						isError = true;
						break;
					}
					stk.push(tmp1 + tmp2);
				}
				else if (tmps == "SUB")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();
					long long tmp2 = stk.top();
					stk.pop();

					if (labs(tmp2 - tmp1) > 1000000000)
					{
						isError = true;
						break;
					}
					stk.push(tmp2 - tmp1);
				}
				else if (tmps == "MUL")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();
					long long tmp2 = stk.top();
					stk.pop();

					if (labs(tmp2 * tmp1) > 1000000000)
					{
						isError = true;
						break;
					}

					stk.push(tmp2 * tmp1);
				}
				else if (tmps == "DIV")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();

					if (tmp1 == 0)
					{
						isError = true;
						break;
					}

					long long tmp2 = stk.top();
					stk.pop();
					stk.push(tmp2 / tmp1);
				}
				else if (tmps == "MOD")
				{
					if (stk.size() < 2)
					{
						isError = true;
						break;
					}
					long long tmp1 = stk.top();
					stk.pop();

					if (tmp1 == 0)
					{
						isError = true;
						break;
					}

					long long tmp2 = stk.top();
					stk.pop();
					if (tmp1 > 0)
						stk.push(labs(tmp2) % labs(tmp1));
					else
						stk.push(-(labs(tmp2) % labs(tmp1)));
				}
			}

			if (stk.size() != 1)
				isError = true;

			if (isError)
				cout << "ERROR\n";
			else
				cout << stk.top() << "\n";
		}

		cout << "\n";
	}
	
	return 0;
}