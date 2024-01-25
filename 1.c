

 Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
 Time Complexity: O(log(min(a, b)))
 Space Complexity: O(1)

 Find nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    
    int prev = 0, current = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}
Time Complexity: O(n)
Space Complexity: O(1)

Sequential Search
int sequential_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
Time Complexity: O(n)
Space Complexity: O(1)

Bubble Sort
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
Time Complexity: O(n^2)
Space Complexity: O(1)

Selection Sort
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
Time Complexity: O(n^2)
Space Complexity: O(1)

Insertion Sort
void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
Time Complexity: O(n^2)
Space Complexity: O(1)

Min and Max finding in a list (minmax algorithm)
void find_min_max(int arr[], int size, int* min_val, int* max_val) {
    if (size % 2 == 0) {
        *min_val = (arr[0] < arr[1]) ? arr[0] : arr[1];
        *max_val = (arr[0] > arr[1]) ? arr[0] : arr[1];
    } else {
        *min_val = *max_val = arr[0];
    }

    int start_index = (size % 2 == 0) ? 2 : 1;
    for (int i = start_index; i < size - 1; i += 2) {
        if (arr[i] < arr[i + 1]) {
            *min_val = (*min_val < arr[i]) ? *min_val : arr[i];
            *max_val = (*max_val > arr[i + 1]) ? *max_val : arr[i + 1];
        } else {
            *min_val = (*min_val < arr[i + 1]) ? *min_val : arr[i + 1];
            *max_val = (*max_val > arr[i]) ? *max_val : arr[i];
        }
    }
}
Time Complexity: O(n)
Space Complexity: O(1)

int main() {
    // Example usage of the algorithms
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Example of using algorithms
    int result = sequential_search(arr, size, 22);
    printf("Sequential Search: Index of 22 is %d\n", result);

    bubble_sort(arr, size);
    printf("Bubble Sort: Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int fib_result = fibonacci(6);
    printf("Fibonacci(6): %d\n", fib_result);

    int gcd_result = gcd(48, 18);
    printf("GCD(48, 18): %d\n", gcd_result);

    int min_val, max_val;
    find_min_max(arr, size, &min_val, &max_val);
    printf("Min: %d, Max: %d\n", min_val, max_val);

    return 0;
}
