class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int i, j, size=nums.size();

      i = 0;
      while (i < nums.size()) {
        //i find the one is 0
        while (nums[i] != val && i < nums.size())
          i++;

        //j find the one not 0
        j = i+1;
        while (nums[j] == val && j < nums.size())
          j++;

        if (j >= nums.size())
          return i;

        nums[i] = nums[j];
        nums[j] = val;
        i++;
        size--;
      }
    }
};