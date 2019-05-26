/*
作者:KellyGong
题目:p1159 最大全0子矩阵
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int pointnum;

int point[2100][2100];
int h[2100];
int l[2100];
int r[2100];

int res = 0;

int main() {
    scanf("%d", &pointnum);
    
    for (int i = 0; i < pointnum; i++) {
        for (int j = 0; j < pointnum; j++) {
            scanf("%d", &point[i][j]);
        }
    }

    for (int i = 0; i < pointnum; i++) {
        for (int j = 0; j < pointnum; j++) {
            if (point[i][j] == 0) h[j]++;
            else h[j] = 0;
        }

        for (int j = 0; j < pointnum; j++) {
            l[j] = j;
            while (l[j] - 1 >= 0 && h[l[j] - 1] >= h[j]) l[j] = l[j] - 1;
        }

        for (int j = pointnum - 1; j >= 0; j--) {
            r[j] = j;
            while (r[j] + 1 < pointnum && h[r[j] + 1] >= h[j]) r[j] = r[j] + 1;
        }

        for (int j = 0; j < pointnum; j++) {
            res = max(res, h[j] * (r[j] - l[j] + 1));
        }

    }
    cout << res << endl;
  
    return 0;
}