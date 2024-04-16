# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1: return TreeNode(val,root)
        kolejka = collections.deque([[root,1]])
        while kolejka:
            root_prime,depth_prime = kolejka.popleft()
            if depth_prime+1 == depth:
                root_prime.left,root_prime.right = TreeNode(val,root_prime.left),TreeNode(val,right=root_prime.right)
            else:
                if root_prime.left != None:
                    kolejka.append([root_prime.left,depth_prime+1])
                if root_prime.right != None:
                    kolejka.append([root_prime.right,depth_prime+1])
        return root