#include<bits/stdc++.h>
using namespace std;

int words[26][26][26];

int hor[]= {0,0,0,0,1,-1};
int ver[]= {0,0,1,-1,0,0};
int cor[]= {1,-1,0,0,0,0};


struct toy
{
    int x,y,z;
    toy(int a,int b,int c)
    {
        x=a,y=b,z=c;
    }
};

int bfs(int a,int b,int c)
{

    if(words[a][b][c]==-2)
        return 0;

    if(words[a][b][c]==-1)
        return -1;

    queue<toy> q;
    q.push(toy(a,b,c));

    int i,j,k;
    while(!q.empty())
    {
        toy u=q.front();
        q.pop();

        for(int h=0; h<6; h++)
        {
            i=(u.x+hor[h])%26;
            i=(i<0)? 25:i;

            j=(u.y+ver[h])%26;
            j=(j<0)? 25:j;

            k=(u.z+cor[h])%26;
            k=(k<0)? 25:k;


            if(words[i][j][k]==-1)
                continue;

            if(words[i][j][k]==-2)
                return (words[u.x][u.y][u.z]+1);

            if(words[i][j][k]==0)
            {
                q.push(toy(i,j,k));
                words[i][j][k]=words[u.x][u.y][u.z]+1;
            }
        }
    }
    return -1;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=1; t--; i++)
    {
        memset(words,0,sizeof words);
        char s[6],s1[7];

        scanf("%s%s",s,s1);

        /// -2 represents destination
        words[s1[0]-'a'][s1[1]-'a'][s1[2]-'a']=-2;

        scanf("%d",&n);
        for(int k=0; k<n; k++)
        {
            string d1,d2,d3;
            cin>>d1>>d2>>d3;

            for(int x=0; x<d1.length(); x++)
                for(int y=0; y<d2.length(); y++)
                    for(int z=0; z<d3.length(); z++)
                        /// -1 represents forbidden words
                        words[d1[x]-'a'][d2[y]-'a'][d3[z]-'a']=-1;
        }

        printf("Case %d: %d\n",i,bfs((int)(s[0]-'a'),(int)(s[1]-'a'),(int)(s[2]-'a')));
    }


    return 0;
}
