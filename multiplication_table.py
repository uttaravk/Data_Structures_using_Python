def multi_table():
    tab = [[0 for i in range(0, 12)]for j in range(0, 12)]
    tab = ""
    for i in range(1, 13):
        for j in range(1, 13):
            res = i * j
            tab += str(res) + " "
        tab += "\n"

    print(tab)


print(multi_table())
