package hubuDS;

public class KMP {

    public static int getIndexOf(String s, String m) {
        if (s == null || m == null || m.length() < 1 || s.length() < m.length()) {
            return -1;
        }
        char[] str1 = s.toCharArray();
        char[] str2 = m.toCharArray();
        int i1 = 0;
        int i2 = 0;
        // 获取next arr
        int[] next = getNextArray(str2); // O(N)
        // 我的两个串都不能越界，i2越界代表我整个str2都被包进去了
        // 如果i1越界代表我整个str1里面没有包括str2
        // 这就是返回值的原理
        while (i1 < str1.length && i2 < str2.length) {
            // 如果是相等的就都++
            if (str1[i1] == str2[i2]) {
                i1++;
                i2++;
            } else if (i2 == 0) {
                // 可以替换成next[i2] == -1, 如果是之前我们谈到的这个特殊情况的话
                // 我们可以让i1++从下一个位置开始匹配。str2中对比的位置已经无法继续往前面跳跃了
                i1++;
            } else {
                // 遇到不相等的了，我们按照之前的结论把i2移动到next[i2]的位置继续来, i1不动
                i2 = next[i2];
            }
        }
        // 也就是说假如我们可以被包含, 那么str2最终一定会越界了
        return i2 == str2.length ? i1 - i2 : -1;
    }

    private static int[] getNextArray(char[] ms) {
        if (ms.length == 1) {
            return new int[]{-1};
        }
        int[] next = new int[ms.length];
        next[0] = -1; // 这个地方是我人为规定的，因为我们知道下标为0的前面没有任何的字符了
        next[1] = 0; // 1前面有一个字符，但是我们说过了不可以取本身的
        int i = 2; // next数组的位置，next数组的起始位置
        int cn = 0; // 哪个位置是字符和i - 1位置的字符比，同时代表了i - 1位置的信息是多少
        while (i < next.length) {
            if (ms[i - 1] == ms[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }

    public static void main(String[] args) {
        String s = "abcdefg";
        String m = "de";
        System.out.println(getIndexOf(s, m));
    }
}
