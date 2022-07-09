from typing import Optional, List, Union


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


def create_singly_link_list(
        vals: Optional[List[Union[int, float, str]]]
) -> Optional[ListNode]:
    if not vals:
        return None
    current_node = next_node = None
    for i in range(len(vals) - 1, -1, -1):
        current_node = ListNode(vals[i], next_node)
        next_node = current_node
    return current_node
