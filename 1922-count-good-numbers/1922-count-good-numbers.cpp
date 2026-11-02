class Solution {
public:
    long long mod = 1000000007;

    long long count(long long x, long long n) {
        long long ans = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % mod;
            }

            x = (x * x) % mod;
            n = n / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long a = count(5, even);
        long long b = count(4, odd);

        return (a * b) % mod;
    }
};