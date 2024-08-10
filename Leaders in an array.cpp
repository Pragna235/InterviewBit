vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(A[i]>maxi){
            ans.push_back(A[i]);
        }
        maxi = max(maxi,A[i]);
    }
    return ans;
}
