
### 【1】Two Sum (easy)

> 题目大意 

给出一个乱序数组，和一个目标值,数组中有两个数相加和目标值相等，返回这两个数的下标(从0开始)

> 解题思路

一开始头铁非要用桶排序，结果一开始发现有负数，于是改用双桶维护正负，找到目标值后反找下标，复杂度O(n)，理论上可行，结果数据值比较大，桶数组开小了越界，开大了MLE

最后妥协了，把数据排序处理，剩下还按照双指针维护做，用Pair记录排序前的下标，这回复杂度全在排序了，按照O(nlogn)算，结果不能用Pair？？？ 感觉哪里有问题，自己写了一个结构

> AC代码

```
 class Pair {
        public int fst;
        public int snd;

        public Pair(int fst, int snd) {
            this.fst = fst;
            this.snd = snd;
        }
    }

    public int[] twoSum(int[] nums, int target) {

        List<Pair> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(new Pair(i, nums[i]));
        }
        list.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.snd - o2.snd;
            }
        });
        int[] res = new int[2];
        // 数组已经排好序，左指针指小值，右指针指大值
        int i = 0, j = list.size() - 1;
        while (i < j) {
            // 获取当前数的和，与目标比较
            int sum = list.get(i).snd + list.get(j).snd;
            if (sum == target) {
                res[0] = list.get(i).fst;
                res[1] = list.get(j).fst;
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

> 改进

看题解，用map做，O(n)即可,这种解法特殊情况为: 类似[3,3] 6的数据，map中的值会被更新，但最后会对nums遍历，不会遗漏，只不过两次遍历方向不同的话结果的顺序会相反，不过也算AC

```

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            // 值为key，下标为v
            map.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            int tag = target - nums[i];
            if (map.containsKey(tag) && map.get(tag) != i) {
                return new int[]{i, map.get(tag)};
            }
        }
        return null;
    }

```