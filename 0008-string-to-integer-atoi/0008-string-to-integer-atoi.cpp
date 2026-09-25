class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool flag = false;
        bool sign = false;

        for(char x : s) {
            if(x >= '0' && x <= '9') {
                int temp = x - '0';
                ans = ans * 10 + temp;
                flag = true;

                if(!sign && ans > INT_MAX)
                    return INT_MAX;

                if(sign && ans > (long long)INT_MAX + 1)
                    return INT_MIN;
            }
            else if(!flag && (x == '-' || x == '+')) {
                if(x == '-')
                    sign = true;

                flag = true;
            }
            else if(!flag && x == ' ') {
                continue;
            }
            else {
                break;
            }
        }

        if(sign)
            return -ans;

        return ans;
    }
};