class Solution {
public:
  
    typedef struct node {
    int x;
    int y;
    }node;
    
    vector<vector<string>> result;
    vector<node> Queens;


    bool check(int k, int m, int n) {
        for (int i = k - 1; i >= 0; i--) {
            // if(Current[i][m] == 'Q') return false;
            if (Queens[i].y == m) return false;
            else if (Queens[i].y - m == k - i) return false;
            else if (Queens[i].y - m == i - k) return false;

        }
        return true;
    }
    
    void IterSolve(int k, int n) {
        if (k == n) {
            string temp(n, '.');
            vector<string> Current(n, temp);
            for (int i = 0; i < Queens.size(); i++) {
                Current[Queens[i].x][Queens[i].y] = 'Q';
            }
            result.push_back(Current);
        }

        else {
            for (int i = 0; i < n; i++) {
                if (check(k, i, n)) {
                    Queens.push_back({ k, i });
                    IterSolve(k + 1, n);
                    Queens.pop_back();
                }
            }
        }
    }


    
    vector<vector<string>> solveNQueens(int n) {
        IterSolve(0, n);        
        return result;
    }
};