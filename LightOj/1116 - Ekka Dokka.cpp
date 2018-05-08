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
 
        if((n%2)==1)
            printf("Case %d: Impossible\n",i+1);
        else
        {
        	ll odd = n/2;
        	ll even = 2;
        	while((odd%2)==0)
        	{
        		odd/=2;
        		even*=2;
        	}
            printf("Case %d: %lld %lld\n",i+1,odd,even);
        }
    }
 
 
    return 0;
}
