// JAVA 20171201x
public class Solution {
    public int bulbSwitch(int n) {
        int result = 0;
        for (int i = 1; i * i <= n; ++i, ++result)
            ;
        return result;
    }
}