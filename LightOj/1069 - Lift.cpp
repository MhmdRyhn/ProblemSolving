#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t,m,x;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&m,&x);
        printf("Case %d: %lld\n",i+1,(long long)(4*abs(m-x)+m*4+19));
    }


    return 0;
}
