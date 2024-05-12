//first approach good solution

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int>ans;
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += Arr[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-K];
    }
};

//second approach optimal solution

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        //create a descending priority queue
        priority_queue<int, vector<int>, greater<int>>mini;
        
        
         for(int i=0; i<N; i++){
            int sum=0;
            for(int j=i; j<N; j++){
                sum += Arr[j];
                //kth largest element wla concept
                if(mini.size() < K){
                    mini.push(sum);
                }
                else{
                    if(sum > mini.top()){
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }   
};
