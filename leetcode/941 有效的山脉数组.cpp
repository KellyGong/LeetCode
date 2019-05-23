class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        bool flag = true;
        int index = -1;
        int i;
        for(i = 1; i < A.size() - 1; i++){
            if(A[i] <= A[i - 1] && flag) return false;
            else if(A[i] >= A[i - 1] && !flag) return false;
            if(A[i] > A[i - 1] && A[i] > A[i + 1]) flag = false;
        }
        if(A[i] < A[i - 1]) return true;
        else return false;
    }
};