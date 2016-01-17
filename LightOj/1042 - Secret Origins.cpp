#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("light.txt","r",stdin);

    ll t,n;

    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        scanf("%lld",&n);

        ll p2n=n & -n;
        ll p2m=(n+p2n) & -(n+p2n);
        ll ans=n+p2n+(p2m/p2n)/2-1;
        printf("Case %lld: %lld\n",i,ans);

    }


    return 0;
}

