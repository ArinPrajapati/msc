from typing import Optional,List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
        def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
            dummy = ListNode(0, head)
            slow = dummy

            fast = head

            while n > 0 and fast:
                fast = fast.next
                n -= 1


            while fast != None:
                slow = slow.next
                fast = fast.next

            slow.next = slow.next.next

            return dummy.next

        
