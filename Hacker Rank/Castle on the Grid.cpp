#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>


int bfs(vector< vector<char> > graph, int n, int sx, int sy, int tx, int ty)
{
    int xdir[] = {0, -1, 0, 1};
    int ydir[] = {-1, 0, 1, 0};
    bool is_visited[n][n];
    int cnt[n][n];
    queue<pii> q;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            is_visited[i][j] = false;
            cnt[i][j] = 0;
        }

    q.push({sx, sy});
    is_visited[sx][sy] = true;
    cnt[sx][sy] = 0;

    while(!q.empty())
    {
        pii u = q.front();
        int ux = u.first, uy = u.second;
        q.pop();

        int vx = ux, vy = uy;
        
        // Following four loops can be converted to one loop

        for(int i=1; i<n; i++)
        {
            int vx_updated = ux+i;
            if(vx_updated<n)
            {
                if(graph[vx_updated][vy] == 'X')
                    break;
                if(!is_visited[vx_updated][vy])
                {
                    q.push({vx_updated, vy});
                    is_visited[vx_updated][vy] = true;
                    cnt[vx_updated][vy] = cnt[ux][uy] + 1;
                    if(vx_updated==tx and vy==ty)
                        return cnt[vx_updated][vy];
                }
            }
        }

        for(int i=1; i<n; i++)
        {
            int vx_updated = ux - i;
            if(vx_updated>=0)
            {
                if(graph[vx_updated][vy] == 'X')
                    break;
                if(!is_visited[vx_updated][vy])
                {
                    q.push({vx_updated, vy});
                    is_visited[vx_updated][vy] = true;
                    cnt[vx_updated][vy] = cnt[ux][uy] + 1;
                    if(vx_updated==tx and vy==ty)
                        return cnt[vx_updated][vy];
                }

            }
        }

        for(int i=1; i<n; i++)
        {
            int vy_updated = uy+i;
            if(vy_updated<n)
            {
                if(graph[vx][vy_updated] == 'X')
                    break;
                if(!is_visited[vx][vy_updated])
                {
                    q.push({vx, vy_updated});
                    is_visited[vx][vy_updated] = true;
                    cnt[vx][vy_updated] = cnt[ux][uy] + 1;
                    if(vx==tx and vy_updated==ty)
                        return cnt[vx][vy_updated];
                }

            }
        }

        for(int i=1; i<n; i++)
        {
            int vy_updated = uy-i;
            if(vy_updated>=0)
            {
                if(graph[vx][vy_updated] == 'X')
                    break;
                if(!is_visited[vx][vy_updated])
                {
                    q.push({vx, vy_updated});
                    is_visited[vx][vy_updated] = true;
                    cnt[vx][vy_updated] = cnt[ux][uy] + 1;
                    if(vx==tx and vy_updated==ty)
                        return cnt[vx][vy_updated];
                }
            }
        }

    }

    return cnt[tx][ty];
}


int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);

    int n;
    cin>>n;

    vector< vector<char> > graph(n, vector<char> (n, '.'));

    char a;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a;
            graph[i][j] = a;
        }
    }

    int sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;

    int ans;
    ans = bfs(graph, n, sx, sy, tx, ty);

    cout<<ans;


    return 0;
}

