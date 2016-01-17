#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t,n,d;

    scanf("%lld",&t);

    for(ll i=1;t--;i++)
    {
        scanf("%lld%lld",&n,&d);
        ll p=d;
        ll ans=0;
        while(true)
        {
            ans++;
            d=d%n;
            if(!d)
                break;
            d=d*10+p;
        }

        printf("Case %lld: %lld\n",i,ans);
    }

    return 0;
}
