/*
作者:KellyGong
题目:p2596 售货员的难题
*/

#include<cstdio>

int n;

int s[20][20];

int x,cnt = 15000;

int vis[20];

void dfs(int a,int cur)

{

       if(x >= cnt) return;

       if(cur == n)

       {

              if(x + s[a][1] < cnt) cnt = x + s[a][1];

       }

       else for(int i = 1;i <= n;i++)

       {

              if(!vis[i])

              {

                   if(x + s[a][i] >= cnt) return;

                     vis[i] = 1;

                     x+= s[a][i];

                     dfs(i,cur + 1);

                     x-= s[a][i];

                     vis[i] = 0;

              }

       }

}

int main()

{

       scanf("%d",&n);

       for(int i = 1;i <= n;i++)

    for(int j = 1;j <= n;j++)scanf("%d",&s[i][j]);

       vis[1] = 1;

       dfs(1,1);

       printf("%d",cnt);

       return 0;

}