#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    ll a,b,c,mx,mn,n;
    string big,small,x;

    scanf("%d",&t);
    for(int cnt=1; t--; cnt++)
    {
        scanf("%lld",&n);
        cin>>x;
        big=x;
        small=x;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll p=a*b*c;
        mx=mn=p;

        n--;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            scanf("%lld%lld%lld",&a,&b,&c);

            p=a*b*c;
            if(p<mn)
            {
                mn=p;
                small=x;
            }
            if(p>mx)
            {
                mx=p;
                big=x;
            }

        }

        printf("Case %d: ",cnt);
        if(mx-mn)
            cout<<big<<" took chocolate from "<<small<<endl;
        else
            cout<<"no thief"<<endl;
    }


    return 0;
}
