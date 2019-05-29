class Solution {
public:
    typedef struct node{
        int index;
        int value;
        
        friend bool operator < (node n1, node n2){
            return n1.value < n2.value;
        }
    }node;
    
    int candy(vector<int>& ratings) {
        vector<node> order;
        int res = 0;
        for(int i = 0; i < ratings.size(); i++){
            order.push_back({i, ratings[i]});
        }
        sort(order.begin(), order.end());
        
        vector<int> distr = vector(ratings.size(), 1);
        
        for(int i = 0; i < ratings.size(); i++){
            int id = order[i].index;
            if(id - 1 >= 0 && ratings[id] > ratings[id - 1]){
                distr[id] = max(distr[id], distr[id - 1] + 1);
            }
            if(id + 1 < ratings.size() && ratings[id] > ratings[id + 1]){
                distr[id] = max(distr[id], distr[id + 1] + 1);
            }
        }
        
        for(int i = 0; i < distr.size(); i++){
            res += distr[i];
        }
        
        return res;
    }
};