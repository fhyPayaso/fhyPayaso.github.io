package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */
class LC215 {


    public int findKthLargest(int[] nums, int k) {
        // 经典快排法
        quickSort(nums, 0, nums.length - 1);
        return nums[nums.length - k];
    }

    public void quickSort(int[] num, int l, int r) {

        if (l >= r) {
            return;
        }

        int flag = num[l];
        int i = l, j = r;
        while (i < j) {

            while (i < j && num[j] >= flag) {
                j--;
            }
            num[i] = num[j];

            while (i < j && num[i] <= flag) {
                i++;
            }
            num[j] = num[i];
        }
        num[i] = flag;

        quickSort(num, l, i);
        quickSort(num, i + 1, r);

    }
}