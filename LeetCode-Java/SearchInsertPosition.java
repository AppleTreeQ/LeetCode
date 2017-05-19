package leetcode;

public class SearchInsertPosition {
	
	public int searchInsert(int[] nums, int target) {
		return searchInsertPosition(nums, 0, nums.length - 1, target);
	}

	private int searchInsertPosition(int[] nums, int l, int r, int target) {
		if (l > r) {
			return l;
		}
		if (l == r) {
			return (target > nums[l]) ? l + 1 : l;
		}
		int m = (l + r) >> 1;
		if (target == nums[m]) {
			return m;
		} else if (target < nums[m]) {
			return searchInsertPosition(nums, l, m - 1, target);
		} else {
			return searchInsertPosition(nums, m + 1, r, target);
		}
	}
}
