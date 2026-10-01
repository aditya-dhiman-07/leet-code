#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lowRow = 0, highRow = m - 1;
        int targetRow = -1;

        while (lowRow <= highRow) {
            int mid = lowRow + (highRow - lowRow) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                targetRow = mid;
                break;
            } else if (target < matrix[mid][0]) {
                highRow = mid - 1;
            } else {
                lowRow = mid + 1;
            }
        }

        if (targetRow == -1) return false;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};