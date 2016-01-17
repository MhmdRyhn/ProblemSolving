#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a[5],b[5];
    ll t;

    scanf("%lld",&t);

    for(ll cnt=1;t--;cnt++)
    {
        scanf("%lld.%lld.%lld.%lld",&a[1],&a[2],&a[3],&a[4]);
        scanf("%lld.%lld.%lld.%lld",&b[1],&b[2],&b[3],&b[4]);

        ll mat=0;
        for(ll i=1;i<5;i++)
        {
            //printf("%lld\n",b[i]);
            ll ans=0;
            for(ll k=0;b[i];k++){
                ans+=(b[i]%10)*(1<<k);
                b[i]/=10;
            }
            if(ans==a[i])
                mat++;
            else
                break;
        }

        printf("Case %lld: ",cnt);
        if(mat==4)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
