#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
int main()
{
    ll t,m,n;
    scanf("%lld",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",i+1,(ll)powl(m,2)*(n/(2*m)));
    }


    return 0;
}
