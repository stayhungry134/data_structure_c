//
// Created by stayh on 2023/9/10.
//

// 欧几里得算法，求两个整数的最大公约数
unsigned int gcd(unsigned int m, unsigned  int n){
    unsigned int rem;
    while(n > 0){
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}