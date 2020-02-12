class Solution
{
public:
    string longestPalindrome(string str)
    {
        int start = 0, stop = 0;
        int length = str.length();

        if(!length)
            return "";

        bool mark[length][length];
        for(int i=0; i<length; i++)
            for(int j=0; j<length; j++)
                mark[i][j] = (i == j)? true: false;

        for(int i=1; i<length; i++)
            if(str[i-1] == str[i])
            {
                mark[i-1][i] = true;
                start = i-1;
                stop = i;
            }


        for(int l=3; l<=length; l++)
        {
            for(int i=0; i<(length-l+1); i++)
            {
                if(mark[i+1][i+l-2] and str[i] == str[i+l-1])
                {
                    mark[i][i+l-1] = true;
                    start = i;
                    stop = i+l-1;
                }
            }
        }

        return str.substr(start, stop-start+1);
    }
};

