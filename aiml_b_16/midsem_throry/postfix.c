#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_operand(char c){
    return ( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') );
}

int is_operator(char c){
    return (c=='+' ||c=='-' ||c=='*' ||c=='/' ||c=='^');

}

int precedence(char c){
    if(c=='+' || c=='-') return 1;
    else if(c == '*' || c=='/') return 2;
    else if(c =='^') return 3;
    else return 0;
}

int compare_precedence(char c1,char c2){
    /*
    the predecence comparision: to either pop or push
    if the top has higher precedence then pop;
    if same precedence then:
        if ^ operator than dont pop
        else for all operatrs pop
    */
    int p1 = precedence(c1);
    int p2 = precedence(c2);
    if(p1 == p2){
        if(p1 == 3)
        return 0;
        return 1;
    }
    return (p1>p2);
}

void infix_to_postfix(char poly[],int n){
    // make a array stack
    int top = -1;
    int out = 1;
    char stack[n];
    char output[n+1];
    output[0] = '\0';

    char c;
    for(int i =0;i<n;i++){
        c = poly[i];
        if(is_operand(c)) {
            output[out++] = c;
        }
        else if(is_operator(c)){
            while(top != -1 && compare_precedence(stack[top],c)){
                // if the predecence of the operator alr in the stack is higher then, pop it till a lower precedence is found
                output[out++] = stack[top--];
            }
            stack[++top] = c;
        }
        else if(c == '('){
            // of a ( is found push it in stack
            stack[++top] = c;
        }
        else if(c == ')'){
            // if a closing bracket is found pop until ) is found and pop ) into output 
            while(top != -1 && stack[top] !='('){
                output[out++] = stack[top--];
            }
            top--;
        }
    }
    while (top != -1){
        output[out++] = stack[top--];
    }
   int i = 1; // start from last character (before '\0')

    for(int i = 0; i < out; i++){
    printf("%c", output[i]);
}

}

int main() {
    char exp[] = "a/(b+c)+44-f^d-1";         // string, null-terminated
    int n = strlen(exp);          // get length of expression

    infix_to_postfix(exp, n);  
    printf("\n\n-------------------------------------------------------------------------\n");
    return 0;
}
/*
Algorithm:
for element in expression
    if element is operand
    push it into output

    if element is operator
        compare the element with top of stack, if they have same preference or the top has a higher precedence then pop until a operator of lower preference is found in stack
    
    if opening bracket is found
        append it into the stack

    if a closing bracket is found 
        pop until opeing bracket
            add the tops into the output
        pop the opeining braket
while stack is not empty 
    append elements of stack to output

the output contains postfix expression is reverse format
*/