/* O(n^2)  */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int max = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				if (sum > max) max = sum;
			}
		}
		return max;
	}
};

/*O(n*logn)*/

int max(int a, int b, int c) {
	if (a < b) a = b;
	if (a > c) return a;
	else return c;
}

int devide_conquer(vector<int>&  nums, int first, int end) {
	if (first == end) return nums[first];
	int mid = (first + end) / 2;
	int maxLeft = INT_MIN, maxRight = INT_MIN, temp = 0;
	for (int i = mid; i >= first; i--) {
		temp += nums[i];
		if (temp > maxLeft) maxLeft = temp;
	}
	temp = 0;
	for (int j = mid + 1; j <= end; j++) {
		temp += nums[j];
		if (temp > maxRight) maxRight = temp;
	}
	return max(maxLeft + maxRight, devide_conquer(nums, first, mid), devide_conquer(nums, mid + 1, end));
}

int maxSubArray(vector<int>& nums) {
	return devide_conquer(nums, 0, nums.size() - 1);
}

 /*O(n)*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int size = nums.size();
      int max, sum=0;
      max = nums[0];
      //max记录最大连续和的结果，sum记录当前的求和结果

      for (int i = 0; i < size; i++) {
        sum += nums[i];
        //一旦左边的sum小于0，就没有将这个串往右继续传递的意义了
        max = (max>sum?max:sum);
        sum = (sum>0?sum:0);
      }

      return max;
    }
};

 