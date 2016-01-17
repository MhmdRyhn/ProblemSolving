#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int w,l;
        char c;

        scanf("%d %c %d",&l,&c,&w);

        double r=sqrt(l*l+w*w)/2.0;

        double ang=asin(w/2/r)*2;
        double arclen=r*ang;

        double len=200*l/(arclen+l);
        double wid=200*w/(arclen+l);

        printf("Case %d: %.8lf %.8lf\n",i+1,len+1e-10,wid+1e-10);
    }

    return 0;
}
