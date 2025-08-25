#include <stdio.h>
#include <stdlib.h>
//Write a program to perform following string operations without using string
//handling functions:
//a.) length of the string
//b.) string concatenation
//c.) string comparison
//d.) to insert a sub string
//e.) to delete a substring

int length(char *s){
    char c = *s;
    int i = 0;
    while(c != '\0'){
        i++;
        c = *(s+i);
    }
    return i;
}
char concat(char s1[],char s2[]){
    int i,j,k;
    i = length(s1);
    j = length(s2);
    char result[i+j+1];
    for(k = 0;k<i;k++){
        result[k] = s1[k];
    }
    for(int l = 0;l<j;l++){
        result[k+l] = s2[l];
    }
    return result;
}
void delete_str(char *s,char del[]){
     int l = length(del),flag,pos;
    char c = *s;
    int j = 0;
    while(c != '\0'){
        j++;
        c = *(s+j);
    }
    for(int i =0;i<j-l;i++){
        if(*(s+i) == del[0]){
                flag =1;
            for(int k = 0;k<l;k++){
                if(*(s+i+k) != del[k]){
                    flag = 0;
                }
            }
            if(flag == 1){
                pos = i;
            }
        }
    }
    if(flag == 0){
        printf("sub string not present");
    }else{
        for(int i = 0;i<l;i++){
            *(s+i) = *(s+pos+i);
        }
    }
}

void insert(char *s,char ins[],int pos){
    //move the characters before inserting
    int l = length(ins);
    char c = *s;
    int j = 0;
    while(c != '\0'){
        j++;
        c = *(s+j);
    }
    for(int i =j;i>=pos;i--){
        *(s+i+l) = *(s+i);
    }
    for(int i = 0;i<l;i++){
        *(s+pos+i) = ins[i];
    }
}
int compare(char s1[],char s2[]){
    int i = length(s1), j = length(s2);
    if(i!=j){
        return 0;
    }
    else{
    for(int k = 0;k<i;k++){
        if(s1[k]!= s2[k]){
            return 0;
        }
    }
    return 1;
    }
}

int main()
{
    char str1[100],str2[100];
    printf("Enter a string: ");
    gets(str1);
    printf("Enter a string 2: ");
    gets(str2);
    printf("String %s length: %d\n",str1,length(str1));
    //printf("after concat %s",concat(str1,str2));
    if(compare(str1,str2)){
        printf("same strings\n");
    }
    else{
        printf("different string\n");
    }
    printf("insert string2 in string1 at position:  ");
    int pos;
    scanf("%d",&pos);
    if(pos <= length(str1)){
        insert(str1,str2,3);
        printf("string after insertion %s\n",str1);

    }
    else{
        printf("wrong position: out of bound.\n");
    }
    delete_str(str1,str2);
    printf("after deleting string2 from string1 %s",str1);


    return 0;
}
