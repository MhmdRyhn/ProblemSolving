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
        ll ans=__builtin_popcount(n);
        printf("Case %lld: %s\n",i,((ans%2)==0)? "even":"odd");

    }


    return 0;
}
