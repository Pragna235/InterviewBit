int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]==B) return mid;
        if(A[low]<=A[mid]){
            if(A[low]<=B && B<=A[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(A[mid]<=B && B<=A[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}
