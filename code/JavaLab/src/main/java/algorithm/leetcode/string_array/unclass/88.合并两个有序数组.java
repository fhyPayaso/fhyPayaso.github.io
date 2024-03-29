package algorithm.leetcode.string_array.unclass;

/**
 * https://leetcode-cn.com/problems/merge-sorted-array/
 */
class LC88 {

    public void merge(int[] nums1, int m, int[] nums2, int n) {

        // 倒序合并即可
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {

            if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

    }
}