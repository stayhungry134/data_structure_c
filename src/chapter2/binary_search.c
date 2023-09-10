//
// Created by stayh on 2023/9/10.
//
// 二分搜索
int binary_search(const int A[], int x) {
    int n = sizeof(A);
    int left, right, mid;
    left = 0;
    right = n - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(A[mid] > x){
            right = mid - 1;
        } else if(A[mid] < x){
            left = mid + 1;
        } else{
            return mid;
        }
    }
    return -1;
}