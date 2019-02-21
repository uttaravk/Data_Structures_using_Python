def reverse_string(str):
    new_str = ""
    for i in str[::-1]:
        new_str += i
    return new_str


print(reverse_string("hello World"))
