class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       int high = matrix.size();
        if(high == 0) return 0;
       int width = matrix[0].size();
        if(width == 0) return 0;
        int res = 0;
        vector<int> h = vector(width, 0);
        vector<int> l = vector(width, 0);
        vector<int> r = vector(width, 0);
        for(int i = 0; i < high; i++){
            for(int j = 0; j < width; j++){
                if(matrix[i][j] == '1')h[j]++;
                else h[j] = 0;
            }
            for(int j = 0; j < width; j++){
                l[j] = j;
                r[j] = j;
            }
            for(int j = 0; j < width; j++){
                int k = j - 1;
                while(k >= 0 && h[k] >= h[j]){
                    l[j] = k;
                    k--;
                }
            }
            for(int j = width - 1; j >= 0; j--){
                int k = j + 1;
                while(k < width && h[k] >= h[j]){
                    r[j] = k;
                    k++;
                }
            }
            
            for(int j = 0; j < width; j++){
                res = max(res, h[j] * (r[j] - l[j] + 1));
            }
        }
        
        return res;
    }
};