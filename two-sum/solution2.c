
/**
 * In this solution, we first sort the array with qsort, which is O(n log n) complexity
 * then we declare two indexes, one is the beginning and the other one is at the end of the array
 * we walk through the array if we found the sum then that's it,
 * if the sum is bigger than expected then we must decrement last_index
 * if the sum is smaller than expected then we must increment first_index
 * they will be meeting each other if there's no solution and return NULL in that case
 */

int cmpint(const void *a, const void *b)
{
    return *((int*) a) - *((int*) b);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;

    qsort(nums, numsSize, sizeof(int), cmpint);

    int first_index = 0, last_index = numsSize - 1;

    while (first_index < last_index) {
        int sum = nums[first_index] + nums[last_index];

        if (sum == target) {
            int* ret_arr = (int*) malloc(*returnSize * sizeof(int));
            ret_arr[0] = first_index;
            ret_arr[1] = last_index;
            return ret_arr;
        }
        else if (sum > target)
            last_index--;
        else
            first_index++;
    }

    return NULL;
}
