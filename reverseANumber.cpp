// These two lines of code are responsible for checking whether reversing the number x would result in an overflow or underflow. Let's break down each line:

// if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;

// This line checks for overflow conditions. Here's the explanation:

// INT_MAX represents the maximum value that can be stored in an int variable, which is usually 2^31 - 1 (2147483647) in C++.
// INT_MAX/10 gives the maximum value divided by 10. This is used as a threshold for the reversed number rev.
// The condition rev > INT_MAX/10 checks if the current value of rev is already greater than the threshold. If it is, then reversing x will definitely result in an overflow, so the function returns 0.
// The second part of the condition (rev == INT_MAX / 10 && pop > 7) is an additional check. It is true when the current value of rev is equal to the threshold (INT_MAX/10) and the last digit pop is greater than 7. In this case, reversing x would result in a number greater than INT_MAX, causing an overflow. So, again, the function returns 0.
// if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

// This line checks for underflow conditions. Here's the explanation:

// INT_MIN represents the minimum value that can be stored in an int variable, which is usually -2^31 (-2147483648) in C++.
// INT_MIN/10 gives the minimum value divided by 10. This is used as a threshold for the reversed number rev.
// The condition rev < INT_MIN/10 checks if the current value of rev is already smaller than the threshold. If it is, then reversing x will definitely result in an underflow, so the function returns 0.
// The second part of the condition (rev == INT_MIN / 10 && pop < -8) is an additional check. It is true when the current value of rev is equal to the threshold (INT_MIN/10) and the last digit pop is smaller than -8. In this case, reversing x would result in a number smaller than INT_MIN, causing an underflow. So, again, the function returns 0.
// In summary, these lines of code ensure that the reversed number rev remains within the range of a signed 32-bit integer. If an overflow or underflow is detected, the function immediately returns 0 to indicate that the reversed number cannot be represented within the given range.

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};