from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow


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

    f = ListNode(5)
    e.next = f

    print(Solution().middleNode(head).val)
