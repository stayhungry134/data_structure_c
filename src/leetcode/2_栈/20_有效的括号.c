/**
 * name: 20_有效的括号
 * create_time: 2024/4/9 17:07
 * author: Ethan
 * 
 * Description: 
 */

#include "stdbool.h"
#include "stdlib.h"
#include "string.h"


bool isValid(char* s) {
    char stack[10000] = {};
    int top = -1;
    for (int i = 0; i < strlen(s); ++i) {
        if(s[i] == ')'){
            if(stack[top] != '(') return false;
            else top--;
            continue;
        }if(s[i] == ']'){
            if(stack[top] != '[') return false;
            else top--;
            continue;
        }if(s[i] == '}'){
            if(stack[top] != '{') return false;
            else top--;
            continue;
        }
        stack[top+1] = s[i];
        top++;
    }
    return true;
}