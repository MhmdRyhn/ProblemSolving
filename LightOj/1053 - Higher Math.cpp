#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t,a=5,b=10,c;
    scanf("%d",&t);

    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        /*printf("Direct: %s\n",(a>b and a>c and a*a==(b*b+c*c))? "yes":
               ((b>a and b>c and b*b==(a*a+c*c))? "yes":((c*c==(a*a+b*b))? "yes":"no")));
        */
        printf("Case %d: ",i+1);
        if(a>b and a>c)
        {
            if(a*a==(b*b+c*c))
                printf("yes");
            else
                printf("no");
        }
        else if(b>c and b>a)
        {
            if(b*b==(a*a+c*c))
                printf("yes");
            else
                printf("no");
        }
        else
        {
            if(c*c==(a*a+b*b))
                printf("yes");
            else
                printf("no");
        }

        printf("\n");
    }


    return 0;
}
