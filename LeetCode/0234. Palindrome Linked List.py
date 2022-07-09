from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return True
        middle_node = self.get_second_half_of_link_list(head)
        tail_to_middle = self.reverse_link_list(middle_node)
        while tail_to_middle is not None:
            if tail_to_middle.val != head.val:
                return False
            head = head.next
            tail_to_middle = tail_to_middle.next
        return True

    def get_second_half_of_link_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        If number of node is odd:
            return node[ceil(n/2)]
        else:
            return node[n/2]
        """
        if head is None:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if fast is not None:
            slow = slow.next
        return slow

    def reverse_link_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        follower = None
        leader = head
        while leader is not None:
            leader_next = leader.next
            leader.next = follower
            follower = leader
            leader = leader_next
        return follower


if __name__ == '__main__':
    from utils import create_singly_link_list

    head = create_singly_link_list([1, 0, 5, 0, 1])
    print(Solution().isPalindrome(head))
