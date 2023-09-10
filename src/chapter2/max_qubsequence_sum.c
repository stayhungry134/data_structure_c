//
// Created by stayh on 2023/9/10.
//
// 最大子序列和
int max_subsequence_sum(const int A[], int n){
    int this_sum, max_sum;

    max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this_sum = 0;
            for (int k = 0; k < j; k++) {
                this_sum += A[k];

                if (this_sum > max_sum) {
                    max_sum = this_sum;
                }
            }
        }
    }
    return max_sum;
}

// 最大子序列优化算法
int max_subsequence_sum1(const int A[], int n){
    int this_sum, max_sum;
    for (int i = 0; i < n; i++) {
        this_sum = 0;
        for (int j = 0; j < n; j++) {
            this_sum += A[j];

            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}