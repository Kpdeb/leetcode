class Solution:
    def countNodes(self, root):
        if not root:
            return 0

        def height(node):
            h = 0
            while node:
                h += 1
                node = node.left
            return h

        left_height = height(root.left)
        right_height = height(root.right)

        if left_height == right_height:
            # Left subtree is a perfect binary tree
            return (1 << left_height) + self.countNodes(root.right)
        else:
            # Right subtree is a perfect binary tree
            return (1 << right_height) + self.countNodes(root.left)