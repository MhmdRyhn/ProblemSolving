#include<cstdio>
using namespace std;


typedef long long ll;
int main()
{
    int t;
    ll n,d;
    scanf("%lld",&t);

    for(int i=0; i<t; i++)
    {
        scanf("%lld",&n);

        ll sum=0;
        for(int j=0; j<n; j++)
        {
            scanf("%lld",&d);
            if(d>0)
                sum+=d;
        }
        printf("Case %d: %lld\n",i+1,sum);
    }



    return 0;
}
