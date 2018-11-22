"""
Given a string s and a non-empty string p, find all the start indices of
p's anagrams in s.

Strings consists of lowercase English letters only and the length of
both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
"""

import collections
s = "cbaebabacd"
p = "abc"
# s = "abab"
# p = "ab"


def find_anagrams(s, p):
    anagram_pos = []
    win = ""

    p_len = len(p)
    s_len = len(s)

    if s_len == 0 or p_len > s_len:
        return []

    p_counter = collections.Counter(p)

    if s_len == p_len:
        s_counter = collections.Counter(s)
        if (p_counter == s_counter):
            anagram_pos.append(0)
            return anagram_pos

    win = s[0:p_len]
    win_counter = collections.Counter(win)
    if(win_counter == p_counter):
        anagram_pos.append(0)

    for i in range(p_len, s_len):
        pos = (i - p_len)
        if win_counter[s[pos]] > 1:
            win_counter[s[pos]] -= 1
        else:
            del win_counter[s[pos]]

        win_counter[s[i]] += 1

        if(win_counter == p_counter):
            anagram_pos.append(pos + 1)

    return anagram_pos


print(find_anagrams(s, p))
