#include <numeric>
#include <vector>
#include <algorithm>

int noOfUnits(const std::vector<int>& C, int mid) {
    int units = 1;
    long long sum = 0;
    for(int i = 0; i < C.size(); i++) {
        if(C[i] + sum <= mid) {
            sum += C[i];
        } else {
            units++;
            sum = C[i];
        }
    }
    return units;
}

int Solution::paint(int A, int B, std::vector<int>& C) {
    int low = *max_element(C.begin(), C.end());
    int high = accumulate(C.begin(), C.end(), 0);
    long long mod = 10000003;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int minTime = noOfUnits(C, mid);
        if(minTime > A) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return (static_cast<long long>(low) * B) % mod;
}
