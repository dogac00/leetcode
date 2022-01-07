
// https://leetcode.com/problems/adding-spaces-to-a-string

public class Solution {
    public string AddSpaces(string s, int[] spaces) {
        var sb = new StringBuilder();
        var begin = 0;
        foreach (var idx in spaces) {
            var sub = s.Substring(begin, idx - begin);
            sb.Append(sub);
            sb.Append(" ");
            begin = idx;
        }
        sb.Append(s.Substring(begin, s.Length - begin));
        return sb.ToString();
    }
}
