class Solution {
    long long int M = 1000000007;
public:
    int countOrders(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            int temp = (i-1)*2 + 1;
            ans *= (temp+1) * temp / 2;
            ans %= M;
        }
        return (int) ans;

    }
    
};