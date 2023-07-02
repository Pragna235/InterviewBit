int Solution::majorityElement(const vector<int> &A) {
    int maxi=A[0],max_count=1;

    for(int i=1;i<A.size();i++){
        if(A[i]==maxi){
            max_count++;
        }
        else{
            max_count--;
            if(max_count==0){
                maxi=A[i];
                max_count=1;
            }
        }
    }
    return maxi;
}

