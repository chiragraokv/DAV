#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct stack{
    char data;
    struct stack* next;
}stack;

stack* push(char d,stack* head){
    stack* new_element = (stack*)malloc(sizeof(stack));
    new_element->data = d;
    new_element->next = head;
    return new_element;
}
bool is_char(char c){
    if(c>'a'&&c<'z'|| c>'A' && c<'Z'){
        return true;
    }
    else false;
}

bool is_operator(char c){
    if(c == '-'||c == '+'||c == '/'||c == '*'||c == '^'){
        return true;
    }
    return false;
}

char pop(stack* head){
    char d ;
    if(head != NULL){
    stack* remove = head;
    d= remove->data;
    head = head->next;
    free(remove);
    }
    else{
        printf("alr empty");
        return ;
    }
    return d;
}
void main(){


    }

