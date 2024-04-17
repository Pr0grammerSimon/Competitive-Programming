# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode],string_prime="") -> str:
        string_prime += string.ascii_lowercase[root.val]
        if root.left == None and root.right == None: return string_prime[::-1]
        if root.left != None: s = self.smallestFromLeaf(root.left,string_prime)
        if root.right != None:
            s_2 = self.smallestFromLeaf(root.right,string_prime)
            if root.left == None:
                return s_2
            else: return min(s_2,s)
        return s