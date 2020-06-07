#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows = 9, columns = 9, step = 3;

        for(int i=0; i<rows; i++)
        {
            vector<int> visited(10, 0);
            for(int j=0; j<columns; j++)
                if(board[i][j] != '.')
                    if(visited[(int) (board[i][j]-'0')])
                        return false;
                    else
                        visited[(int) (board[i][j]-'0')] = 1;
        }

        for(int i=0; i<columns; i++)
        {
            vector<int> visited(10, 0);
            for(int j=0; j<rows; j++)
                if(board[j][i] != '.')
                    if(visited[(int) (board[j][i]-'0')])
                        return false;
                    else
                        visited[(int) (board[j][i]-'0')] = 1;
        }

        for(int i=0; i<rows; i+=step)
        {
            for(int j=0; j<columns; j+=step)
            {
                vector<int> visited(10, 0);
                for(int m=0; m<step; m++)
                {
                    for(int n=0; n<step; n++)
                        if(board[i+m][j+n] != '.')
                            if(visited[(int) (board[i+m][j+n]-'0')])
                                return false;
                            else
                                visited[(int) (board[i+m][j+n]-'0')] = 1;
                }
            }
        }
        return true;
    }
};


int main()
{
    Solution obj;

    vector<vector<char>> v =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool ans = obj.isValidSudoku(v);
    cout<<ans<<endl;

    return 0;
}

