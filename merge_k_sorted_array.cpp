//first approach 

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[0].size(); j++){
                ans.push_back(arr[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//second approach

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<K;j++)
            {
                minh.push(arr[i][j]);
            }
            
        }
        vector<int>res;
        while(!minh.empty())
        {
            res.push_back(minh.top());
            minh.pop();
        }
        return res;
    }
};
