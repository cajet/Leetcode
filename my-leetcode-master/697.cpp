class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		vector<int> v;
		map<int, int> m;
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
			if (m[nums[i]] > max) {
				max = m[nums[i]];
			}
		}
		for (auto element : m) {
			if (element.second == max) {
				v.push_back(element.first);
			}
		}
		int length = INT_MAX;
		for (auto element : v) {
			int start, end;
			for (int i = 0; i < nums.size() ; i++) {
				if (nums[i] == element) {
					start = i;
					break;
				}
			}
			for (int j = nums.size() - 1; j >= 0; j--) {
				if (nums[j] == element) {
					end = j;
					break;
				}
			}
			if (length > end - start + 1) {
				length = end - start + 1;
			}
		}
		return length;
	}
};


//解法二，借助map<int, vector<int>> 避免了解法一多次循环，直接记录下标
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        int degree = 0;
        int min_dis = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]].push_back(i);
            int size = map[nums[i]].size();
            degree = max(degree, size);
        }
        for(auto m: map) {
            vector<int> tmp = m.second;
            if(tmp.size()==degree)
                min_dis = min(min_dis, tmp[tmp.size()-1]-tmp[0]+1);
        }
        return min_dis;
    }
};