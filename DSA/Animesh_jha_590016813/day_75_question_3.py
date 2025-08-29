class Diameter:
    def __init__(self):
        self.max_diameter = 0

def diameter_of_binary_tree(root):
    def height(node):
        if not node:
            return 0
          
        left_h = height(node.left)
        right_h = height(node.right)
      
        diameter.max_diameter = max(diameter.max_diameter, left_h + right_h)

        return 1 + max(left_h, right_h)
    
    diameter = Diameter()
    height(root)
    return diameter.max_diameter

root3 = Node(1)
root3.left = Node(2)
root3.right = Node(3)
root3.left.left = Node(4)
root3.left.right = Node(5)

print("Diameter:", diameter_of_binary_tree(root3))  
