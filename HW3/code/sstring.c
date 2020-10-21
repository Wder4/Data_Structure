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

void substr(char *targ, const char* src, unsigned int start, unsigned int cnt) {
    strncpy(targ, src + start, cnt);
    targ[cnt] = 0;
}

int stloc(char *str, char *str_find) {
    int loc = strstr(str, str_find) - str;
    return loc;
}

void ltrim(char *str) {
	if (str == NULL || *str == '\0')
		return;
	int len = 0;
	char *p = str;
	while (*p != '\0' && isspace(*p)) {
		++p;
		++len;
	}
	memmove(str, p, strlen(str) - len + 1);
}

void rtrim(char *str) {
	if (str == NULL || *str == '\0')
		return;
	int len = strlen(str);
	char *p = str + len - 1;
	while (p >= str  && isspace(*p)) {
		*p = '\0';
		--p;
	}
}

void trim(char *str) {
    rtrim(str);
    ltrim(str);
}