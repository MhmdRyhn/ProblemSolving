#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if(num1[0] == '0' or num2[0] == '0')
            return "0";

        int len1 = num1.length(), len2 = num2.length();
        vector<int> v1, v2;
        vector<int> ans;

        for(int i=len1-1; i>-1; i--)
            v1.push_back((int) (num1[i]-'0'));
        for(int i=len2-1; i>-1; i--)
            v2.push_back((int) (num2[i]-'0'));
        for(int i=0; i<len2; i++)
            ans.push_back(0);

        for(int i=0; i<len1; i++)
        {
            int j, n;
            int carry = 0;
            for(j=0; j<len2; j++)
            {
                n = v1[i]*v2[j] + carry;
                if((i+j) < ans.size())
                {
                    n += ans[i+j];
                    carry = n/10;
                    n %= 10;
                    ans[i+j] = n;
                }
                else
                {
                    carry = n/10;
                    n %=10;
                    ans.push_back(n);
                }
            }
            if(carry)
            {
                if((i+j) >= ans.size())
                {
                    ans.push_back(carry);
                    carry = 0;
                }
                else
                {
                    n += ans[i+j];
                    carry = n/10;
                    n %=10;
                    ans[i+j] = n;
                }
            }
            if(carry)
                ans.push_back(carry);
        }

        string result = "";
        for(int i=ans.size()-1; i>-1; i--)
            result += to_string(ans[i]);

        return result;
    }
};


int main()
{
    Solution obj;

//    string n1 = "123";
//    string n2 = "0";
//    string correct = "0";

    string n1 = "398952156347820415337010868272413429836462364637363164372310573115219077216899627";
    string n2 = "55714946123437258158091870754660433857669";
    string correct = "22227597896747931974032471411465102311462678900848060110229065542539766699641722110846910736641448270255228166899577189463";
    string ans = obj.multiply(n1, n2);

    cout<<ans<<endl;

    if(ans == correct)
        cout<<"Correct"<<endl;

    return 0;
}

