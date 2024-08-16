int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    long ans=INT_MAX/2;
    int n = A.size();
    
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            long x = A[i] + A[j] + A[k];
            if(abs(x-B) < abs(ans-B)) ans = x;
            if(x>B) k--;
            else j++;
        }
    }
    return ans;
}
