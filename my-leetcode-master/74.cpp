class Solution {
public:

    bool searchMatrix1(vector<vector<int> >& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int mid, min = 0, max = m*n-1;

      while (min <= max) {
        mid = min + (max-min)/2;
        if (matrix[mid/n][mid%n] == target)
          return true;
        else if (matrix[mid/n][mid%n] < target)
          min = mid+1;
        else
          max = mid-1;
      }

      return false;
    }

    bool searchMatrix(vector<vector<int> >& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int mid, min = 0, max = m*n-1;

      while (min != max) {
        mid = min + (max-min)/2;
        if (matrix[mid/n][mid%n] < target)
          min = mid+1;
        else
          max = mid;
      }

      return matrix[max/n][max%n]==target;
    }
};
