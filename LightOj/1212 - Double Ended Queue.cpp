#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,dig;
    string s;
    scanf("%d",&t);

    deque<int> x;

    for(int count=1; t--; count++)
    {
        x.clear();
        printf("Case %d:\n",count);
        scanf("%d%d",&n,&m);

        for(int i=0; i<m; i++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                scanf("%d",&dig);
                if(x.size()<n)
                {
                    x.push_front(dig);
                    printf("Pushed in left: %d\n",dig);
                }
                else
                    printf("The queue is full\n");
            }
            else if(s=="pushRight")
            {
                scanf("%d",&dig);
                if(x.size()<n)
                {
                    x.push_back(dig);
                    printf("Pushed in right: %d\n",dig);
                }
                else
                    printf("The queue is full\n");
            }
            else if(s=="popLeft")
            {
                if(!x.empty())
                {
                    printf("Popped from left: %d\n",x.front());
                    x.pop_front();
                }
                else
                    printf("The queue is empty\n");
            }
            else
            {
                if(!x.empty())
                {
                    printf("Popped from right: %d\n",x.back());
                    x.pop_back();
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }

    return 0;
}
