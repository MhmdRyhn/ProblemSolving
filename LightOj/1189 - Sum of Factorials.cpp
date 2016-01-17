#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("light.txt","r",stdin);

    ll fact[21],ans[21];
    fact[0]=1;

    for(ll i=1;i<21;i++)
        fact[i]=fact[i-1]*i;

    ll t,n,k,j;

    scanf("%lld",&t);

    for(ll i=1;t--;i++)
    {
        scanf("%lld",&n);

        for(j=20,k=-1;j>=0 and n;j--)
        {
            if(fact[j]<=n)
            {
                n-=fact[j];
                k++;
                ans[k]=j;
            }
        }

        printf("Case %lld: ",i);
        if(n)
            printf("impossible\n");
        else
        {
            for(k;k>=0;k--)
            {
                printf("%lld!",ans[k]);
                if(k)
                    printf("+");
                else
                    printf("\n");
            }
        }
    }


    return 0;
}
