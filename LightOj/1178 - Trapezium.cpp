#include<cstdio>
#include<cmath>
using namespace std;

double height_of_trapizium(double par_a,double par_b,double x,double y)
{
    double base_tri=abs(par_a-par_b);
    double p=(base_tri+x+y)/2;
    double ar=sqrt(p*(p-base_tri)*(p-x)*(p-y));
    double hei=(2*ar)/base_tri;
    return ((2*ar)/base_tri);
}

double area_of_trapizium(double par_a,double par_b,double height_trap)
{
    return (0.5*(par_a+par_b)*height_trap);
}


int main()
{
    double a,b,c,d;
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        printf("Case %d: %.7lf\n",i+1,area_of_trapizium(a,c,height_of_trapizium(a,c,b,d)));
    }

    return 0;
}
