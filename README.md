# Generic-C-MergeSort
A generic merge sort function for C.

Testing is currently still underway, but so far it seems to work for simple integer arrays.

The initial intent was to find a way to sort without requiring the extra O(n) space that makes merge sort less efficient than quick sort in the average case, but the cost of that seems to be O(log(n)) extra time for the merge method used instead.

In theory, if there was a way to use O(log(n)) space to reduce the time complexity of the merge back down to O(nlog(n)), then things can be improved, but I'm not certain if that's possible.


# Algorithm Complexity Discussion Below
Quick sort claims to run in O(1) space, but that's not actually correct.  Due to the fact that it is recursive with a depth of O(log(n)) in the average case, that means it requires O(log(n)) function calls in the average case.  Each function call adds constant space onto the stack.  So while in theory quick sort takes O(1) space, in practice, it takes O(log(n)) space.

This means that if it's possible to make merge sort take O(log(n)) space at most when merging its two sorted lists, then the growth complexity will match -- or at minimum, get a lot closer to -- quicksort.
