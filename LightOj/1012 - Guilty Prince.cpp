#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define x first
#define y second

char grid[20][20];

int dfs(pii s,int r,int c)
{
    stack<pii> stk;
    pii cross,d;
    bool isvisited[r][c];
    memset(isvisited,false,sizeof isvisited);

    int cnt=0,cnt2=0;
    stk.push(s);
    isvisited[s.x][s.y]=true;

    while(!stk.empty())
    {
        cross=stk.top();
        stk.pop();
        cnt++;

        if((cross.x-1)>-1 and grid[cross.x-1][cross.y]=='.' and !isvisited[cross.x-1][cross.y])
        {
            stk.push({cross.x-1,cross.y});
            isvisited[cross.x-1][cross.y]=true;
        }
        if((cross.y-1)>-1 and grid[cross.x][cross.y-1]=='.' and !isvisited[cross.x][cross.y-1])
        {
            stk.push({cross.x,cross.y-1});
            isvisited[cross.x][cross.y-1]=true;
        }
        if((cross.x+1)<r and grid[cross.x+1][cross.y]=='.' and !isvisited[cross.x+1][cross.y])
        {
            stk.push({cross.x+1,cross.y});
            isvisited[cross.x+1][cross.y]=true;
        }
        if((cross.y+1)<c and grid[cross.x][cross.y+1]=='.' and !isvisited[cross.x][cross.y+1])
        {
            stk.push({cross.x,cross.y+1});
            isvisited[cross.x][cross.y+1]=true;
        }
    }

    return cnt;
}



int main()
{
    int c,r,t;
    pii s;

    scanf("%d",&t);

    for(int i=1; t--; i++)
    {
        scanf("%d%d",&c,&r);

        bool src=false;
        for(int k=0; k<r; k++)
        {
            scanf("%s",grid[k]);

            if(!src)
                for(int j=0; j<c; j++)
                {
                    if(grid[k][j]=='@')
                    {
                        s= {k,j};
                        src=true;
                        break;
                    }
                }
        }

//        for(int k=0;k<r;k++)
//            printf("%s\n",grid[k]);
//        printf("src: %d %d\n",s.x,s.y);


        printf("Case %d: %d\n",i,dfs(s,r,c));


    }




    return 0;
}
