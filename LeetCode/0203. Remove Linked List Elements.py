# Definition for singly-linked list.
from typing import Optional

from LeetCode.utils import create_singly_link_list


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head is None:
            return None
        follower = None
        leader = head
        while leader is not None:
            if leader.val == val:
                if follower is not None:
                    follower.next = leader.next
                else:
                    head = head.next
                leader = leader.next
            else:
                follower = leader
                leader = leader.next
        return head


if __name__ == '__main__':
    link_list = create_singly_link_list([1, 1, 2, 3, 4, 5, 4, 5, 6, 4, 4])
    # new_link_list = Solution().removeElements(link_list, 5)
    # new_link_list = Solution().removeElements(link_list, 4)
    new_link_list = Solution().removeElements(link_list, 1)
    while new_link_list:
        print(new_link_list.val, end=" ")
        new_link_list = new_link_list.next
