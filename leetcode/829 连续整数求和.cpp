class Solution {
public:
    int consecutiveNumbersSum(int N) {
        N = 2 * N;
        int res = 0;
        for(int i = 1; i <= sqrt(N); i++){
            if(N % i == 0){
                int temp = N / i + 1 - i;
                if(temp % 2 == 0 && temp > 0){
                    res++;
                }
            }
        }
        return res;
    }
};