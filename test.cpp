#include <stdio.h>


void check(char* s) {
    int flag = 0;
    for (int i = 0; i < 21; i++) 
        if (s[i] == '\0') {
            flag = 1;
            printf("%d", i);
        }
    if (flag) 
        printf("%s\n", s);
    else 
        printf("Строка не влезла\n");
}


int main() {
    char s[20];
    scanf("%s", s);
    check(s);

    return 0;
}