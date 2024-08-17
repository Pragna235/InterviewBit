vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int n = A.size();
    
    for(int i=0;i<n;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && A[j]==A[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = A[i]+A[j];
                sum+=A[k];
                sum+=A[l];
                if(sum<B) k++;
                else if(sum>B) l--;
                else{
                    vector<int> temp = {A[i],A[j],A[k],A[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k<l && A[k]==A[k-1]) k++;
                    while(k<l && A[l]==A[l+1]) l--;
                }
            }
        }
    }
    return ans;
}
