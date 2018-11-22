"""
Given a list of names; return a sorted list of these royal names.
First sort alphabetically, and then by their suffix
"""

name_list = ["Philippe I", "Philip II", "Philip"]


def int_to_roman(num):
    first = ["\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    ten = ["\0", "X", "XX", "XXX",
           "XL", "L", "LX", "LXX", "LXXX", "XC"]
    hundred = ["\0", "C", "CC", "CCC",
               "CD", "D", "DC", "DCC", "DCCC", "CM"]
    thousand = ["\0", "M", "MM", "MMM"]
    roman_num = ""
    times = 1
    res = 0
    while (times <= 1000):
        res = num % 10
        if times == 1:
            roman_num = first[res] + roman_num
            break
        elif times == 10:
            roman_num = ten[res] + roman_num
            break
        elif times == 100:
            roman_num = hundred[res] + roman_num
            break
        elif times == 1000:
            roman_num = thousand[res] + roman_num
            break
        times *= 10
        num = num / 10
    return roman_num


def roman_to_int(s):
    romanInt = {'M': 1000, 'D': 500, 'C': 100,
                'L': 50, 'X': 10, 'V': 5, 'I': 1}
    num = 0
    curr = 0
    nxt = 0
    flag = 0
    for i in range(0, len(s) - 1):
        if(flag != 1):
            curr = romanInt[s[i]]
            nxt = romanInt[s[i + 1]]
            if curr >= nxt:
                num = num + curr
            elif curr < nxt:
                num = num + (nxt - curr)
                flag = 1
        else:
            flag = 0
    if(flag != 1):
        num = num + romanInt[s[len(s) - 1]]
    return num


def get_sorted_list(names):
    name_list = []

    for i in names:
        split_name = i.split(' ')
        prefix = split_name[0]
        if len(split_name) == 1:
            name_list.append(prefix)
        else:
            suffix = roman_to_int(split_name[1])
            name_list.append(prefix + " " + str(suffix))

    name_list.sort()
    names = []
    for i in name_list:
        split_name = i.split(' ')
        prefix = split_name[0]
        if len(split_name) == 1:
            names.append(prefix)
        else:
            suffix = int_to_roman(int(split_name[1]))
            names.append(prefix + " " + suffix)

    return names


print(get_sorted_list(name_list))
