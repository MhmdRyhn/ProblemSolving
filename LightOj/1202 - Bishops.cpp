#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int t;
    ll bis[4];
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        for(int k=0;k<4;k++)
            scanf("%lld",&bis[k]);
        if(abs(bis[0]-bis[2])%2==abs(bis[1]-bis[3])%2)
        {
            if(abs(bis[0]-bis[2])==abs(bis[1]-bis[3]))
                printf("Case %d: 1\n",i+1);
            else
                printf("Case %d: 2\n",i+1);
        }
        else
            printf("Case %d: impossible\n",i+1);
    }


    return 0;
}
