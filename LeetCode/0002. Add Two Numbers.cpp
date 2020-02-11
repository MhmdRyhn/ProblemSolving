/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*************************** Solution 1 *******************/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0);
        ListNode* result = answer;
        int carry = 0;
        
        while(l1 or l2) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            result = result->next;
        }
        if(carry)
            result->next = new ListNode(1);
        
        return answer->next;
    }
};


/*************************** Solution 2 *******************/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = NULL;
        ListNode* result = answer;
        int carry = 0;
        
        while(l1 or l2) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* newNode = new ListNode(sum % 10);
            if(!answer)
                answer = newNode;
            else
                result->next = newNode;
            carry = sum / 10;
            result = newNode;
        }
        if(carry)
            result->next = new ListNode(1);
        
        return answer;
    }
};

