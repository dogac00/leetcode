
/*
  LeetCode: https://leetcode.com/problems/remove-element/discuss/1634165/Simple-C-Solution
*/

int removeElement(int* nums, int numsSize, int val) {
    int idx = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != val)
            nums[idx++] = nums[i];
    return idx;
}
