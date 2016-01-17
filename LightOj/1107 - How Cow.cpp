#include<cstdio>
using namespace std;

typedef struct p
{
    int x;
    int y;
} point;

int main()
{
    point low,up,cow;
    int t,n;

    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d%d",&low.x,&low.y,&up.x,&up.y);
        scanf("%d",&n);

        printf("Case %d:\n",i+1);
        for(int k=0; k<n; k++)
        {
            scanf("%d%d",&cow.x,&cow.y);

            if((cow.x>low.x and cow.x<up.x) and (cow.y>low.y and cow.y<up.y))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }



    return 0;
}
