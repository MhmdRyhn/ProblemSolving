#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)


typedef long long ll;

bool f(pair<int,int> a,pair<int,int>b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second>b.second;
}


int main()
{
    //freopen("light.txt","r",stdin);

    vector<pair<int,int> > store;
    store.push_back({1,1});
    for(int i=2;i<1001;i++)
    {

        int p=i;
        int ans=1;
        for(int k=2;k<=(int)(i/2);k++)
        {
            int cnt=0;
            while((p%k)==0){
                    p/=k;
                cnt++;
            }
            ans*=(cnt+1);
        }
        if(p>1)
            ans*=2;
        store.push_back({ans,i});
    }

    sort(store.begin(),store.end(),f);

    int t,n;
    scanf("%d",&t);
    for(int i=1;t--;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,store[n-1].second);
    }




    return 0;
}





