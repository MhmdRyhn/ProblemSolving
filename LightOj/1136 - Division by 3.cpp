#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("light.txt","r",stdin);

    ll t,a,b;
    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        scanf("%lld%lld",&a,&b);
        ll ans=0;

        if((b-a)==0){
                if((a%3)!=1)
            ans++;
            //printf("enter000\n");
        }
        else if((b-a)==1)
        {
            if((a%3)!=1)
                ans++;
            if((b%3)!=1)
                ans++;
            //printf("enter11111\n");
        }
        else
        {
            //printf("enter222222\n");
            if((a%3)==0)
                ans++;
            else if((a%3)==1)
            {
                ans+=2;
                a+=2;
            }
            else
            {
                ans+=2;
                a++;
            }

            ans+=((b-a)/3)*2;
            if((b-a)%3)
                ans+=(b-a)%3-1;
        }

        printf("Case %lld: %lld\n",i,ans);

    }


    return 0;
}
