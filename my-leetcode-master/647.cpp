/*
一个个位置的统计，使用中心向外拓展的方法： 
1、每个字符自己构成回文，+1 
2、中心拓展，假设当前位置i为回文的中心，那么设置left=i-1 right=i+1，比较left与right位置是否相同，相同就+1，然后各自移动一步，重复直到退出 
3、中心拓展当前的回文长度是偶数的，那么就设置left=i，right=i+1，其他同2一样
*/


class Solution {
public:
	int countSubstrings(string s) {
		int count = 0, left, right;
		for (int i = 0; i < s.length(); i++) {
			count++;
            //奇数
			left = i - 1;
			right = i + 1;
			while (left >= 0 && right < s.length() && s[left] == s[right]) {
				count++;
				left--;
				right++;
			}
			//偶数
			left = i;
			right = i + 1;
			while (left >= 0 && right < s.length() && s[left] == s[right]) {
				count++;
				left--;
				right++;
			}
		}
		return count;
	}
};