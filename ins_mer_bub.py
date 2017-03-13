import random as rand
import time

n = 10

# Initialize
arr = [rand.randrange(1, n) for i in range(n)]
arr2 = [rand.randrange(1, n) for i in range(n)]
arr3 = [rand.randrange(1, n) for i in range(n)]
    
def InsertionSort(arr, way):
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            # Increasing order
            if way == 1:
                if arr[i] > arr[j]:
                    arr[i], arr[j] = arr[j], arr[i]
            # Decreasing order
            else:
                if arr[i] < arr[j]:
                    arr[i], arr[j] = arr[j], arr[i]
    return arr

def MergeSort(arr, n, way):
    # if there is single element, return itself
    if n == 1:
        return arr

    ret = []
    
    first = arr[0:int(n/2)]
    second = arr[int(n/2):len(arr)]

    # Divide 
    first = MergeSort(first, len(first), way)
    second = MergeSort(second, len(second), way)  

    # Merge in increasing order
    if way == 1:
        while len(first) != 0 or len(second) != 0:
            if len(second) == 0:
                ret.append(first[0])
                first.remove(first[0])
            elif len(first) == 0:
                ret.append(second[0])
                second.remove(second[0])
            elif first[0] < second[0]:
                ret.append(first[0])
                first.remove(first[0])
            else:
                ret.append(second[0])
                second.remove(second[0])
    # Merge in decreasing order
    else:
        while len(first) != 0 or len(second) != 0:
            if len(second) == 0:
                ret.append(first[0])
                first.remove(first[0])
            elif len(first) == 0:
                ret.append(second[0])
                second.remove(second[0])
            elif first[0] > second[0]:
                ret.append(first[0])
                first.remove(first[0])
            else:
                ret.append(second[0])
                second.remove(second[0])
    return ret

def BubbleSort(arr, way):
    while True:
        cnt = 0
        for i in range(len(arr)-1):
            # Increasing order
            if way == 1:
                if arr[i] > arr[i+1]:
                    arr[i], arr[i+1] = arr[i+1], arr[i]
                    cnt += 1
            # Decreasing order
            else:
                if arr[i] < arr[i+1]:
                    arr[i], arr[i+1] = arr[i+1], arr[i]
                    cnt += 1
        # Do it until there is nothing to change
        if cnt == 0:
            break
    return arr
start = time.time()
print('Insertion Sort')
print('Original', arr)
arr = InsertionSort(arr, 0)
print('Sorted', arr, '\nTime', time.time() - start)

start = time.time()
print('\nMerge Sort')
print('Original', arr2)
arr2 = MergeSort(arr2, len(arr2), 0)
print('Sorted', arr2, '\nTime', time.time() - start)

start = time.time()
print('\nBubble Sort')
print('Original', arr3)
arr2 = BubbleSort(arr3, 0)
print('Sorted', arr3, '\nTime', time.time() - start)