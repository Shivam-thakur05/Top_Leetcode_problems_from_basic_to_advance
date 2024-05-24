//first method - using simple iterative approach

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i <  strs[0].length(); i++){
            //take first character of firdst string and check with each string to present or not
            char ch = strs[0][i];
            bool isPresent = true;
            for(int j = 1; j < strs.size(); j++){
                //first check for not present
                if(ch != strs[j][i] || strs[j].size() < i){
                    isPresent = false;
                    break;
                }
            }
            if(isPresent){
                ans.push_back(ch);
            }
            else{
                break;
            }
        }
        return ans;
    }
};


//second approach - using trie data structure

class TrieNode{
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    int childCnt;

    TrieNode(char d){
        this->ch = d;
        this->isTerminal = false;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
        this->childCnt = 0;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // ek case solve baaki re sambhaal lega
        char ch = word[0];
        int index = ch-'a';
        TrieNode* child = NULL;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(ch);
            root->childCnt++;
            root->children[index] = child;
        }

        insertWord(child,word.substr(1));
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(int i=0;i<strs.size();i++){
            insertWord(root,strs[i]);
        }

        if(root->isTerminal) return "";

        string st = strs[0];
        string ans = "";

        for(int i=0;i<st.length();i++){
            char ch = st[i];
            int index = ch-'a';
            if(root->childCnt == 1 && root->children[index] != NULL){
                ans.push_back(ch);
                root = root->children[index];
                if(root->isTerminal) break;
            }
            else{
                break;
            }
        }

        return ans;
    }
};
