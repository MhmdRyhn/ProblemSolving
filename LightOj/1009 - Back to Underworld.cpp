#include<bits/stdc++.h>
using namespace std;
#define mx 20001

typedef long long ll;

vector<ll> f[mx];
ll mark[mx];

ll bfs(ll src)
{
    ll black=0,red=0;
    queue<ll> q;

    q.push(src);
    mark[src]=1;
    black++;

    while(!q.empty())
    {
        ll p=q.front();
        q.pop();

        ll len=f[p].size();

        for(ll i=0;i<len;i++)
        {
            if(!mark[f[p][i]]){
            q.push(f[p][i]);
            if(mark[p]==1)
                mark[f[p][i]]=2,red++;
            else
                mark[f[p][i]]=1,black++;
            }
        }
        f[p].clear();
    }
    return max(black,red);
}

int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll i=1; t--; i++)
    {
        ll n,a,b;
        scanf("%lld",&n);

//        for(ll k=0;k<mx;k++)
//            f[k].clear();

        memset(mark,0,sizeof mark);

        for(ll k=0;k<n;k++)
        {
            scanf("%lld%lld",&a,&b);
            f[a].push_back(b);
            f[b].push_back(a);
        }

//        for(ll k=1;k<2001;k++)
//        {
//            ll len=f[k].size();
//            printf("%lld\n",len);
//            if(len!=0)
//                for(ll j=0;j<len;j++)
//                printf("%lld ",f[k][j]);
//            printf("\n");
//        }

        ll ans=0;
        for(ll k=1;k<mx;k++)
        {
            if(!mark[k] and f[k].size())
                //printf("now\t"),
                ans+=bfs(k);
            //f[k].clear();
        }

        printf("Case %lld: %lld\n",i,ans);

    }


    return 0;
}
