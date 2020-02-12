/* 
Learn explanation from here: 
https://www.geeksforgeeks.org/print-longest-substring-without-repeating-characters/
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string str)
    {
        int i;
        int final_start, current_start = 0;
        int max_length = 0, current_length;
        unordered_map<char, int> position;

        int length = str.length();
        for(i=0; i<length; i++)
        {
            if(position.find(str[i]) == position.end())
                position[str[i]] = i;
            else
            {
                if(position[str[i]] >= current_start)
                {
                    current_length = i - current_start;
                    if(current_length > max_length)
                    {
                        max_length = current_length;
                        final_start = current_start;
                    }
                    current_start = position[str[i]] + 1;
                }
                position[str[i]] = i;
            }
        }
        current_length = i - current_start;
        if(current_length > max_length)
        {
            max_length = current_length;
            final_start = current_start;
        }

        return max_length;
    }
};

