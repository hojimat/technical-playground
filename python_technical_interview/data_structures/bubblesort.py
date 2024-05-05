def bubble(arr):
    N = len(arr)
    output = arr
    for i in range(N):
        for j in range(N-i-1):
            if arr[j] > arr[j+1]:
                output[j], output[j+1] = arr[j+1], arr[j]
    return output

if __name__=='__main__':
    print(bubble([10,12,32,11,3,4,2]))
