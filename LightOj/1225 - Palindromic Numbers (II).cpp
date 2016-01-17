#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
int main()
{
    char x[10];
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int k,cnt=0;
        scanf("%s",x);

        for(k=0; k<strlen(x)/2; k++)
            if(x[k]!=x[strlen(x)-1-k])
                break;
        if(k==strlen(x)/2)
            printf("Case %d: Yes\n",i+1);
        else
            printf("Case %d: No\n",i+1);
    }



    return 0;
}
