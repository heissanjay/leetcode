// referred editorial

class Solution {
private:
    long long getSum(int index, int value, int n) {
        long long count = 0;
        
        if (value > index) {
            count += (long long)(value + value - index) * (index + 1) / 2;
        } else {
            count += (long long)(value + 1) * value / 2 + index - value + 1;
        };

        if (value >= n - index) {
            count += (long long)(value + value - n + 1 + index) * (n - index) / 2;
        } else {
            count += (long long)(value + 1) * value / 2 + n - index - value;
        }   
        
        return count - value;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (getSum(index, mid, n) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
