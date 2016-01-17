#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)


typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);

    ll t,n;
    char s[10];

    scanf("%lld",&t);

    for(ll i=0;i<t;i++)
    {
        scanf("%lld%s",&n,s);

            int p=n%3;
            printf("Case %lld: ",i+1);
        if(strcmp(s,"Alice")==0)
        {

            if(p==0 or p==2)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
        else
        {
            if(p==0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }


    return 0;
}


