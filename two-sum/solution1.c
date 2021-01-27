
/**
 * Brute-force solution 
 * 
 * This solution is the simplest one but it is not optimal, it can be better.
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int* returnArr;
    
    *returnSize = 2;
    returnArr = (int*) malloc(sizeof(int) * *returnSize);
    
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnArr[0] = i;
                returnArr[1] = j;
                return returnArr;
            }
        }
    }
    
    return NULL;
}
