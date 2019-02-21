def selection_sort(arr):
    for i in range(len(arr)):
        pos = i
        for j in range(i + 1, len(arr)):
            if arr[pos] > arr[j]:
                pos = j
        arr[i], arr[pos] = arr[pos], arr[i]
    return arr


arr = [1, 5, 0, 3, 7]
print(selection_sort(arr))


def insertion_sort(arr):
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr


arr = [1, 5, 0, 3, 7]
print(insertion_sort(arr))


def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


arr = [1, 5, 0, 3, 7]
print(bubble_sort(arr))
