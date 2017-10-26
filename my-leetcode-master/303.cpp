class NumArray {
public:
    NumArray(vector<int> &nums) {
        v.push_back(0);
        for (int num : nums)
            v.push_back(v.back() + num);
    }

    int sumRange(int i, int j) {
        return v[j + 1] - v[i];
    }
private:
    vector<int> v;
};