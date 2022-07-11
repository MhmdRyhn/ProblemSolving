# Definition for singly-linked list.
from typing import Optional

from LeetCode.utils import create_singly_link_list


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        follower = head
        leader = head.next
        while leader:
            if leader.val == follower.val:
                leader = leader.next
                follower.next = leader
            else:
                follower = follower.next
                leader = leader.next
        return head


if __name__ == '__main__':
    link_list = create_singly_link_list([1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7])
    # new_link_list = Solution().removeElements(link_list, 5)
    # new_link_list = Solution().removeElements(link_list, 4)
    new_link_list = Solution().deleteDuplicates(link_list)
    while new_link_list:
        print(new_link_list.val, end=" ")
        new_link_list = new_link_list.next
