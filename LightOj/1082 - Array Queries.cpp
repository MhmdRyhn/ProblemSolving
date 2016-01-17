#include<bits/stdc++.h>
using namespace std;

#define maxelement 100001
#define maxval 100001

typedef long long ll;

ll ans[maxelement*3];
ll data[maxelement];

void createTree(ll x,ll p,ll q)
{
    if(p==q)
    {
        ans[x]=data[p];
        return;
    }

    ll left=x*2;
    ll right=x*2+1;
    ll mid=(p+q)/2;

    createTree(left,p,mid);
    createTree(right,mid+1,q);

    ans[x]=min(ans[left],ans[right]);

}

ll query(ll x,ll p,ll q,ll i,ll j)
{
    if(i>q or j<p)
        return maxval;

    if(p>=i and q<=j)
        return ans[x];

    ll left=x*2;
    ll right=x*2+1;
    ll mid=(p+q)/2;

    ll a=query(left,p,mid,i,j);
    ll b=query(right,mid+1,q,i,j);


    return min(a,b);
}



int main()
{
    //freopen("code.txt","r",stdin);

    ll t,n,x,y,q;
    scanf("%lld",&t);

    for(ll i=1;t--;i++)
    {
        scanf("%lld%lld",&n,&q);

        for(ll k=1;k<=n;k++)
            scanf("%lld",&data[k]);

        createTree(1,1,n);

//        for(int i=1;i<10;i++)
//            printf("%lld\n",ans[i]);

        printf("Case %lld:\n",i);
        for(ll k=0;k<q;k++)
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));
        }

    }



    return 0;
}

