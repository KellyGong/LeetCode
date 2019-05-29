class Solution {
public:
    int result = INT_MIN;
    
    void deal(vector<int> &sum, int k){
        int len = sum.size();
        for(int i = 0; i < sum.size(); i++){
            int temp = 0;
            for(int j = i; j < sum.size(); j++){
                temp += sum[j];
                if(temp <= k) result = max(result, temp);
            }
        }
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        if(matrix.size() == 0) return 0;
        if(matrix[0].size() == 0) return 0;
        
        for(int i = 0; i < matrix.size(); i++){
            vector<int> highsum = vector(matrix[0].size(), 0);
            for(int j = i; j < matrix.size(); j++){
                for(int l = 0; l < matrix[0].size(); l++){
                    highsum[l] = highsum[l] + matrix[j][l];
                }
                deal(highsum, k);
            }
        }
        return result;
    }
};