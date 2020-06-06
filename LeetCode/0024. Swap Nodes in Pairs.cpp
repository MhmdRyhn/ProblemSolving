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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* temp;
        ListNode* justBack = NULL;
        ListNode* current = head;

        while(current and current->next)
        {
            temp = current->next;
            current->next = current->next->next;
            temp->next = current;
            if(justBack == NULL)
            {
                justBack = temp;
                head = temp;
            }
            else
                justBack->next=temp;
            justBack = current;
            current = current->next;
        }

        return head;
    }
};


int main()
{
    Solution obj;

    return 0;
}

