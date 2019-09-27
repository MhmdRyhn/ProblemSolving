#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);

    ll n, t, x;
    queue<ll> q;
    cin>>n;

    for(ll i=0; i<n; i++)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>x;
            q.push(x);
        }
        else if(t == 2)
            q.pop();
        else
            cout<<q.front()<<endl;
    }

    return 0;
}

