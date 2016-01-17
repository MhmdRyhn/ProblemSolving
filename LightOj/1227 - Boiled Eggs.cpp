#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    for(int i=0; i<t; i++)
    {
        int npcs,ppcs,qgms;
        scanf("%d%d%d",&npcs,&ppcs,&qgms);

        int xgms[npcs];
        for(int k=0; k<npcs; k++)
            scanf("%d",&xgms[k]);

        int k,sum=0;
        for(k=0; k<ppcs and k<npcs; k++)
        {
            sum+=xgms[k];
            if(sum>qgms)
                break;
        }
        printf("Case %d: %d\n",i+1,k);
    }


    return 0;
}
