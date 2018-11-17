"""
Given an arbitrary ransom note string and another string containing letters
from all the magazines, write a function that will return true
if the ransom note can be constructed from the magazines ; otherwise,
it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
"""


import collections


def canConstruct(ransomNote, magazine):
    note_count = collections.Counter(ransomNote)
    for letter, count in note_count.items():
        if magazine.count(letter) < count:
            return False
    return True


ransomNote = "bg"
magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
print(canConstruct(ransomNote, magazine))

ransomNote = "aa"
magazine = "ab"
print(canConstruct(ransomNote, magazine))
