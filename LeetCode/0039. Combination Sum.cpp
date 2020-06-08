#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        typedef struct Node
        {
            Node* prev;
            int curIndex;
            int total;
        } node;

        int len = candidates.size();
        vector<vector<int>> ans;
        queue<node*> q;

        map<int, pair<int, int>> adj;
        for(int i=0; i<len; i++)
            adj[i] = {i, len-1};

        node* superSource = new node;
        superSource->prev = NULL;
        superSource->curIndex = -1;
        superSource->total = 0;
        q.push(superSource);

        while(!q.empty())
        {
            node* top = q.front();
            q.pop();
            if(top->total == target)
            {
                vector<int> oneSolution;
                while(top != NULL)
                {
                    oneSolution.push_back(candidates[top->curIndex]);
                    top = top->prev;
                }
                ans.push_back(oneSolution);
                continue;
            }

            int from, to;
            if(top->curIndex >= 0)
            {
                from = adj[top->curIndex].first;
                to = adj[top->curIndex].second;
            }
            else
            {
                from = 0;
                to = len-1;
            }

            for(int i=from; i<=to; i++)
            {
                if((candidates[i]+top->total) <= target)
                {
                    node* newNode = new node;
                    if(top->total != 0)
                        newNode->prev = top;
                    else
                        newNode->prev = NULL;
                    newNode->curIndex = i;
                    newNode->total = candidates[i]+top->total;
                    q.push(newNode);
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution obj;

    vector<int> v{2, 3, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum(v, target);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

