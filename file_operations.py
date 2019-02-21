def file_read():
    lines = []
    with open('filename.txt', mode='r') as f:
        for i in f:
            i = i.strip('\n')
            i = i.strip(' ')
            lines.append(int(i))
    return lines


def file_write():
    with open('filename.txt', mode='a') as f:
        f.write('6')


print(file_read())
print(file_write())
print(file_read())
