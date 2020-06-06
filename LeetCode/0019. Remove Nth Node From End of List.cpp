#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* start = head;
        int cnt = 0;
        while(start != NULL)
        {
            cnt++;
            start = start->next;
        }
        cnt = cnt - n - 1;
        if(cnt < 0)
            return head->next;
        start = head;
        while(cnt and start->next != NULL)
        {
            cnt--;
            start = start->next;
        }
        start->next = start->next->next;

        return head;
    }
};


int main()
{
    Solution obj;

    return 0;
}




