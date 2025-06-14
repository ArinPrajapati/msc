def kadaneAlgo(arr):
    sum = 0;

    maxi = 0;

    for i in range(len(arr)):
        sum += arr[i]
        if(sum < 0):
            sum == 0
        maxi= max(maxi,sum)

    return maxi
    pass


def maxSumSubArray(arr):
    if len(arr) == 0:
        return 0

    if len(arr) == 1:
        return arr[0]

    return kadaneAlgo(arr)


# Example usage:

if __name__ == "__main__":
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(maxSumSubArray(arr))  # Output: 6 (subarray: [4, -1, 2, 1])
    
    arr = [-1, -2, -3]
    print(maxSumSubArray(arr))  # Output: -1 (subarray: [-1])
    
    arr = []
    print(maxSumSubArray(arr))  # Output: 0 (empty array)
    
    arr = [5]
    print(maxSumSubArray(arr))  # Output: 5 (single element array)

