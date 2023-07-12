
// This function checks if a given string is 1 or not. 
// In case of 1 it returns true.
bool isOne(string a){
    int n = a.size();
    for(int i=0; i<n-1; i++)
        if(a[i] != '0') return false;
    if(a[n-1] == '1') return true;
    return false;
}

// This function divides the given string by 2, and return the result.
string divisionByTwo(string &a){
    int carry = 0;
    string temp = "";
    int n = a.size();
    for(int i=0; i<n; i++){
        temp.push_back('0' + carry+(a[i] - '0')/2);
        carry = (a[i] - '0')%2 == 1 ? 5: 0;
    }
    return temp;
}
int Solution::power(string a) {
    int n = a.size();
    
    int j=0;
    while(a[j] == '0') j++; 
    // If the number is 1 initially, that means k=0, therefore return 0.
    if(isOne(a)) return 0;
    
    // Divide the number until it becomes 1.
    while(!isOne(a)){
        // In case the number is not divisible by 2 then return 0.
        if((a[n-1] - '0')%2 == 1) return 0;
        a = divisionByTwo(a);
    }
    // We reach here that means the string is a power of 2.
    return 1;
}
