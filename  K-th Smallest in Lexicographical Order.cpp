class Solution {
public:
   long long countSteps(long long n, long long current, long long next) {
    long long steps = 0;
    while (current <= n) {
        steps += min(n + 1, next) - current;
        current *= 10;
        next *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    long long current = 1;
    k -= 1;

    while (k > 0) {
        long long steps = countSteps(n, current, current + 1);
        if (steps <= k) {
            current += 1;
            k -= steps;
        } else {
            current *= 10;
            k -= 1;
        }
    }

    return current;
}
};