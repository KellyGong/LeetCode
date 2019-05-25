#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int nums;

int city[102][102];
int res = 0;
int cost[102];
int parent[102];
int visit[102];

typedef struct EDGE {
    int startnode;
    int endnode;
    int weight;

    friend bool operator < (EDGE e, EDGE c) {
        return e.weight < c.weight;
    }

}EDGE;

vector<EDGE> result;

void  prim() {
    //从结点1开始搜索
    visit[1] = 1;
    for (int i = 1; i <= nums; i++) {
        cost[i] = city[1][i];
        parent[i] = 1;
    }

    //从当前代价最小点出发
    int index;
    for (int i = 1; i < nums; i++) {
        //总计需要搜索nums - 1个点

        int minn = 10000000;

        for (int j = 1; j <= nums; j++) {
            if (!visit[j] && minn > cost[j]) {
                index = j;
            }
        }

        visit[index] = 1;

        if (minn > 0) {
            //此时表示该边是还未连上的边
            if (parent[index] > index) {
                result.push_back({ index, parent[index], city[index][parent[index]] });
            }
            else {
                result.push_back({ parent[index], index, city[index][parent[index]] });
            }

            for (int j = 1; j <= nums; j++) {
                if (!visit[j] && cost[j] > city[index][j]) {
                    cost[j] = city[index][j];
                    parent[j] = index;
                }
            }

        }

    }

}

int main() {
    cin >> nums;
    
    for (int i = 1; i <= nums; i++) {
        for (int j = 1; j <= nums; j++) {
            cin >> city[i][j];
        }      
    }
    
      
    prim();
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].startnode << " " << result[i].endnode << endl;
        res += result[i].weight;
    }
    cout << res << endl;

    system("pause");
    return 0;
}