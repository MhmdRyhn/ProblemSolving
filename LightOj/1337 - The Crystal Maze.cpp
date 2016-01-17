#include<bits/stdc++.h>
using namespace std;
#define mx 501
#define pii pair<ll,ll>

typedef long long ll;

ll vertical[]= {1,-1,0,0};
ll horizontal[]= {0,0,1,-1};
ll m,n,onex,oney;

char grid[mx][mx];
ll isvisited[mx][mx];
ll cost[mx][mx];

ll dfs(ll p,ll q,ll ans,ll mark)
{
    ll s,d,cnt=0,x=p,y=q;
    stack<pii> stk;
    stk.push({x,y});
    isvisited[x][y]++;

    cost[x][y]=ans;

    while(!stk.empty())
    {
        pii u=stk.top();
        stk.pop();

        x=u.first,y=u.second;
        onex=x,oney=y;

        for(ll i=0; i<4; i++)
        {
            s=x+vertical[i],d=y+horizontal[i];
            if(s>-1 and s<m and d>-1 and d<n and
                    grid[s][d]!='#')
            {
                if(!isvisited[s][d])
                {
                    stk.push({s,d});
                    isvisited[s][d]=1;
                    if(grid[s][d]=='C')
                        cnt++;
                }
                else if(isvisited[s][d]==1 and mark==1)
                {
                    cost[s][d]=ans;
                    stk.push({s,d});
                    isvisited[s][d]++;
                }

            }
        }
    }

    return cnt;
}



int main()
{
    ll t,q,a,b;
    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        memset(isvisited,0,sizeof isvisited);
        memset(cost,0,sizeof cost);

        scanf("%lld%lld%lld",&m,&n,&q);

        for(ll k=0; k<m; k++)
            scanf("%s",grid[k]);

        for(ll j=0; j<m; j++)
        {
            for(ll k=0; k<n; k++)
            {
                ll big=0;
                if(grid[j][k]=='.' and
                        !isvisited[j][k])
                {
                    big=dfs(j,k,0,0);
                    dfs(onex,oney,big,1);
                }
            }
        }

        printf("Case %lld:\n",i);
        for(ll k=0; k<q; k++)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",cost[a-1][b-1]);
        }
    }

    return 0;
}
