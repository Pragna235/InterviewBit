int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int low=0,high=n-1,ans=INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[low]<=A[high]){
            ans = min(ans,A[low]);
            return ans;
        }
        if(A[low]<=A[mid]){
            ans = min(ans,A[low]);
            low=mid+1;
        }
        else{
            ans = min(ans,A[mid]);
            high=mid-1;
        }
    }
    return ans;
}
