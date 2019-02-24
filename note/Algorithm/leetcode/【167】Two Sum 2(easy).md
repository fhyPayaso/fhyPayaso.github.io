
### 【167】Two Sum 2(easy)

> 题目大意 

给出一个升序数组，和一个目标值，数组中有两个数相加和目标值相等，返回这两个数的下标(从1开始)

> 解题思路

此题是TwoSum的简化版本，数组已经升序排好，双指针从左右开始维护即可

> AC代码

```
    public int[] twoSum(int[] nums, int target) {

        int[] res = new int[2];
        // 数组已经排好序，左指针指小值，右指针指大值
        int i = 0, j = nums.length - 1;
        while (i < j) {
            // 获取当前数的和，与目标比较
            int sum = nums[i] + nums[j];
            if (sum == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            } else if (sum > target) {
                j--; // 当前值大则大数减小
            } else {
                i++; // 当前值小则小数增大
            }
        }
        return res;
    }
```