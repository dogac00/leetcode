
/*
  First, sort the string array in lexicographical order. Then, compare the first and the last element which are the most different elements after sorting.
  
  Assume caller calls free() on returned string
  
  LeetCode: https://leetcode.com/problems/longest-common-prefix/discuss/1631892/Runtime-0-ms-Faster-than-100-in-C
*/

int str_cmp(const void* p1, const void* p2) {
    return strcmp(*(const char**) p1, *(const char**) p2);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return calloc(1, sizeof(char));
    }
    if (strsSize == 1) {
        return strdup(strs[0]);
    }

    qsort(strs, strsSize, sizeof(char*), str_cmp);
    const char* begin = strs[0];
    const char* end = strs[strsSize - 1];
    char* result = calloc(200, sizeof(char));
    for (int i = 0; i < strlen(begin) && i < strlen(end); i++) {
        if (begin[i] != end[i])
            break;

        result[i] = begin[i];
    }

    return result;
}
