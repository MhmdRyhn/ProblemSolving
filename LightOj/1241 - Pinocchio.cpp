#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);

    for(int cnt=1;t--;cnt++)
    {
        int n;
        scanf("%d",&n);
        int x[n];
        int ans=0;
        scanf("%d",&x[0]);
        if(x[0]>2){
            ans+=ceil(((double)x[0]-2)/5);
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d",&x[i]);

            int p=x[i]-x[i-1];

            ans+=ceil(((double)x[i]-x[i-1])/5);

        }
        printf("Case %d: %d\n",cnt,ans);
    }



    return 0;
}
