#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int n, q;
    string s;
    map<string, int> m;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(m.find(s) != m.end())
            m[s] ++;
        else
            m[s] = 1;
    }
    
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>s;
        if(m.find(s) != m.end())
            cout<<m[s]<<endl;
        else
            cout<<0<<endl;
    }
    
    return 0;
}
