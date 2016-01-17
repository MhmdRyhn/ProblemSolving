#include<cstdio>

#define prt(x,y) printf("%d %d\n",x,y)
using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m<=10)
            prt(0,m);
        else
            prt(m-10,10);
    }


    return 0;
}
