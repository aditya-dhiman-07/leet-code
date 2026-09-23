class Solution {
private:
    int days_(int capacity, vector<int>& weights) {
        int days = 1;
        int current = 0;

        for (int x : weights) {
            if (current + x > capacity) {
                days++;
                current = x;
            } else {
                current += x;
            }
        }

        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (days_(mid, weights) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};