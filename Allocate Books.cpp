#include<numeric>
int noOfStudents(vector<int> &A, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] + pagesStudent <= pages){
            pagesStudent += A[i];
        }
        else{
            students++;
            pagesStudent = A[i];
        }
    }
    return students;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B>n) return -1;
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int students = noOfStudents(A,mid);
        if(students>B){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
