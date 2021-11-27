package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 */
class LC33 {

    public int search(int[] nums, int target) {

        int l = 0, r = nums.length - 1;
        int mid;
        while (l < r) {

            mid = l + (r - l) / 2;

            if (target == nums[mid]) {
                return mid;
            }

            // 搜索到旋转节点
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {

                if (target > nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                continue;
            }

            // 中间值小于右侧, 右侧有序
            if (nums[mid] < nums[r]) {

                // 在有序之间
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }

            } else {
                // 左侧有序

                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }

            }
        }

        return -1;
    }
}