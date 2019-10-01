#include<bits/stdc++.h>
using namespace std;


vector<int> divisors(int x, bool is_visited[])
{
    vector<int> v;
    int a = int(sqrt(x));

    for(int i=2; i<=a; i++)
    {
        if(x%i == 0)
        {
            int m = max(i, x/i);
            if(!is_visited[m] and m>1)
                v.push_back(m);
        }
    }

    return v;
}


int bfs(int n)
{
    if(n<4)
        return n;

    bool is_visited[n+1];
    int steps[n+1];
    queue<int> q;

    for(int i=0; i<=n; i++)
    {
        is_visited[i] = false;
        steps[i] = 0;
    }

    q.push(n);
    is_visited[n] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        vector<int> v;
        v = divisors(u, is_visited);
        for(int i=0; i<v.size(); i++)
        {
            q.push(v[i]);
            is_visited[v[i]] = true;
            steps[v[i]] = steps[u] + 1;
        }
        if(!is_visited[u-1])
        {
            q.push(u-1);
            is_visited[u-1] = true;
            steps[u-1] = steps[u] + 1;
        }
        if(steps[2])
            return steps[2] + 2;
    }
    return steps[0];
}


int main()
{
    ios_base::sync_with_stdio(false);

    int q, n;

    cin>>q;

    for(int i=0; i<q; i++)
    {
        cin>>n;
        int ans = bfs(n);
        cout<<ans<<"\n";
    }


    return 0;
}

