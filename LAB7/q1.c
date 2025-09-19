#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check_palindrome(char c[],int top,int size){
    char reversed[size],ori[size];
    strcpy(ori,c);
    int t =-1,t_o = top;
    //pop from the original and push into reverse
    while(t_o != -1){
        printf("%d",t_o);
        reversed[t_o--] = ori[++t];

    }
    while(top != -1){
            int i = top--;
        if(ori[i] != reversed[i]){
            return 0;
        }
    }
    return 1;

}

void main(){
     char c[] = "potp";
    int size = strlen(c);

    if (check_palindrome(c,3, size)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
