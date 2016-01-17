
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
int main()
{
    int t;
    ll n;
    scanf("%d",&t);

    for(int i=0; i<t; i++)
    {
        ll j;
        scanf("%lld",&n);

        if(n%2)
            printf("Case %d: Impossible\n",i+1);
        else
        {

            printf("Case %d: %lld %lld\n",i+1,1ll,n);
        }
    }


    return 0;
}
