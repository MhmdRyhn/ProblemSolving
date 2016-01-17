#include<cstdio>
#include<iostream>
using namespace std;


typedef long long ll;
int main()
{
    string s;
    int t,n;
    ll mny;
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        ll sum=0;
        scanf("%d",&n);

        printf("Case %d:\n",i+1);
        for(int j=0;j<n;j++)
        {
            cin>>s;
            if(s=="donate")
            {
                scanf("%lld",&mny);
                sum+=mny;
            }
            else
                printf("%lld\n",sum);
        }
    }


    return 0;
}
