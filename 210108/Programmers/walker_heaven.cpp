#include <vector>
#include <utility>

using namespace std;

int MOD = 20170805;

int M, N;

void distribute(int x, int y, vector<vector<int>> &city_map, vector<vector<pair<int, int>>> &map)
{
    int val = city_map[x][y];

    switch(val)
    {
        case 0 :
            if (x + 1 < M)
                map[x + 1][y].first += map[x][y].second % MOD;
            if (y + 1 < N)
                map[x][y + 1].second += map[x][y].first % MOD;
        case 2 :
            if (x + 1 < M)
                map[x + 1][y].first += map[x][y].first % MOD;
            if (y + 1 < N)
                map[x][y + 1].second += map[x][y].second % MOD;
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<pair<int, int>>> map(m, vector<pair<int, int>>(n, pair<int, int>(0, 0)));

    M = m;
    N = n;

    map[0][0].first = 1;
    
    int x_pivot = 0, y_pivot = 0;

    while(y_pivot < n)
    {
        int cnt = 0;
        while(0 <= y_pivot - cnt && cnt < m)
        {
            distribute(cnt, y_pivot - cnt, city_map, map);
            cnt++;
        }
        y_pivot++;
    }

    while(x_pivot < m)
    {
        int cnt = 0;
        while(0 <= y_pivot - cnt && x_pivot + cnt < m)
        {
            distribute(x_pivot + cnt, y_pivot - cnt, city_map, map);
            cnt++;
        }
        x_pivot++;
    }
    
    return (map[m-1][n-1].first + map[m-1][n-1].second) % MOD;
}