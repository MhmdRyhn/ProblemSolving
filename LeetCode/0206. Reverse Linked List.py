from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    """ Iterative Solution """

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        follower = None
        leader = head
        while leader is not None:
            leader_next = leader.next
            leader.next = follower
            follower = leader
            leader = leader_next
        return follower


class SolutionRecursive:
    """ Recursive Solution """

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        return self.recursive_reverse(None, head)

    def recursive_reverse(self, follower: Optional[ListNode], leader: Optional[ListNode]):
        if leader is None:
            return follower
        leader_next = leader.next
        leader.next = follower
        follower = leader
        leader = leader_next
        return self.recursive_reverse(follower, leader)


"""
** Here, f = follower, l = leader, N = None
(N-f) | (1-l) > 2 > 3 > 4
(1-f) > N | (2-l) > 3 > 4
(2-f) > 1 > N | (3-l) > 4
(3-f) > 2 > 1 > N | (4-l)
(4-f) > 3 > 2 > 1 | (N-l)
4 > 3 > 2 > 1
"""

if __name__ == '__main__':
    pass
