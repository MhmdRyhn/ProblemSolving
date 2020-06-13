#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int board[m][n];
        for(int i=0; i<n; i++)
            board[0][i] = 1;
        for(int i=0; i<m; i++)
            board[i][0] = 1;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                board[i][j] = board[i-1][j] + board[i][j-1];
        return board[m-1][n-1];
    }
};


int main()
{
    Solution obj;

    int m = 7, n = 3;

    int ans = obj.uniquePaths(m, n);

    cout<<ans<<endl;

    return 0;
}

