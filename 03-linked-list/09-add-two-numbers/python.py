# Method 1: Brute
# Time: O(n+m) | Space: O(n+m)
# Turn each list into a BigInt (least-significant digit first), add, then emit digits into a new list. Easy in JavaScript, hides the carry logic interviewers want.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def addTwoNumbers(l1, l2):
    def toBig(node):
        n = 0
        place = 1
        while node:
            n += node.val * place
            place *= 10
            node = node.next
        return n
    sum = toBig(l1) + toBig(l2)
    dummy = ListNode(0)
    tail = dummy
    if sum == 0:
        return dummy
    while sum > 0:
        tail.next = ListNode(int(sum % 10))
        tail = tail.next
        sum /= 10
    return dummy.next


# Method 2: Optimal
# Time: O(max(n,m)) | Space: O(max(n,m))
# Recursive add of two nodes plus carry. Next call gets the rest of both lists. Stack depth follows the longer number.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def addTwoNumbers(l1, l2):
    def add(a, b, carry):
        if not a  and  not b  and  carry == 0:
            return None
        sum = (a ? a.val : 0) + (b ? b.val : 0) + carry
        node = ListNode(sum % 10)
        node.next = add(a ? a.next : None, b ? b.next : None, (sum  # 10))
        return node
    return add(l1, l2, 0)


# Method 3: More optimal
# Time: O(max(n,m)) | Space: O(1)
# Iterative dummy. Each step sums two digits and carry, writes sum % 10, carry becomes floor(sum/10). Extra node if carry remains. Output list is required; extra pointers are constant.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def addTwoNumbers(l1, l2):
    dummy = ListNode(0)
    tail = dummy
    carry = 0
    while l1  or  l2  or  carry:
        sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry
        tail.next = ListNode(sum % 10)
        tail = tail.next
        carry = (sum  # 10)
        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next
    return dummy.next
