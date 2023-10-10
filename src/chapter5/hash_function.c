//
// Created by Ethan on 2023/10/10.
//
typedef unsigned  int Index;

Index Hash(const char *key, int table_size){
    unsigned int hash_val = 0;
    /// 这里是要给一个字符串计算哈希值，在C语言中，字符串像又多个字符组成的数组，所以要先把所有字符串的值都算进去
    /// 在这里实际上是取到字符的ASCII码，然后加起来
    while (key != '\0'){
        hash_val += *key++;
    }
    return hash_val % table_size;
}