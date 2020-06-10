#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++)
            for(int j=i+1; j<matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> v;
    int n = 5, x = 1;
    for(int i=1; i<=n; i++)
    {
        vector<int> a;
        for(int j=1; j<=n; j++)
        {
            a.push_back(x);
            x++;
        }
        v.push_back(a);
    }
    obj.rotate(v);

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

