public class Solution {
    public int MySqrt(int x) {
        if (x == 0)
            return 0;
        var left = 1;
        var right = x;
        while (true) {
            var mid = (left + right) / 2;
            if (mid > x / mid)
                right = mid - 1;
            else if ((mid + 1) > x / (mid + 1))
                return mid;
            else
                left = mid + 1;
        }
    }
}
