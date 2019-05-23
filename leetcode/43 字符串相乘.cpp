class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string res;
        
        vector<int> number1;
        vector<int> number2;
        for(int i = n1 - 1; i >= 0; i--){
            number1.push_back((int)(num1[i] - '0'));
        }
        for(int i = n2 - 1; i >= 0; i--){
            number2.push_back((int)(num2[i] - '0'));
        }
        vector<int> result(230, 0);
        int temp, k;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                result[i + j] += number1[i] * number2[j];
            }
        }
        int resultlength = 0;
        for(; resultlength < 229; resultlength++){
            result[resultlength + 1] += result[resultlength] / 10;
            result[resultlength] = result[resultlength] % 10;
        }
        
        k = resultlength - 1;
        while( k >= 0 && result[k] == 0){
            k--;
        }
        
        for(; k >= 0; k--){
            res += (char)('0' + result[k]);
        }
        if(res.size() == 0) res += '0';
        return res;
    }
};