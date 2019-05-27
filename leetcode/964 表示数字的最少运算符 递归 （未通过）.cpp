#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#define ONLINE_JUDGE
using namespace std;


const double eps = 0.00001;
deque<double> q;

bool dfs(double target) {
    if (q.size() == 1) {
        if (fabs(target - q.front()) < eps) return true;
        else return false;
    }
    //+
    double temp2;
    double temp = q.front();
    q.pop_front();
    bool exp1 = dfs(target - temp);
    q.push_front(temp);

    //-
    temp = q.front();
    q.pop_front();
    bool exp2 = dfs(temp - target);
    q.push_front(temp);
    
    //*
    temp = q.front();
    q.pop_front();
    temp2 = q.front();
    q.pop_front();
    q.push_front(temp * temp2);
    bool exp3 = dfs(target);
    q.pop_front();
    q.push_front(temp2);
    q.push_front(temp);

    // /
    temp = q.front();
    q.pop_front();
    temp2 = q.front();
    q.pop_front();
    q.push_front(temp / temp2);
    bool exp4 = dfs(target);
    q.pop_front();
    q.push_front(temp2);
    q.push_front(temp);

    return exp1 || exp2 || exp3 || exp4;
}

bool deal(int count, int x, int target) {
    while (!q.empty())q.pop_back();

    for (int i = 0; i < count; i++) {
        q.push_back((double)x);
    }

    return dfs((double)target);
}

int leastOpsExpressTarget(int x, int target) {
    int i = 1;
    while (1) {
        if (deal(i, x, target)) break;
        i++;
    }
    return i;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
#endif
    int res = leastOpsExpressTarget(5, 501);

    cout << res - 1 << endl;

    system("pause");
    return 0;
}