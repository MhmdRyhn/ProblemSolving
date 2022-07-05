from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False


if __name__ == '__main__':
    head = ListNode(0)
    b = ListNode(1)
    head.next = b
    c = ListNode(2)
    b.next = c
    d = ListNode(3)
    c.next = d
    e = ListNode(4)
    d.next = e
    # e.next = b
    ans = Solution().hasCycle(head)
    print(ans)
