#include<numeric>

int days(vector<int> &A, int cap){
    int load=0,day=1;
    for(int i=0;i<A.size();i++){
        if(load+A[i] > cap){
            day+=1;
            load=A[i];
        }
        else{
            load+=A[i];
        }
    }
    return day;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    
    while(low<=high){
        int mid = (low+high)/2;
        if(days(A,mid)<=B){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
