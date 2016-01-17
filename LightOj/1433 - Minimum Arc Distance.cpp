#include<cstdio>
#include<cmath>
using namespace std;

#define p2(a) ((double)(a)*(double)(a))


typedef long long ll;

typedef struct p
{
    double x;
    double y;
} point;

double dist(point p,point q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

int main()
{
    freopen("light.txt","r",stdin);

    point cen,b,a;

    int t;
    double  ans,oa,ab,theta;
    scanf("%d",&t);

    for(ll i=0; i<t; i++)
    {
        scanf("%lf%lf",&cen.x,&cen.y);
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&b.x,&b.y);

        oa=dist(cen,a);
        ab=dist(a,b);


        theta=acos((2*oa*oa-ab*ab)/(2*ab*ab));

        printf("ndfkd: %lf %lf\n",theta,oa);
        printf("pow: %lf\n",p2(4-9));
        ans=theta*oa;

        printf("Case %d: %lf\n\n",i+1,ans);

    }


    return 0;
}
