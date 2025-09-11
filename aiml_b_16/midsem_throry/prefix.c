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
int compare_precedence(char c1, char c2) {
        /*
    the predecence comparision: to either pop or push
    if the top has higher precedence then pop;
    if same precedence then:
        if ^ operator than pop
        else for all operatrs dont pop
    */
    int p1 = precedence(c1);
    int p2 = precedence(c2);
    if (p1 == p2) {
        if (p1 == 3) return 1; // ^ is right-associative → don't pop
        return 0;              // +,-,*,/ are left-associative → don't pop immediately
    }
    return (p1 > p2);
}

int evaluate(char c, int a ,int b){
    switch (c)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '/':
        return a/b;
        break;
    case '*':
        return a*b;
        break;
    case '^':
        return a^b;
        break;
    default:
    return 0;
        break;
    }

}

void reverse(char exp[]) {
    int n = strlen(exp);
    char output[n + 1];   // +1 for '\0'

    for (int i = 0; i < n; i++) {
        char c = exp[n - 1 - i]; // reverse order
        if (c == '(')
            output[i] = ')';
        else if (c == ')')
            output[i] = '(';
        else
            output[i] = c;
    }

    output[n] = '\0'; // null terminate
    strcpy(exp, output);
}


void infix_to_prefix(char poly[],int n){
    // make a array stack
    int top = -1;
    int out = 0;
    char stack[n];
    char output[n+1];
    output[out] = '\0';
    reverse(poly);
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
    int eval[n];
    int top_e = -1;
    for(int i =0;i<n;i++){
        char c = output[i];
        if(is_operand(c)){
            int num = c -'0';
            eval[++top_e] = num;
        }
        else if(is_operator(c)){
            int a = eval[top_e--];
            int b = eval[top_e --];

            eval[++top_e] = evaluate(c,a,b);
        }
    }
    int sol = eval[top_e];
    printf("%d\n\n",sol);

   int f = strlen(output);
    for (int i = 0; i < f /2; i++) {
        char tmp = output[i];
        output[i] = output[f - 1 - i];
        output[f - 1 - i] = tmp;
    }
    printf("%s",output);
}


int main() {
    char exp[] = "4+2-(6/3)";         // string, null-terminated
    int n = strlen(exp);          // get length of expression

    infix_to_prefix(exp, n);  
    printf("\n\n-------------------------------------------------------------------------\n");
    return 0;
}
/*
reverse with bracket
postfix with swapped equal precedence logic
reverse
*/