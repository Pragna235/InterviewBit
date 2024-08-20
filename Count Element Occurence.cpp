int firstOccurrence(const vector<int> &arr, int n, int k){
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==k){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    int lastOccurrence(const vector<int> &arr, int n, int k){
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==k){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(const vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurrence(nums,n,target);
        if(first==-1) return {-1,-1};
        int last = lastOccurrence(nums,n,target);
        return {first,last};
    }
int Solution::findCount(const vector<int> &A, int B) {
    vector<int> temp = searchRange(A, B);
    if(temp[0]==-1) return 0;
    return temp[1]-temp[0]+1;
}
