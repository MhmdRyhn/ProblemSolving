#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int maxNum = -((1<<16)-1);
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!matrix[i][j])
                {
                    for(int k=0; k<m; k++)
                        if(matrix[k][j])
                            matrix[k][j] = maxNum;
                    for(int k=0; k<n; k++)
                        if(matrix[i][k])
                            matrix[i][k] = maxNum;
                }
            }
        }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(matrix[i][j] == maxNum)
                    matrix[i][j] = 0;
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> v =
    {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    obj.setZeroes(v);

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

