#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 101
#define x first
#define y second

vector<int> graph[mx];
int cost[mx][mx];
bool isvisited[mx];


int bfs(int src,int ad)
{
    int cst=0,from,to;

    queue<int> q;
    isvisited[src]=true;

//    printf("src: %d\n",src);
//    printf("srcad: %d\n",graph[src][ad]);

    to=graph[src][ad];

    cst+=cost[src][to];

    q.push(to);
    isvisited[to]=true;

    int d=cost[src][to];

//    printf("from: %d to: %d--> ",src,to);
//    printf("%d\n",d);

    while(!q.empty())
    {
        from=q.front();
        q.pop();

        if(!isvisited[graph[from][0]])
        {
            to=graph[from][0];

            cst+=cost[from][to];
            isvisited[to]=true;
            q.push(to);

//            printf("from: %d to: %d--> ",from,to);
//            printf("%d\n",cost[from][to]);
        }
        else if(!isvisited[graph[from][1]])
        {
            to=graph[from][1];

            cst+=cost[from][to];
            isvisited[to]=true;
            q.push(to);

//            printf("from: %d to: %d--> ",from,to);
//            printf("%d\n",cost[from][to]);
        }
    }

    cst+=cost[from][src];
//    printf("from: %d to: %d--> ",from,src);
//    printf("%d\n",cost[from][src]);
//
//    printf("Cost: %d\n",cst);

    return cst;
}




int main()
{
    //freopen("light.txt","r",stdin);

    int t,a,b,c,n;

    scanf("%d",&t);

    for(int i=1; t--; i++)
    {
        memset(cost,0,sizeof cost);
        scanf("%d",&n);

        for(int k=0; k<n; k++)
        {
            scanf("%d%d%d",&a,&b,&c);
            graph[a].push_back(b);
            graph[b].push_back(a);
            cost[a][b]=0;
            cost[b][a]=c;
        }

//        for(int j=1;j<=n;j++)
//        {
//            for(int k=1;k<=n;k++)
//                printf("%d ",cost[j][k]);
//            printf("\n");
//        }
//        printf("\n\n");

        int ans=1e9;
        memset(isvisited,false,sizeof isvisited);
        int x=bfs(1,0);
        ans=min(ans,x);
//            printf("x1: %d\n",x);

        memset(isvisited,false,sizeof isvisited);
        x=bfs(1,1);
        ans=min(ans,x);

//            printf("x2: %d\n",x);
//            printf("\n\n");


        printf("Case %d: %d\n",i,ans);

        for(int k=1; k<=n; k++)
            graph[k].clear();

    }
}
