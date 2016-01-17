#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    double x[4];
    scanf("%d",&t);

    for(int i=0;t--;i++)
    {
        scanf("%lf%lf%lf%lf",&x[0],&x[1],&x[2],&x[3]);
        printf("Case %d: %.10lf\n",i+1,(sqrt(x[3])/sqrt(x[3]+1))*x[0]);
    }


    return 0;
}
