//超时
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) return;
        int temp, n= nums.size();
        k %= n;
        for (int i= 0; i< k; i++) {
            temp= nums[n-1];
            for (int j= n-1; j> 0; j--) {
                nums[j]= nums[j-1];
            }
            nums[0]= temp;
        }
    }
};


//借助STL rotate函数
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};


//把后面k个元素取出，保存到一个新的数组中。
//把前面的(n - k)个元素取出，添加到上面新数组的末尾。
//用新数组替换老数组。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> rotatedNums(nums.begin() + n - k, nums.end());
        rotatedNums.insert(rotatedNums.end(), nums.begin(), nums.begin() + n - k);
        nums = rotatedNums;
    }
};
