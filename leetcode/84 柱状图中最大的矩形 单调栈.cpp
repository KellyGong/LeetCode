class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        stack<int> s;     //保存序号
        for(int i = 0; i < heights.size(); i++){
            
            while(!s.empty() && heights[s.top()] > heights[i]){
                int index = s.top();
                s.pop();
                res = max(res, heights[index] * (s.empty()? i:(i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};