#include <stdio.h>
#include <stdlib.h>

char* criarcadeiachar(char c){
    char* cadeiachar = (char*) malloc (sizeof(char));
    cadeiachar[0] = c;
    cadeiachar[1] = '\0';
    return cadeiachar;
}

int main(void) {
    char c;
    scanf("%c", &c);
    printf("%s", criarcadeiachar(c));
    return 0;
}
