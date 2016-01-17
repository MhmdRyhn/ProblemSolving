#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

#define mx 1000001

typedef long long ll;

vector<ll> prime;
int no[mx];

void sieve()
{
    for(ll i=3; i<mx; i+=2)
    {
        if(!no[i])
        {
            for(ll k=i*i; k<mx; k+=2*i)
                no[k]=1;
        }
    }

    prime.push_back(2);
    for(ll i=3; i<mx; i+=2)
        if(!no[i])
            prime.push_back(i);
}

/*
ll divisor(ll n)
{
    ll len=(ll)prime.size();
    ll ans=1;
    ll x=(ll)sqrtl(n);
    for(ll i=0; i<len and prime[i]<=x; i++)
    {
        ll cnt=1;
        while(!(n%prime[i]))
        {
            cnt++;
            n/=prime[i];
        }
        ans*=cnt;
    }
    if(n!=1)
        ans*=2;

    return ans;
}
*/




int main()
{
    sieve();

    int t;
    ll n;
    scanf("%d",&t);

    for(int lp=1; t--; lp++)
    {
        scanf("%lld",&n);


        ll len=(ll)prime.size();
        ll ans=1;
        ll x=(ll)sqrtl(n);
        for(ll i=0; i<len and prime[i]<=x; i++)
        {
            ll cnt=1;
            while(!(n%prime[i]))
            {
                cnt++;
                n/=prime[i];
            }
            ans*=cnt;
        }
        if(n!=1)
            ans*=2;

        printf("Case %d: %lld\n",lp,ans-1);
    }

    return 0;
}
