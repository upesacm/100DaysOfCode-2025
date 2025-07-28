def decode_string(text):
    number_stack = []
    string_stack = []
    current_text = ""
    current_number = 0

    for ch in text:
        if ch.isdigit():
            current_number = current_number * 10 + int(ch)
        elif ch == '[':
            number_stack.append(current_number)
            string_stack.append(current_text)
            current_number = 0
            current_text = ""
        elif ch == ']':
            repeat = number_stack.pop()
            previous_text = string_stack.pop()
            current_text = previous_text + current_text * repeat
        else:
            current_text += ch

    return current_text
