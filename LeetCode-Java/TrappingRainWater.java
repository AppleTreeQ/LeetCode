package leetcode;

public class TrappingRainWater {
	public int trap(int[] height) {
		return calculate(height, 0, height.length - 1);
	}

	private int calculate(int[] height, int l, int r) {
		if (l >= r - 1)
			return 0;
		int divider = l, dividerHeight = Math.min(height[l], height[r]);
		int sum = 0;
		for (int i = l + 1; i < r; i++) {
			sum += height[i];
			if (dividerHeight < height[i]) {
				dividerHeight = height[i];
				divider = i;
			}
		}
		System.out.println("L: " + l + " R: " + r + " D: " + divider);
		if (divider == l) {
			return Math.min(height[l], height[r]) * (r - l - 1) - sum;
		}
		return calculate(height, l, divider) + calculate(height, divider, r);
    }
}
