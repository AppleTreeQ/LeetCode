package leetcode;

public class SearchForARange {
	public int[] searchRange(int[] A, int target) {
		int[] r = {-1, -1};
		r[0] = findL(A, 0, A.length - 1, target);
		r[1] = findR(A, 0, A.length - 1, target);
		return r;
	}

	private int findL(int A[], int l, int r, int target) {
		if (l > r) {
			return -1;
		}
		if (l == r) {
			return A[l] == target ? l : -1;
		}
		int m = (l + r) / 2;
		if (A[m] == target) {
			int posL = findL(A, l, m - 1, target);
			return (posL == -1) ? m : posL;
		} else if (A[m] < target) {
			return findL(A, m + 1, A.length - 1, target);
		} else {
			return findL(A, l, m - 1, target);
		}
	}

	private int findR(int A[], int l, int r, int target) {
		if (l > r) {
			return -1;
		}
		if (l == r) {
			return A[l] == target ? l : -1;
		}
		int m = (l + r) / 2;
		if (A[m] == target) {
			int posR = findR(A, m + 1, A.length -1, target);
			return (posR == -1) ? m : posR;
		} else if (A[m] < target) {
			return findR(A, m + 1, A.length - 1, target);
		} else {
			return findR(A, l, m - 1, target);
		}
	}
}
