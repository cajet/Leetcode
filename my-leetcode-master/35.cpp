
// 二分查找

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, max, min;
        int size = nums.size();
        min = 0;
        max = size -1;

        while (min <= max) {
          mid = (min+max)/2;
          if (nums[mid] == target)
            return mid;
          else if (nums[mid] > target)
            max = mid-1;
          else
            min = mid+1;
        }

        return min;
    }
};