#include <ctype.h>
#include "sstring.h"

void stupr(char *str, size_t n) {
    for(int i = 0; i < n; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] ^= 1 << 5;
        else if ((unsigned) str[i] >= '\x7f') /* extended ASCII */
            str[i] = toupper(str[i]);
    }
}

void stlwr(char *str, size_t n) {
    for(int i = 0; i < n; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] ^= 1 << 5;
        else if ((unsigned) str[i] >= '\x7f') /* extended ASCII */
            str[i] = tolower(str[i]);
    }
}

int stloc(char *str, char *str_find) {
    int loc = strstr(str, str_find) - str;
    return loc;
}


// int main()
// {
//     char str[] = "pUsh";
//     int n = strlen(str);
//     stupr(str, n);
//     puts(str);
//     stlwr(str, n);
//     puts(str);
//     return 0; 
// }