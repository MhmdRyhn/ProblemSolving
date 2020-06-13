#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int board[m][n];

        int i, j;
        for(i=0; i<n; i++)
            if(!obstacleGrid[0][i])
                board[0][i] = 1;
            else
                break;
        for(; i<n; i++)
            board[0][i] = 0;

        for(i=0; i<m; i++)
            if(!obstacleGrid[i][0])
                board[i][0] = 1;
            else
                break;
        for(; i<m; i++)
            board[i][0] = 0;

        for(i=1; i<m; i++)
            for(j=1; j<n; j++)
                board[i][j] = obstacleGrid[i][j]? 0:board[i-1][j] + board[i][j-1];

        return board[m-1][n-1];
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> v =
    {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int ans = obj.uniquePathsWithObstacles(v);

    cout<<ans<<endl;

    return 0;
}

