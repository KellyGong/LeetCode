#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define ONLINE_JUDGE
using namespace std;

int StartNode;
int EndNode;

int stationNum = 0;
unordered_map<int, int> m;
vector<int> station[1000];

int bfs(int S, int T, vector<vector<int>>& routes) {
    queue<int> q;
    unordered_set<int> s;   //表示所有已经访问过的站点
    q.push(S);
    int time = 0;
    queue<int> temp;
    while (!q.empty() || !temp.empty()) {
        int frontnode = q.front();
        q.pop();
        s.insert(frontnode);
        if (frontnode == T) return time;
        


        for (int i = 0; i < station[frontnode].size(); i++) {
            for (int j = 0; j < routes[station[frontnode][i]].size(); j++) {
                if (s.count(m[routes[station[frontnode][i]][j]]) == 0) {
                    temp.push(m[routes[station[frontnode][i]][j]]);
                }
            }
        }

        if (q.empty() && !temp.empty()) {
            time++;
            swap(q, temp);
            
        }
    }
}

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            if (m.count(routes[i][j]) == 0) {
                m[routes[i][j]] = stationNum;
                stationNum++;
            }
            station[m[routes[i][j]]].push_back(i);
        }
    }
    if (m.count(S) == 0 || m.count(T) == 0) return -1;

    return bfs(m[S], m[T], routes);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
#endif
    vector<vector<int>> input = { {1, 2, 7}, {3, 6, 7} };
    StartNode = 1;
    EndNode = 6;

    int res = numBusesToDestination(input, StartNode, EndNode);

    cout << res << endl;

    system("pause");
    return 0;
}