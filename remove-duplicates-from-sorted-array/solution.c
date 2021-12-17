
/*
  LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/1633188/Runtime-8-ms-Simple-C-Solution
*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int last_elem = INT32_MIN;
    int cur_idx = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != last_elem) {
            last_elem = nums[i];
            nums[cur_idx] = nums[i];
            count++;
            cur_idx++;
        }
    }
    return count;
}
