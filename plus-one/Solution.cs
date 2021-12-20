/*
  LeetCode: https://leetcode.com/problems/plus-one/discuss/1637848/Simple-C-Solution
*/

public class Solution {
    public int[] PlusOne(int[] digits) {
        if (digits.Length == 0)
            return digits;
        var pos = digits.Length - 1;
        digits[pos] += 1;

        while (digits[pos] > 9) {
            digits[pos] = 0;

            if (pos - 1 < 0) {
                var newDigits = new int[digits.Length + 1];
                Array.Copy(digits, 0, newDigits, 1, digits.Length);
                newDigits[0] = 1;
                return newDigits;
            }

            digits[pos - 1] += 1;
            pos--;
        }
        return digits;
    }
}
