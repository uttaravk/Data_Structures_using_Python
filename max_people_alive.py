def num_people_alive():
    birth = [2000, 1975, 1975, 1803, 1750, 1840, 1803, 1894]
    death = [2011, 2006, 2004, 1810, 1870, 1936, 1922, 1922]
    birth.sort()
    death.sort()
    max = 0
    cnt = 0
    yr = 0
    print (birth)
    print(death)
    j = 0
    for i in range(0, len(birth)):
        if birth[i] < death[j]:
            cnt += 1
        elif birth[i] > death[j]:
            if max < cnt:
                max = cnt
                yr = birth[i - 1]
            cnt -= 1
            j += 1
            i -= 1
    if max < cnt:
        max = cnt
    return yr


print(num_people_alive())
