class Solution {
public:
	bool isPossible(vector<int>& nums) {
		if (nums.size() < 3) return false;
		vector<vector<int> >v;
		bool flag;
		for (int i = 0; i < nums.size(); i++) {
		    flag = false;
			for (int j = v.size() - 1; j >= 0; j--) {  //先在当前组里找插入点，没有就往其他组里找插入点
				if (nums[i] == v[j].back() + 1) {
					v[j].push_back(nums[i]);
					flag = true;
					break;
				}
			}
			if (flag == false) {  //都找不到插入点，重新开辟新的一组
				vector<int> temp;
				temp.push_back(nums[i]);
				v.push_back(temp);
			}
		}
		for (int k = 0; k < v.size(); k++) {
			if (v[k].size() < 3) return false;
		}
		return true;
	}
};