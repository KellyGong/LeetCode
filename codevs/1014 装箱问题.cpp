#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int capacity;
int thingnum;

vector<int> thing;

int backvalue(vector<int> lists, int leftcap) {
    if (lists.size() == 0 || lists[0] > leftcap) return leftcap;
    vector<int> temp1 = lists;
    temp1.pop_back();
    int value1 = INT_MAX;
    int value2 = INT_MAX;
    if (leftcap - lists[lists.size() - 1] >= 0) {
        value1 = backvalue(temp1, leftcap - lists[lists.size() - 1]);
    }
    value2 = backvalue(temp1, leftcap);
    return min(value1, value2);
}

int main() {
    cin >> capacity;
    cin >> thingnum;
    int temp;
    for (int i = 0; i < thingnum; i++) {
        cin >> temp;
        thing.push_back(temp);
    }
    sort(thing.begin(), thing.end());
    int res = backvalue(thing, capacity);

    cout << res << endl;


    system("pause");
    return 0;
}