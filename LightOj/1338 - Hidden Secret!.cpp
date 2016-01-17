#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    getchar();

    for(int i=0; i<t; i++)
    {
        int x[26]= {0};

        int cnt=0;
        char c;
        char s1[105],s2[105];

        gets(s1);
        gets(s2);

        for(int k=0; k<strlen(s1); k++)
        {
            if(s1[k]==' ')
                continue;

            c=toupper(s1[k]);
            x[c-'A']++;
            cnt++;
        }

        for(int k=0; k<strlen(s2); k++)
        {
            if(s2[k]==' ')
                continue;

            c=toupper(s2[k]);
            x[c-'A']--;
            cnt--;

        }

        if(cnt!=0)
            printf("Case %d: No\n",i+1);
        else
        {
            cnt=0;
            for(int k=0; k<26; k++)
            {
                if(x[k]==0)
                    cnt++;
                else
                    break;
            }

            if(cnt==26)
                printf("Case %d: Yes\n",i+1);
            else
                printf("Case %d: No\n",i+1);
        }

    }

    return 0;
}
