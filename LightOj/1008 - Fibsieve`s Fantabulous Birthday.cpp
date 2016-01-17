#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    long long t,mine,fxy;

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t);
        mine=ceil(sqrt(t));
        fxy=pow(mine-1,2)+((pow(mine,2)-pow(mine-1,2)+1))/2;

        long long go=mine-abs(t-fxy);
        if(mine==sqrtl(t))
            if(mine%2==0)
                printf("Case %d: %lld 1",i,mine);
            else
                printf("Case %d: 1 %lld",i,mine);

        else if(fxy==t)
            printf("Case %d: %lld %lld",i,mine,mine);

        else if(t>fxy)
        {
            if(mine%2==0)
                printf("Case %d: %lld %lld",i,mine,go);
            else
                printf("Case %d: %lld %lld",i,go,mine);

        }

        else if(t<fxy)
        {
            if(mine%2==0)
                printf("Case %d: %lld %lld",i,go,mine);
            else
                printf("Case %d: %lld %lld",i,mine,go);
        }

        printf("\n");
    }

    return 0;
}

