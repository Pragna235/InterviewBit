int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int slow=A[0],fast=A[0];
    do{
        slow=A[slow];
        fast=A[A[fast]];
    }while(slow!=fast);
    fast=A[0];
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
}
