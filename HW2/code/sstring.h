#ifndef _SSTRING_
#define _SSTRING_
#include <string.h>

void stupr(char *str, size_t n);

void stlwr(char *str, size_t n);

void substr(char *targ, const char* src, unsigned int start, unsigned int cnt);

int stloc(char *str, char *str_find);

#endif