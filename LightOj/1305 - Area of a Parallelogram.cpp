#include<cstdio>
#include<cmath>
using namespace std;

typedef struct p
{
    int x;
    int y;
}point;

int main()
{
    point a,b,c,d;
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);

        d.x=c.x-(b.x-a.x);
        d.y=c.y-(b.y-a.y);

        int area=abs((a.x-b.x)*(c.y-b.y)-(c.x-b.x)*(a.y-b.y));

        printf("Case %d: %d %d %d\n",i+1,d.x,d.y,area);
    }




    return 0;
}
