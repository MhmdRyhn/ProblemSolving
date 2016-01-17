#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t,b;
    char x[210];

    scanf("%lld",&t);

    for(ll count=1;t--;count++)
    {
        scanf("%s",x);
        scanf("%lld",&b);

        b=abs(b);
        ll i=0,len=strlen(x);
        if(x[0]=='-')
            i=1;

        ll ans=0;
        for(i;i<len;i++)
        {
            ans=ans*10+(x[i]-'0');
            ans%=b;
        }

        printf("Case %lld: ",count);
        if(ans)
            printf("not divisible\n");
        else
            printf("divisible\n");
    }

    return 0;
}
