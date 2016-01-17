#include<bits/stdc++.h>
using namespace std;
#define mx 20
#define pii pair<int,int>
#define newline printf("\n")

int hr[]= {0,1,-1,0};
int down[]= {1,0,0,-1};
char grid[mx][mx];
bool isvisited[mx][mx];
int cost[mx][mx];
int dx,dy,m,n;

void bfs(int a,int b)
{
    memset(isvisited,false,sizeof isvisited);
    memset(cost,0,sizeof cost);
    int x,y;
    queue<pii> q;
    isvisited[a][b]=true;
    cost[a][b]=0;
    q.push({a,b});

    while(!q.empty())
    {
        pii u=q.front();
        x=u.first,y=u.second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int s=x+hr[i],d=y+down[i];

            if(s>-1 and s<m and
                    d>-1 and d<n and
                    !isvisited[s][d])
            {

                if(grid[s][d]=='m' or grid[s][d]=='#')
                    continue;

                q.push({s,d});
                isvisited[s][d]=true;
                cost[s][d]=cost[x][y]+1;

            }
        }
    }
}


int main()
{
    int t,x1,y1,x2,y2,x3,y3;
    char c;

    scanf("%d",&t);

    for(int i=1; t--; i++)
    {
        scanf("%d%d",&m,&n);

        for(int k=0; k<m; k++)
        {
            getchar();
            for(int j=0; j<n; j++)
            {
                scanf("%c",&grid[k][j]);


                if(grid[k][j]=='a')
                    x1=k,y1=j;
                else if(grid[k][j]=='b')
                    x2=k,y2=j;
                else if(grid[k][j]=='c')
                    x3=k,y3=j;
                else if(grid[k][j]=='h')
                    dx=k,dy=j;
            }
        }

        int ans=0;
        bfs(x1,y1);
        ans=max(ans,cost[dx][dy]);
        bfs(x2,y2);
        ans=max(ans,cost[dx][dy]);
        bfs(x3,y3);
        ans=max(ans,cost[dx][dy]);

        printf("Case %d: %d\n",i,ans);
    }


    return 0;
}
