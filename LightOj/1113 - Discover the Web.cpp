#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("light.txt","r",stdin);

    string s,w;
    int t;
    scanf("%d",&t);
    //getchar();

    for(int i=1;t--;i++)
    {
        vector<string> web(100);
        printf("Case %d:\n",i);
        web[0]="http://www.lightoj.com/";
        web[1]="NULL";
        int pnt=0,sz=pnt;
        while(cin>>s and s!="QUIT")
        {
            if(s=="VISIT")
            {
                cin>>w;
                web[++pnt]=w;
                web[pnt+1]="NULL";
                cout<<w<<endl;

            }
            else if(s=="BACK")
            {
                if(pnt==0)
                    cout<<"Ignored"<<endl;
                else
                    cout<<web[--pnt]<<endl;

            }
            else
            {
                if(web[pnt+1]=="NULL")
                    cout<<"Ignored"<<endl;
                else{
                    cout<<web[++pnt]<<endl;
                }

            }
        }

        web.clear();
    }



    return 0;
}
