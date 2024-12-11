# Fibonacci Search algorithm
def fibonacci_search(arr, x):
    n = len(arr)
    
    # Initialize Fibonacci numbers
    fib_m_minus_2 = 0  # (m-2)'th Fibonacci number
    fib_m_minus_1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m_minus_2 + fib_m_minus_1  # m'th Fibonacci number
    
    # fib_m is the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib_m
        fib_m = fib_m_minus_2 + fib_m_minus_1
    
    # Initially, we are considering the whole array
    offset = -1
    
    # Continue searching while the Fibonacci number is greater than 1
    while fib_m > 1:
        # Calculate the index to compare with
        i = min(offset + fib_m_minus_2, n-1)
        
        # If x is greater than the element at index i, cut the subarray from the left
        if arr[i] < x:
            fib_m = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
            offset = i
        
        # If x is smaller than the element at index i, cut the subarray from the right
        elif arr[i] > x:
            fib_m = fib_m_minus_2
            fib_m_minus_2 = fib_m_minus_1 - fib_m_minus_2
            fib_m_minus_1 = fib_m - fib_m_minus_2
        
        # Element found at index i
        else:
            return i
    
    # If there is one element left, compare it with x
    if fib_m_minus_1 and arr[offset + 1] == x:
        return offset + 1
    
    # If the element is not present in the array
    return -1

# Example usage
arr = [10, 22, 35, 40, 45, 50, 80, 82, 85]
x = 85

result = fibonacci_search(arr, x)

if result != -1:
    print(f"Element {x} found at index {result}")
else:
    print(f"Element {x} not found in the array")
