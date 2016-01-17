#include<bits/stdc++.h>
using namespace std;

///area of triangle
double area(double a,double b,double c)
{
    double per=(a+b+c)/2;
    return sqrt(per*(per-a)*(per-b)*(per-c));
}

///angles of the triangle
double angle(double a,double b,double c)
{
    return acos((b*b+c*c-a*a)/(2*b*c));
}

///area with the curve
double areaWithCurve(double a,double b)
{
    return (a*(b*b)/2);
}

/**
a=r1+r2 ; b=r1+r3 ; c=r2+r3
r3<--A=b^c ; r2<--B=a^c ; r1<--C=a^b
**/

int main()
{
    int t;
    double r1,r2,r3,a,b,c;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r2;
        b=r1+r3;
        c=r2+r3;

        double total=area(a,b,c);
        total-=areaWithCurve(angle(a,b,c),r3);
        total-=areaWithCurve(angle(b,c,a),r2);
        total-=areaWithCurve(angle(c,a,b),r1);

        printf("Case %d: %.10lf\n",i+1,total);
    }


    return 0;
}
