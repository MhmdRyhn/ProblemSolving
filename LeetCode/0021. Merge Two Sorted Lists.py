from typing import Optional

from LeetCode.utils import create_singly_link_list


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        pre_head = ListNode(-101)
        current = pre_head
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = ListNode(val=list1.val)
                current = current.next
                list1 = list1.next
            else:
                current.next = ListNode(val=list2.val)
                current = current.next
                list2 = list2.next
        if list1:
            current.next = list1
        else:
            current.next = list2
        return pre_head.next


if __name__ == '__main__':
    # l1 = create_singly_link_list([1, 2, 4])
    # l2 = create_singly_link_list([1, 3, 4])
    # l1 = create_singly_link_list([3, 4, 5])
    # l2 = create_singly_link_list([2, 3, 4])
    l1 = create_singly_link_list([])
    l2 = create_singly_link_list([1, 3, 4])
    new_link_list = Solution().mergeTwoLists(l1, l2)
    while new_link_list:
        print(new_link_list.val, end=" ")
        new_link_list = new_link_list.next
