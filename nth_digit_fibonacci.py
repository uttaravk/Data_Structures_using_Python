def nth_num(pos):
    if pos == 0:
        return 0
    if pos == 1:
        return 1
    return nth_num(pos - 1) + nth_num(pos - 2)


print(nth_num(10))
