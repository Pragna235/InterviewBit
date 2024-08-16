vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> final;
    for(int i=1;i<=A;i++){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1;col<i;col++){
            ans = ans * (i-col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        final.push_back(ansRow);
    }
    return final;
}
