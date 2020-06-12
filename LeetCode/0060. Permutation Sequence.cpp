#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        ll kth = (ll) k;
        for(ll i=1; i<=n; i++)
            nums.push_back(i);

        ll fact[10] = {1};
        for(ll i=1; i<=9; i++)
            fact[i] = fact[i-1]*i;

        string s = "";
        for(ll i=(ll) (n-1); i>0; i--)
        {
            int p;
            if(kth%fact[i])
            {
                p = (int) (kth/fact[i]);
                kth %= fact[i];
            }
            else
            {
                p = (int) (kth/fact[i]) - 1;
                kth -= (ll) (p*fact[i]);
            }
            s += to_string(nums[p]);
            nums.erase(nums.begin()+p);
        }
        s += to_string(nums[0]);
        return s;
    }
};


int main()
{
    Solution obj;

    int n = 4, k = 20;

    string ans = obj.getPermutation(n, k);

    cout<<ans<<endl;

    return 0;
}

