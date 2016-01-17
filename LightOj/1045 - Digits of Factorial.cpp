#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
    freopen("input.txt","r",stdin);

    vector<double> digits;

    double sum=0.0;
    digits.push_back(0.0);
    digits.push_back(0.0);
    for(ll i=2;i<=1000000;i++)
    {
        sum+=log((double)i);
        digits.push_back(sum);
    }

    ll t,n,b;
    scanf("%lld",&t);

    for(ll i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&b);
        printf("Case %lld: %lld\n",i+1,(ll)(digits[n]/log((double)b))+1);
    }

    return 0;
}
