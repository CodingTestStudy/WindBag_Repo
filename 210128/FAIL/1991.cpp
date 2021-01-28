/*
1991 트리순회
주어진 입력으로 트리 정보를 받고 전위/중위/후위 순회 출력을 출력하는 문제
단 항상 A가 루트노드고 최대 26개를 입력받는 등 조건이 상냥하다.
*/

#include <iostream>

#define FOR(I, N) for (int I = 0; I < N; I++)

using namespace std;

char node[26][2], N, tmp, nl, nr;

void pre(char node_num)
{
	cout << node_num + 'A';
	if (node[node_num][0] != -1) pre(node[node_num][0]);
	if (node[node_num][1] != -1) pre(node[node_num][1]);

	return;
}

void in(char node_num)
{
	if (node[node_num][0] != -1) in(node[node_num][0]);
	cout << node_num + 'A';
	if (node[node_num][1] != -1) in(node[node_num][1]);

	return;
}

void post(char node_num)
{
	if (node[node_num][0] != -1) post(node[node_num][0]);
	if (node[node_num][1] != -1) post(node[node_num][1]);
	cout << node_num + 'A';

	return;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp >> nl >> nr;

		cout << i;

		if (nl == '.')
			node[tmp - 'A'][0] = -1;
		else
			node[tmp - 'A'][0] = nl - 'A';

		if(nr == '.')
			node[tmp - 'A'][1] = -1;
		else
			node[tmp - 'A'][1] = nr - 'A';
	}

	cout << "for end";

	pre(0);
	in(0);
	post(0);

	return 0;
}