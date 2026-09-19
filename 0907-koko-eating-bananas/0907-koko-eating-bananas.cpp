class Solution {
private:
    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;

        for (int x : v) {
            totalH += x / hourly + (x % hourly != 0);
        }

        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};