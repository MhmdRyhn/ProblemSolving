#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define newline printf("\n")
#define mx 30005
#define xx first
#define yy second
//#define ll long long
#define pii pair<ll,ll>
#define initialize(name,val,sz) for(ll i=0;i<sz;i++) name[i]=val;

vector<pii> graph[mx];
ll cost[mx];
bool isvisited[mx];


ll dfs(ll src)
{
    ll ans=0;
    memset(cost,0,sizeof cost);
    memset(isvisited,false,sizeof isvisited);

    queue<ll> qwe;
    cost[src]=0;
    isvisited[src]=true;
    qwe.push(src);
    ll pp;
    ll big=0;

    while(!qwe.empty())
    {
        //printf("out\n");
        pp=qwe.front();
        qwe.pop();

        ll len=graph[pp].size();
        for(ll i=0; i<len; i++)
        {
            ll ver=graph[pp][i].xx;
            ll weight=graph[pp][i].yy;

            if(!isvisited[ver])
            {

                qwe.push(ver);
                isvisited[ver]=true;
                cost[ver]=cost[pp]+weight;
                //printf("cost[%lld]: %lld\n",graph[pp.xx][i].xx,cost[graph[pp.xx][i].xx]);

                if(cost[ver]>=big)
                {
                    big=cost[ver];
                    ans=ver;
                }
            }
        }
    }

    //printf("done: %lld\n",ans);
    return ans;

}


int main()
{
    ll t,n,u,v,w;
    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        scanf("%lld",&n);

        for(ll i=0;i<n;i++)
            graph[i].clear();

        for(ll k=1; k<n; k++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

//        for(int k=0;k<n;k++)
//        {
//            for(int j=0;j<graph[k].size();j++)
//                printf("%lld ",graph[k][j].xx);
//            newline;
//        }
//        newline;

        ll start,fin;

        start=dfs(0);
        //printf("start: %lld\n",start);
        fin=dfs(start);

        printf("Case %lld: %lld\n",i,cost[fin]);

    }

    return 0;
}
