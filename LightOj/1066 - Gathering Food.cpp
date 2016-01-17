#include<bits/stdc++.h>
using namespace std;
#define mx 11
#define xx first
#define yy second
#define pii pair<int,int>

int hor[]= {0,0,1,-1};
int ver[]= {1,-1,0,0};
int nowx,nowy;
char grid[mx][mx];
bool taken[26];
bool isvisited[mx][mx];
int cost[mx][mx];


int bfs(int xsrc,int ysrc,int n)
{
    memset(isvisited,false,sizeof isvisited);
    memset(cost,0,sizeof cost);
    char pos=grid[xsrc][ysrc];
    grid[xsrc][ysrc]='.';
    queue<pii> q;

    isvisited[xsrc][ysrc]=true;
    cost[xsrc][ysrc]=0;
    q.push({xsrc,ysrc});
    nowx=-1,nowy=-1;


    while(!q.empty())
    {
        pii from=q.front();
        int fx=from.xx,fy=from.yy;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int s=fx+hor[i],d=fy+ver[i];

            if(s>-1 and s<n and d>-1 and d<n
                    and grid[s][d]!='#' and
                    !isvisited[s][d])
            {
                isvisited[s][d]=true;
                cost[s][d]=cost[fx][fy]+1;

                if(grid[s][d]>='A' and grid[s][d]<='Z')
                {
                    if((grid[s][d]-1)==pos)
                    {
                        nowx=s,nowy=d;
                        return cost[s][d];
                    }
                    else
                        continue;
                }
                q.push({s,d});

            }
        }
    }

}



int main()
{
    //freopen("light.txt","r",stdin);

    int t,n;
    scanf("%d",&t);

    for(int i=1; t--; i++)
    {
        memset(taken,false,sizeof taken);
        scanf("%d",&n);
        int cntchar=-1;
        int xstart=-1,ystart=-1;


        for(int j=0; j<n; j++)
        {
            getchar();
            for(int k=0; k<n; k++)
            {
                scanf("%c",&grid[j][k]);
                if(grid[j][k]>='A' and grid[j][k]<='Z')
                {
                    cntchar++;
                    if(grid[j][k]=='A')
                        xstart=j,ystart=k;
                }
            }
        }


        printf("Case %d: ",i);
        if(cntchar<=0)
        {
            printf("0\n");
            continue;
        }
        if(xstart==-1 and ystart==-1)
        {
            printf("0\n");
            continue;
        }


        int cnt=1,ans=0;
        taken[0]=true;
        ans+=bfs(xstart,ystart,n);

        if(nowx<0 and nowy<0)
        {
            printf("Impossible\n");
            continue;
        }

        for(int k=1; k<cntchar; k++)
        {
            if(cnt<cntchar)
            {
                if(nowx!=-1 and nowy!=-1)
                {
                    ans+=bfs(nowx,nowy,n);
                    cnt++;
                }
                else
                {
                    printf("Impossible\n");
                    break;
                }
            }
        }
        if(nowx!=-1 and nowy!=-1)
            printf("%d\n",ans);

    }

    return 0;
}
