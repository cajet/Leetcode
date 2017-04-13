class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int size = nums.size(), min = 0, max = size-1, mid;
      if (size==1)
        return nums[0]==target;

      //寻找转折点
      while (min < max) {
        //跳过重复
        while (min < max && nums[min] == nums[min+1])
          min++;
        while (min < max && nums[max] == nums[max-1])
          max--;
        mid = min +(max-min)/2;
        if (nums[mid] > nums[max])
          min = mid+1;
        else
          max = mid;
      }

      //cout << "min: " << min << endl;

      if (target > nums[size-1]) {
        max = min;
        min = 0;
      } else {
        max = size-1;
      }

      //cout << "min: " << min << ", max: " << max << endl;

      //二分寻找目标值
      while (min < max) {
        mid = min+(max-min)/2;
        if (target > nums[mid])
          min = mid+1;
        else
          max = mid;
      }

      return target==nums[min];
    }
};