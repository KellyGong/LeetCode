class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1) return 0;
        if(n < 10) return 1;
        
        string s = to_string(n);
        int length = s.size();
        
        int high = stoi(s.substr(0, 1), 0, 10);
        int low = stoi(s.substr(1, length - 1), 0, 10);
        int power = pow(10, length - 1);
        
        if(high == 1){
            return low + 1 + countDigitOne(power - 1) + countDigitOne(low);
        }
        else{
            return power + countDigitOne(low) + (high) * countDigitOne(power - 1);
        }
        return 0;
    }
};