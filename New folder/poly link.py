def insertion_sort(arr):
    # Loop over each element in the array starting from the second one
    for i in range(1, len(arr)):
        key = arr[i]  # The element to be inserted into the sorted portion
        j = i - 1  # The index of the element just before the current element
        
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Place the key in its correct position
        arr[j + 1] = key

# Example usage
arr = [12, 11, 13, 5, 6]
print("Original array:", arr)

insertion_sort(arr)

print("Sorted array:", arr)
