#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)


typedef long long ll;


int main()
{
    //ios_base::sync_with_stdio(false);

    ll t,n,m;

    scanf("%lld",&t);

    for(ll i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&m);
        if(n==1 or m==1)
        {
            printf("Case %lld: %lld\n",i+1,max(n,m));
            continue;
        }

        if(n==2 or m==2)
        {
            ll ans=0,p=max(m,n);
            ans+=(ll)(max(m,n)/4)*4;

            p%=4;

            if(p==1)
                ans+=2;
            else if(p>1)
            ans+=4;


            printf("Case %lld: %lld\n",i+1,ans);
            continue;
        }


        ll p=n*m;

        if(p%2)
            printf("Case %lld: %lld\n",i+1,(m*n+1)/2);
        else
            printf("Case %lld: %lld\n",i+1,(m*n)/2);

    }


    return 0;
}






