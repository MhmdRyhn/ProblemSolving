
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll q;

ll noof5(ll n)
{
    ll ans=0;

    while(n){
        n/=5;
        ans+=n;
    }

    return ans;
}

ll bin_search(ll s,ll d)
{
    if(s>d)
        return -1;

    ll mid=(s+d)/2;

    ll cnt=noof5(mid);

    if(cnt==q)
    {

        while(noof5(mid)==q)
            mid--;

        return ++mid;
    }

    if(cnt<q)
        return bin_search(mid+1,d);
    else
        return bin_search(s,mid-1);
}


int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll i=1;t--;i++)
    {
        scanf("%lld",&q);
        ll ans=bin_search(1,500000000);
        if(ans!=-1)
            printf("Case %lld: %lld\n",i,ans);
        else
            printf("Case %lld: impossible\n",i);
    }


    return 0;
}
