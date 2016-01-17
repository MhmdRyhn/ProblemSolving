
#include<bits/stdc++.h>
using namespace std;
#define mx 101

typedef long long ll;

vector<ll> graph[mx];
ll distance1[mx],distance2[mx];
bool isvisited[mx];

void dfs(ll src,ll dis[])
{
    memset(isvisited,false,sizeof isvisited);

    queue<ll> stk;

    dis[src]=0;
    isvisited[src]=true;
    stk.push(src);

    while(!stk.empty())
    {
        ll u=stk.front();
        stk.pop();

        ll len=graph[u].size();
        for(ll i=0;i<len;i++)
        {
            ll v=graph[u][i];

            if(isvisited[v])
                continue;

            stk.push(v);
            isvisited[v]=true;
            dis[v]=dis[u]+1;
        }

    }
}

int main()
{
    ll t,n,u,v,s,d,p;

    scanf("%lld",&t);

    for(ll i=1;t--;i++)
    {
        scanf("%lld%lld",&n,&p);

        for(ll k=0;k<p;k++)
        {
            scanf("%lld%lld",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        scanf("%lld%lld",&s,&d);

        dfs(s,distance1);
        dfs(d,distance2);

//        for(ll k=0;k<n;k++)
//            printf("%lld ",distance1[k]);
//        printf("\n");
//
//        for(ll k=0;k<n;k++)
//            printf("%lld ",distance2[k]);
//        printf("\n");

        ll ans=0;
        for(ll k=0;k<n;k++)
            ans=max(ans,distance1[k]+distance2[k]),graph[k].clear();

        printf("Case %lld: %lld\n",i,ans);

    }



    return 0;
}

