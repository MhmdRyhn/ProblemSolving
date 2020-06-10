#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> anagrams;
        vector<vector<string>> ans;
        int lowerCaseCnt=26;

        for(int i=0; i<strs.size(); i++)
        {
            int cnt[lowerCaseCnt];
            memset(cnt, 0, sizeof(cnt));
            for(int j=0; j<strs[i].size(); j++)
                cnt[(int)(strs[i][j] - 'a')]++;

            string s = "";
            for(int j=0; j<lowerCaseCnt; j++)
                if(cnt[j])
                {
                    if(s.length())
                        s += "|";
                    s += to_string(j) + "=" + to_string(cnt[j]);
                }
            if(anagrams.find(s) == anagrams.end())
                anagrams[s] = vector<string> {strs[i]};
            else
                anagrams[s].push_back(strs[i]);
        }

        for(map<string, vector<string>>::iterator it=anagrams.begin(); it!=anagrams.end(); it++)
            ans.push_back(it->second);

        return ans;
    }
};


int main()
{
    Solution obj;

    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = obj.groupAnagrams(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

