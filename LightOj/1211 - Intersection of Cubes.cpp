#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("light.txt","r",stdin);

    int t,n,x[4],y[4],z[4];

    scanf("%d",&t);

    for(int i=1; t--; i++)
    {
        scanf("%d",&n);
        scanf("%d%d%d%d%d%d",&x[0],&y[0],&z[0],
              &x[1],&y[1],&z[1]);

        for(int j=1; j<n; j++)
        {
            scanf("%d%d%d%d%d%d",&x[2],&y[2],&z[2],
                  &x[3],&y[3],&z[3]);

            x[0]=max(x[0],x[2]);
            y[0]=max(y[0],y[2]);
            z[0]=max(z[0],z[2]);
            x[1]=min(x[1],x[3]);
            y[1]=min(y[1],y[3]);
            z[1]=min(z[1],z[3]);
        }

        printf("Case %d: ",i);

        if(x[0]<x[1] and y[0]<y[1] and z[0]<z[1])
            printf("%lld\n",(ll)((x[1]-x[0])*
                   (y[1]-y[0])*(z[1]-z[0])));
        else
            printf("0\n");

    }

    return 0;
}
