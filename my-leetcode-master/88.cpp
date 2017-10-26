class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i, j;
      i = j = 0;

      while (i < m && j < n) {
        while (nums1[i+j] <= nums2[j] && i < m)
          i++;

        if (i == j+m)
          break;

        nums1.insert(nums1.begin()+i+j, nums2[j]);
        j++;
      }
      
      for (; j < n; j++)
        nums1.insert(nums1.begin()+i+j, nums2[j]);
      
      nums1.resize(m+n);
    }
};


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> ret;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ret.push_back(nums1[i]);
                i++;
            } else {
                ret.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            ret.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            ret.push_back(nums2[j]);
            j++;
        }
        nums1 = ret;
	}
};