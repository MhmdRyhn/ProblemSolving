#include<bits/stdc++.h>
using namespace  std;

#define pi acos(-1)


int main()
{
    int t;

    scanf("%d",&t);

    double r1,r2,r3,h,p,ans;

    for(int i=1;t--;i++)
    {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        r3=r2+((r1-r2)*p)/h;
        ans=pi*p*(r2*r2+r2*r3+r3*r3)/3;
        printf("Case %d: %.10lf\n",i,ans);
    }


    return 0;
}
