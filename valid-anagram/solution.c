

/*
  https://leetcode.com/problems/valid-anagram/
*/

bool isAnagram(char * s, char * t){
    int alphabet[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
        alphabet[s[i] - 'a']++;
    for (int i = 0; t[i] != '\0'; i++)
        alphabet[t[i] - 'a']--;
    for (int i = 0; i < 26; i++)
        if (alphabet[i] != 0)
            return false;
    return true;
}
