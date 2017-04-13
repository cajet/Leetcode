//  1.用二分法找到单调循环数组的转折点  
//  2.找到转折点之后，确定目标在转折点左边还是右边
//  3.应用普通二分法寻找目标


class Solution {
public:
    int search(vector<int>& nums, int target) {
      int size = nums.size(), min = 0, max = size-1;
      int mid;
      while (min < max) {
        mid = min+(max-min)/2;
        if (nums[mid] > nums[max])
          min = mid+1;
        else
          max = mid;
      }

      if (target>nums[size-1]) {
        max = min;
        min = 0;
      } else {
        max = size -1;
      }

      while (min < max) {
        mid = min+(max-min)/2;
        if (target > nums[mid])
          min = mid+1;
        else
          max = mid;
      }


      if (target==nums[min])
        return min;
      else
        return -1;
    }
};
