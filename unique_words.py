from collections import Counter
import string


def unique_words_list_method1(text):
    # Remove punctuation and convert text into list
    words = (text.translate(None, string.punctuation)).split(" ")

    # Transform each word into lowercase and apply counter
    word_cnt = Counter([word.lower() for word in words])

    # Find unique words
    word_list = []
    for key in word_cnt:
        word_list.append(key)

    return word_list


def unique_words_list_method2(text):
    # Remove punctuation and convert text into list
    words = (text.translate(None, string.punctuation)).split(" ")

    unique_words = set([word.lower() for word in words])

    return list(unique_words)


def unique_words_list_method3(text):
    words = (text.translate(None, string.punctuation)).split(" ")
    words = [word.lower() for word in words]

    word_cnt = {}

    # Counter Implementation
    for i in words:
        if i in word_cnt:
            word_cnt[i] += 1
        else:
            word_cnt[i] = 1
    return(word_cnt)


text = "Hello, My first name is Uttara and my last name is Kulkarni"
print(unique_words_list_method1(text))
print(unique_words_list_method2(text))
print(unique_words_list_method3(text))
