int mergeAndCount(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int inv_count = 0;

    // Merge and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            inv_count += (mid - left + 1);
            right++;
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy the remaining elements of right subarray, if any
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted subarray into original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return inv_count;
}

int mergeSortAndCount(vector<int> &arr, int low, int high) {
    if (low >= high) return 0;
    int mid = low + (high - low) / 2;
    int inv_count = 0;

    inv_count += mergeSortAndCount(arr, low, mid);
    inv_count += mergeSortAndCount(arr, mid + 1, high);
    inv_count += mergeAndCount(arr, low, mid, high);

    return inv_count;
}

int Solution::countInversions(vector<int> &A) {
    return mergeSortAndCount(A, 0, A.size() - 1);
}
