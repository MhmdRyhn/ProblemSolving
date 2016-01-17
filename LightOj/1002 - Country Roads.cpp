#include<bits/stdc++.h>
using namespace std;

#define mx 500
#define ll long long
#define pii pair<ll,ll>
#define vpair vector<pii>
#define inf 2e4+1
#define xx first
#define yy second

//const ll inf=2e10;

vector<pii> graph[mx];
ll cost[mx];

void dijkstra(ll src)
{
    stack<pii> pq;
    memset(cost,inf,sizeof cost);

    cost[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        pii f=pq.top();
        pq.pop();
        //ll w=f.xx,
        ll u=f.yy;
        //cost[u]=min(w,cost[u]);

        ll len=graph[u].size();
        for(ll i=0; i<len ;i++)
        {
            ll v=graph[u][i].yy,wadj=graph[u][i].xx;

            if(max(cost[u],wadj)<cost[v])
            {
                cost[v]=max(cost[u],wadj);
                pq.push({wadj,v});
                //printf("cost[%lld]: %lld\n",v,cost[v]);
            }
        }

    }
}

int main()
{
    //freopen("light.txt","r",stdin);

    //printf("inf: %lld\n",inf);
    ll t,n,m,u,v,w,home;
    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        scanf("%lld%lld",&n,&m);

        for(ll k=0; k<m; k++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }
        scanf("%lld",&home);

        dijkstra(home);

        printf("Case %lld:\n",i);

        for(ll k=0; k<n; k++)
        {
            if(cost[k]<inf)
                printf("%lld\n",cost[k]);
            else
                printf("Impossible\n");
            graph[k].clear();
        }

    }

    return 0;
}

