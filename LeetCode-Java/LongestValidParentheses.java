package leetcode;

public class LongestValidParentheses {
	public int longestValidParentheses(String s) {
		int[] dp = new int[s.length()];
		int maxLen = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == ')') {
				if (s.charAt(i - 1) == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
					maxLen = Math.max(maxLen, dp[i]);
				} else {
					if (i - 1 - dp[i - 1] >= 0 && s.charAt(i - 1 - dp[i - 1]) == '(') {
						dp[i] = dp[i - 1] + 2 + (i - 2 - dp[i - 1] >= 0 ? dp[i - 2 - dp[i - 1]] : 0);
						maxLen = Math.max(maxLen, dp[i]);
					} else {
						dp[i] = 0;
					}
				}
			}
		}
		return maxLen;
    }
}
