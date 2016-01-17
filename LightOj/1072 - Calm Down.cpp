#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int t,n;
    double r,rb;
    scanf("%d",&t);

    for(int i=0; i<t; i++)
    {
        scanf("%lf%d",&rb,&n);
        if(n==1)
            printf("Case %d: %.10lf\n",i+1,rb);
        else
        {
            printf("Case %d: %.10lf\n",i+1,rb*sin(acos(-1.0)/n)/(1+sin(acos(-1.0)/n)));
        }
    }



    return 0;
}
