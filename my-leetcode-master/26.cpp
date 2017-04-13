// 法1：直接遍历，调用vector的erase函数，但是erase带来的开销比较大
// 法2：使用两个指针，一个在被处理数组上遍历，一个作为结果数组上的指针
//     虽然两个数组实际上是同一个。本质上是将不重复的数字移动到数组前面

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
      int size = nums.size();
      int tmp, ans = size;
      if (size==0)
        return 0;

      tmp = nums[0];
      vector<int>::iterator it = nums.begin()+1;
      while (it!=nums.end()) {
        if (*it == tmp) {
          ans--;
          nums.erase(it);
        } else {
          tmp = *it;
          it++;
        }
      }

      return ans;
    }

    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      int count = 0;

      for (int i = 1; i < size; i++) {
        if (nums[i] == nums[i-1])
          count++;
        else
          nums[i-count] = nums[i];
      }

      return size-count;
    }
};
