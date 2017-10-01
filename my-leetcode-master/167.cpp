class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> v;
		int i, j;
		for (i = 0, j = numbers.size() - 1; i < j;) {
			if (numbers[i] + numbers[j] == target) {
                break;
            }
			else  if (numbers[i] + numbers[j] < target) i++;
			else j--;
		}
        return vector<int>({i+1,j+1});
    }
};