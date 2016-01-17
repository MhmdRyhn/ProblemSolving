#include<bits/stdc++.h>
using namespace std;
#define mx 1001

vector<int> primefact[mx];
int cost[mx];
bool isvisited[mx];

void factor(int n)
{
    int idx=n;

    for(int i=2; i<=(n/2); i++)
    {
        int cnt=0;
        while((n%i)==0)
            n/=i,cnt++;

        if(cnt)
            primefact[idx].push_back(i);
    }

    if(n!=idx and n>1)
        primefact[idx].push_back(n);
}



int bfs(int s,int t)
{
    memset(cost,0,sizeof cost);
    memset(isvisited,false,sizeof isvisited);

    queue<int> q;
    cost[s]=0;
    q.push(s);

    int u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        int len=primefact[u].size();
        for(int i=0; i<len; i++)
        {
            v=u+primefact[u][i];



            if(v<=t and !isvisited[v])
            {
                //printf("v: %d\n",v);
                q.push(v);
                cost[v]=cost[u]+1;
                isvisited[v]=true;
            }

            if(v==t)
                return cost[t];
        }
        //printf("\n");
    }

    //printf("cost[t]: %d\n",cost[t]);
    return cost[t];
}


int main()
{
    for(int i=2; i<mx; i++)
        primefact[i].clear(),factor(i);

//    for(int i=0;i<mx;i++)
//    {
//        printf("prime factors of %d are: ",i);
//        for(int j=0;j<primefact[i].size();j++)
//            printf("%d ",primefact[i][j]);
//        printf("\n");
//    }
//    printf("\n");

    int cs,s,t;
    scanf("%d",&cs);

    for(int i=1; cs--; i++)
    {
        scanf("%d%d",&s,&t);
        printf("Case %d: ",i);

        if(s>t)
        {
            printf("-1\n");
            continue;
        }

        if(s==t)
        {
            printf("0\n");
            continue;
        }


        int ans=bfs(s,t);
        if(ans)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }

    return 0;
}
