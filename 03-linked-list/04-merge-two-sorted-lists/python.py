# Method 1: Brute
# Time: O((n+m) log(n+m)) | Space: O(n+m)
# Collect every value, sort the array, rebuild. Simple, but sort is extra work and you throw away the original nodes.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def mergeTwoLists(list1, list2):
    vals = []
    p = list1
    while p:
        vals.append(p.val)
        p = p.next
    p = list2
    while p:
        vals.append(p.val)
        p = p.next
    vals.sort()
    dummy = ListNode(0)
    tail = dummy
    for v in vals:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


# Method 2: Optimal
# Time: O(n+m) | Space: O(n+m)
# Recurse: the smaller head is the next output node, then merge the rest. Linear comparisons. Stack depth is O(n+m).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def mergeTwoLists(list1, list2):
    if not list1:
        return list2
    if not list2:
        return list1
    if list1.val < list2.val:
        list1.next = mergeTwoLists(list1.next, list2)
        return list1
    list2.next = mergeTwoLists(list1, list2.next)
    return list2


# Method 3: More optimal
# Time: O(n+m) | Space: O(1)
# Dummy plus a tail pointer. Each step hangs the smaller remaining node. Leftover chain attaches at the end. Constant extra space besides the output, which reuses input nodes.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def mergeTwoLists(list1, list2):
    dummy = ListNode(0)
    tail = dummy
    while list1  and  list2:
        if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
        else:
            tail.next = list2
            list2 = list2.next
        tail = tail.next
    tail.next = list1  or  list2
    return dummy.next
