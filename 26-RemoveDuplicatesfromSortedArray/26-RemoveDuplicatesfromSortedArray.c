// Last updated: 1/10/2026, 10:17:23 AM
1int removeDuplicates(int* nums, int numsSize) {
2    if (numsSize == 0) return 0; // Edge case: if the array is empty
3
4    int i = 0; // Pointer for the position of unique elements
5
6    // Iterate through the array with j
7    for (int j = 1; j < numsSize; j++) {
8        if (nums[j] != nums[i])  // Check if current element is different from the last 
9            nums[++i] = nums[j]; // Update the position with the new unique element
10    }
11
12    return i + 1; // Return the number of unique elements
13}