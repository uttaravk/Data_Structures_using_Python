"""
Find the number of perfect teams that can be formed among a group of students.
A perfect team consists of only 5 students.
No two students in a perfect team must belong to the same category.
Categories depend on the subject a student opts for.
Input: pcmbz
Expected output: 1
Explanation:
pcmbz: implies first student opts for physics, second student opts for chemistry, third to mathematics, forth to biology and last to z: zoology.
From this group of students, we can form one perfect team.
"""

import collections
import sys
s = "pcmpcmbbbzz"


def perfect_team(s):
    subject_count = collections.Counter(s)
    min = sys.maxsize
    for subject, cnt in subject_count.items():
        if min > cnt:
            min = cnt
    return min


print(perfect_team(s))
