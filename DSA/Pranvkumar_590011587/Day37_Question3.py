def delete_middle(stack):
    def delete_middle_helper(s, current, middle):
        if current == middle:
            s.pop()
            return
        temp = s.pop()
        delete_middle_helper(s, current + 1, middle)
        s.append(temp)

    middle = len(stack) // 2
    delete_middle_helper(stack, 0, middle)
    return stack

# Examples:
print(delete_middle([1, 2, 3, 4, 5]))  
print(delete_middle([10, 20, 30]))   
