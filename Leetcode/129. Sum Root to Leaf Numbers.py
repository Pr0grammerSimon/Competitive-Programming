# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode],string="") -> int:
        wynik = 0
        string += str(root.val)
        if root.left == None and root.right == None: return int(string)
        if root.left != None:
            wynik += self.sumNumbers(root.left,string)
        if root.right != None:
            wynik += self.sumNumbers(root.right,string)
        return wynik