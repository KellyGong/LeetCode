#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int nums;

int city[102][102];
int rep[102];    //代表元，代表元相同说明是同一个树中，代表元为树中最小的元素

typedef struct EDGE {
    int startnode;
    int endnode;
    int weight;

    friend bool operator < (EDGE e, EDGE c) {
        return e.weight < c.weight;
    }

}EDGE;

vector<EDGE> edge;
vector<EDGE> result;

int main() {
    cin >> nums;
    
    for (int i = 1; i <= nums; i++) {
        rep[i] = i;
    }

    char a;
    for (int i = 1; i <= nums; i++) {
        for (int j = 1; j <= nums; j++) {
            cin >> city[i][j];
            if (city[i][j] != 0 && i < j) {
                EDGE temp;
                temp.startnode = i;
                temp.endnode = j;
                temp.weight = city[i][j];
                edge.push_back(temp);
            }
            if (city[i][j] == 0) {
                if (j < i) {
                    int temp = j;
                    while (rep[temp] != temp) {
                        temp = rep[temp];
                    }
                    rep[i] = temp;
                }
            }
        }      
    }
    
    sort(edge.begin(), edge.end());
    
    int res = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (rep[edge[i].startnode] != rep[edge[i].endnode]) {
            result.push_back(edge[i]);
            res += edge[i].weight;
            if (rep[edge[i].startnode] < rep[edge[i].endnode]) {
                int replace = rep[edge[i].endnode];
                int next = rep[edge[i].startnode];
                for (int j = 1; j <= nums; j++) {
                    if (rep[j] == replace) rep[j] = next;
                }
            }
            else if (rep[edge[i].startnode] > rep[edge[i].endnode]) {
                int replace = rep[edge[i].startnode];
                int next = rep[edge[i].endnode];
                for (int j = 1; j <= nums; j++) {
                    if (rep[j] == replace) rep[j] = next;
                }
            }
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].startnode << " " << result[i].endnode << endl;
    }
    cout << res << endl;

    system("pause");
    return 0;
}