class Solution {
public:
    
    
    int longestValidParentheses(string s) {
        stack<int> t;
        int len = s.size();
        int res = 0;
        vector<bool> flag = vector(len, false);
        for(int i = 0; i < len; i++){
            if(s[i] == ')'){
                if(!t.empty()){
                    flag[t.top()] = true;
                    flag[i] = true;
                    t.pop();
                }
                
            }
            else{
                t.push(i);
            }
        }
        int count = 0;
        for(int i = 0; i < len; i++){
            if(flag[i] == false) count = 0;
            else {
                count++;
                res = max(res, count);
            }
        }
        return res;
    }
};