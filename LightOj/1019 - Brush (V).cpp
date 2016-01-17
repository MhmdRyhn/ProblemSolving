#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mx 101
#define pii pair<ll,ll>
#define xx first
#define yy second
#define inf 1000005

vector<pii> graph[mx];
ll cost[mx];

void dijkstra(ll src)
{
    memset(cost,inf,sizeof cost);
    priority_queue<pii,vector<pii>, greater<pii> > pq;

    cost[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        pii f=pq.top();
        pq.pop();
        ll w=f.xx,u=f.yy;

        if(w>cost[u])
            continue;

        ll len=graph[u].size();
        for(ll i=0;i<len;i++)
        {
            pii v=graph[u][i];
            if((cost[u]+v.xx)<cost[v.yy])
            {
                cost[v.yy]=cost[u]+v.xx;
                pq.push({v.xx,v.yy});
            }
        }
    }

}

void clean(ll n)
{
    for(ll i=1;i<=n;i++)
        graph[i].clear();
}


int main()
{
    ll t,n,m,u,v,w;

    scanf("%lld",&t);

    for(ll i=1;t--;i++)
    {
        scanf("%lld%lld",&n,&m);
        for(ll k=0;k<m;k++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }


        printf("Case %lld: ",i);
        if(m==1){
            printf("Impossible\n");
            continue;
        }

        dijkstra(1);
        if(cost[n]<inf)
            printf("%lld\n",cost[n]);
        else
            printf("Impossible\n");
        clean(n);
    }


    return 0;
}
