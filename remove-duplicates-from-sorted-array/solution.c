
/*
  LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/1633188/Runtime-8-ms-Simple-C-Solution
*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2)
        return numsSize;
    int idx = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[idx++] = nums[i];
        }
    }
    return idx;
}
