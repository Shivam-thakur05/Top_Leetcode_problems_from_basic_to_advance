class Solution {
public:
    bool rotateString(string s, string goal) {
        int firstMatch = 0;
        if(s.length() != goal.length()) return false;
        int n = s.length();

        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp.push_back(goal[(j+i)%n]);
            }
            cout<<temp<<endl;
            if(s == temp) return true;
        }
        return false;
    }
};
