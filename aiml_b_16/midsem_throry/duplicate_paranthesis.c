#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_operand(char c){
    return ( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') );
}

int is_operator(char c){
    return (c=='+' ||c=='-' ||c=='*' ||c=='/' ||c=='^');

}


int  is_duplicate(char eq[], int n){
     int top = -1;
    int out = 1;
    char stack[n];

    char c;
    for(int i =0;i<n;i++){
        c = eq[i];
        if(c == '('|| c ==')'){
            if(c =='('){
                stack[++top]=c;
            }
            else{
                if(stack[top] == '('){
                    return 1;
                }
                else{
                while(top != -1 && stack[top] != '('){
                    top--;
                }

            }
            }
        }
        else{
            stack[++top] = c;
        }
    }
    return 0;
}

void main(){
    char exp[] = "a+s*(a-s)";
    int n = strlen(exp);
    printf("%d",is_duplicate(exp,n));
    printf("\n-------------------------------------------------------------------\n\n");
}