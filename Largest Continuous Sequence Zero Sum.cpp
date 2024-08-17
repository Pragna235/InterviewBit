vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> mpp;
    int n = A.size();
    int sum = 0, start = -1, end = -1;
    int maxi = 0;
    
    mpp[0] = -1; // to handle cases where subarray starts from index 0
    
    for(int i=0; i<n; i++){
        sum += A[i];
        
        if(mpp.find(sum) != mpp.end()){
            int len = i - mpp[sum];
            if(len > maxi){
                maxi = len;
                start = mpp[sum] + 1;
                end = i;
            }
        } else {
            mpp[sum] = i;
        }
    }
    
    vector<int> ans;
    if(start != -1 && end != -1){
        for(int i = start; i <= end; i++){
            ans.push_back(A[i]);
        }
    }
    
    return ans;
}
