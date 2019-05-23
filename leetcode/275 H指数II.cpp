class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int res = n;
        int left = 0;
        int right = n - 1;
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(citations[mid] >= n - mid){
                right = mid - 1;
                res = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return n - res;
    }
};