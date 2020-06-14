#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool status = false;

    bool exist(vector<vector<char>>& board, string word)
    {
        if(!word.length())
            return true;
        int m = board.size();
        if(!m)
            return false;
        int n = board[0].size();
        if(!n)
            return false;

        vector<pair<int, int>> pos;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == word[0])
                    pos.push_back({i, j});
            }
        }

        for(int i=0; i<pos.size(); i++)
        {
            vector<vector<bool>> isVisited(m, vector<bool>(n, false));
            string now = string(1, board[pos[i].first][pos[i].second]);
            dfs(board, m, n, word, now, pos[i].first, pos[i].second, isVisited);
            if(status)
                return true;
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, int m, int n, string word, string now, int xsrc, int ysrc, vector<vector<bool>> isVisited)
    {
        int xdir[] = {0, 0, -1, 1};
        int ydir[] = {-1, 1, 0, 0};
        if(word == now or status)
        {
            status = true;
            return;
        }
        isVisited[xsrc][ysrc] = true;

        for(int i=0; i<4; i++)
        {
            int tox = xdir[i]+xsrc, toy = ydir[i]+ysrc;
            if(tox > -1 and tox < m and toy > -1 and toy < n and !isVisited[tox][toy] and board[tox][toy] == word[now.length()])
                dfs(board, m, n, word, now + board[tox][toy], tox, toy, isVisited);
        }
    }
};


int main()
{
    Solution obj;

    vector<vector<char>> v =
    {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    string word = "ABFSADEESEC";
//    string word = "ABCCED";
//    string word = "ABCESEEEFS";

    bool ans = obj.exist(v, word);

    cout<<ans<<endl;

    return 0;
}

