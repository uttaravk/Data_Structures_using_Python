def summation():
    sum = 0
    with open('num.txt', mode='r') as f:
        for i in f.read():
            if i.isdigit():
                sum += int(i)
    return sum


print(summation())
