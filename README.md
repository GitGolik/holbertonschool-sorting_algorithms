# Sorting Algorithms

This project contains implementations of sorting algorithms in C.

## Task 0: Bubble sort

The `bubble_sort` function sorts an array of integers in ascending order.

It prints the array after every swap.

### Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c \
    print_array.c 0-main.c -o bubble
```

### Complexity

- Best case: O(n)
- Average case: O(n^2)
- Worst case: O(n^2)
