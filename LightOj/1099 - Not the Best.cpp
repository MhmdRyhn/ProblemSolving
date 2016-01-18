/*
Why go there?
Who makes you DUMP.
Why don't go there?
Who makes you UP.

Who are you waiting for?
Who even doesn't know your EXISTANCE.
Find your best one,
Lessen your DISTANCE.
*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define xx first
#define yy second
#define pii pair<ll,ll>
#define inf 500000001
#define mx 5001
#define reset(x,val) memset(x,val,sizeof x)

vector<pii> graph[mx];
ll cost1[mx];
ll cost2[mx];
ll mincost[mx];
bool isvisited[mx];
bool again[mx];
vector<ll> sec;


ll dijkstra(ll src,ll n)
{
    reset(mincost,inf);
    for(ll i=1; i<=n; i++)
    {
        ll len=graph[i].size();
        for(ll j=0; j<len; j++)
            mincost[i]=min(mincost[i],graph[i][j].xx*2);
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    reset(cost1,inf);
    reset(cost2,inf);
    reset(again,false);
    reset(isvisited,false);

    cost1[src]=0;
    pq.push({0,src});


    while(!pq.empty())
    {
        pii f=pq.top();
        pq.pop();

        ll u=f.yy,w=f.xx;

        //printf("u: %lld w:%lld\n",u,w);

        if(isvisited[u])
        {
            if(w>cost1[u] and w<=cost2[u])
                cost2[u]=w;
            else
                continue;
        }
        else
            isvisited[u]=true;

        ll len=graph[u].size();
        for(ll i=0; i<len; i++)
        {
            pii v=graph[u][i];

            if((w+v.xx)<cost1[v.yy])
            {
                cost2[v.yy]=cost1[v.yy];
                cost1[v.yy]=w+v.xx;
                pq.push({cost1[v.yy],v.yy});
//                printf("pushed one: %lld %lld\n",v.yy,cost1[v.yy]);
//                printf("w+v.xx: %lld\n",w+v.xx);
            }
            else if((w+v.xx)<cost2[v.yy])
            {
                if((w+v.xx)!=cost1[v.yy]){
                    pq.push({w+v.xx,v.yy});
//                printf("pushed two: %lld %lld\n",v.yy,w+v.xx);
//                printf("w+v.xx: %lld\n",w+v.xx);
                }
            }
        }

        if(!again[u])
        {
            pq.push({cost1[u]+mincost[u],u});
//            printf("pushed again: %lld %lld\n",u,cost1[u]+mincost[u]);
            again[u]=true;
        }
    }

    return cost2[n];

}


//void clean(ll n)
//{
//    for(ll i=1;i<=n;i++)
//        graph[i].clear();
//    sec.clear();
//}


int main()
{
    ll t,n,m,u,v,w;

    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        scanf("%lld%lld",&n,&m);

        for(ll i=1; i<=n; i++)
            graph[i].clear();

        for(ll k=0; k<m; k++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }

        printf("Case %lld: %lld\n",i,dijkstra(1,n));
//        for(ll k=1;k<=n;k++)
//            printf("%lld %lld %lld\n",k,cost1[k],cost2[k]);
//        printf("\n\n");
    }


    return 0;
}

