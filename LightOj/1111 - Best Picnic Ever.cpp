#include<bits/stdc++.h>
using namespace std;
#define mx 1001

vector<int> graph[101];
bool isvisited[mx];
int cost[mx];

void dfs(int src)
{
    memset(isvisited,false,sizeof isvisited);
    stack<int> stk;

    stk.push(src);
    isvisited[src]=true;
    cost[src]++;

    while(!stk.empty())
    {
        int s=stk.top();
        stk.pop();

        int len=graph[s].size();
        for(int i=0;i<len;i++)
        {
            if(!isvisited[graph[s][i]])
            {
                stk.push(graph[s][i]);
                cost[graph[s][i]]++;
                isvisited[graph[s][i]]=true;
            }
        }
    }

}


int main()
{
    int t,k,n,m,u,v;
    int man[101];
    scanf("%d",&t);

    for(int i=1;t--;i++)
    {
        memset(cost,0,sizeof cost);
        scanf("%d%d%d",&k,&n,&m);
        for(int j=1;j<=k;j++)
            scanf("%d",&man[j]);

        for(int j=1;j<=m;j++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }

        for(int j=1;j<=k;j++)
            dfs(man[j]);

        int ans=0;
        for(int j=1;j<=n;j++){
                graph[j].clear();
            if(cost[j]==k)
            ans++;
        }

//        for(int j=1;j<=n;j++)
//            printf("%d ",cost[j]);
//        printf("\n");

        printf("Case %d: %d\n",i,ans);
    }



    return 0;
}
