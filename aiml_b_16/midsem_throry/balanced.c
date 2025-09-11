#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_paranthesis(char c){
    return (c == '{'||c == '['||c == '('||c == ')'||c == ']'||c == '}');
}
int is_open(char c){
    return (c == '{'||c == '['||c == '(');
}
char get_paranthesis(char c){
    if(c ==')')return '(';
    else if(c =='}')return '{';
    else if(c ==']')return '[';
}

int is_balanced(char exp[],int n){
    int top = -1;
    int out = 1;
    char stack[n];

    char c;
    for(int i =0;i<n;i++){
        c = exp[i];
        if(is_paranthesis(c)){
            if(is_open(c)){
                stack[++top] = c;
            }
            else{
                if(top == -1){
                    return 0;
                }
                if(stack[top]== get_paranthesis(c)){
                    top --;
                    continue;
                }
                else return 0;
            }
        }

    }
    return 1;
}


int main() {
    char exp[] = "{a/(b+c)+44-f^d-1}";         // string, null-terminated
    int n = strlen(exp);          // get length of expression

    printf("%d",is_balanced(exp, n));  
    printf("\n\n-------------------------------------------------------------------------\n");
    return 0;
}