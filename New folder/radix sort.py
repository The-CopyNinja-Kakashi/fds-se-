def shell_sort(arr):
    # Start with a large gap, then reduce the gap
    n = len(arr)
    gap = n // 2  # Initial gap size (half of the array length)

    # Perform the sorting until gap is reduced to 1
    while gap > 0:
        # Perform gapped insertion sort for each element in the array
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Reduce the gap

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original Array:", arr)
shell_sort(arr)
print("Sorted Array:", arr)
