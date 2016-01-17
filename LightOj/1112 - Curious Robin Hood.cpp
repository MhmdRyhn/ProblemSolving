#include<bits/stdc++.h>
using namespace std;
#define max 100001

typedef long long ll;

ll tree[max],data[max];
ll n;

void  update(ll i,ll val)
{
    while(i<=n)
    {
        tree[i]+=val;
        i+=(i & -i);
    }
}

ll query(ll i)
{
    ll sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=(i & -i);
    }
    return sum;
}


int main()
{
    ll t,q,a,b,z;
    scanf("%lld",&t);

    for(ll i=1; t--; i++)
    {
        memset(tree,0,sizeof tree);

        scanf("%lld%lld",&n,&q);

        for(ll k=1; k<=n; k++)
        {
            scanf("%lld",&data[k]);
            update(k,data[k]);
        }

//        for(int w=1;w<=n;w++)
//            printf("%lld ",data[w]);
//        printf("\n");
//        for(int w=1;w<=n;w++)
//            printf("%lld ",tree[w]);
//        printf("\n");

        printf("Case %lld:\n",i);
        for(ll k=0; k<q; k++)
        {
            scanf("%lld",&z);
            switch(z)
            {
            case 1:
                scanf("%lld",&a);
                a++;
                printf("%lld\n",data[a]);
                update(a,-data[a]);
                data[a]=0;
                break;
            case 2:
                scanf("%lld%lld",&a,&b);
                a++;
                update(a,b);
                data[a]+=b;
                break;
            case 3:
                scanf("%lld%lld",&a,&b);
                printf("%lld\n",query(b+1)-query(a));
                break;

            }
        }

    }


    return 0;
}
