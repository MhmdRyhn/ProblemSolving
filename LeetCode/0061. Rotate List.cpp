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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL)
            return head;

        int totalNode = 1;
        ListNode *tail = head;
        while(tail->next)
        {
            totalNode++;
            tail = tail->next;
        }

        k %= totalNode;
        if(!k)
            return head;

        k = totalNode - k;
        ListNode *current = head;
        while(--k)
            current = current->next;

        tail->next = head;
        head = current->next;
        current->next = NULL;
        return head;
    }
};


int main()
{
    Solution obj;

    return 0;
}

