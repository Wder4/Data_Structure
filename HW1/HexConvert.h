#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  get the substring
void substr(char *targ, const char* src, unsigned int start, unsigned int cnt) {
    strncpy(targ, src + start, cnt);
    targ[cnt] = 0;
}

// binary to decimal
int Bin2Dec(char *bin_str, int len) {
    // int len = strlen(bin_str);
    int base = 1, out_dec = 0;
    for (int i = len - 1; i >= 0; --i) {
        int dec =  bin_str[i] - '0';   // change to integer
        out_dec += dec * base;
        base *= 2;
    }
    return out_dec;
}

// hex to decimal in 1 char
int Hex2Dec_ch(char hex_ch) {    
    if ((hex_ch >= '0' && hex_ch <= '9') || (hex_ch >= 'A' && hex_ch <= 'F') || (hex_ch >= 'a' && hex_ch <= 'f')) {
        int dec = hex_ch - '0'; 
        return dec <= 9 ? dec : dec - 7;  // since A=17, B=18..., have to minus 7 
    }
    else 
        return 0;
} 

// hex to decimal in string
int Hex2Dec(char *hex_str, int len) {
    int base = 1, out_dec = 0;
    for (int i = len - 1; i >= 0; --i) {    
        int dec = Hex2Dec_ch(hex_str[i]);
        out_dec +=  dec * base;
        base *= 16;  
    }
    return out_dec;
}

// hex to binary
void Hex2Bin(char *hex_str, int len, char *bin)
{
    for (int i = 0; i < len; ++i) {
        int dec = Hex2Dec_ch(hex_str[i]);
        int idx = i * 4;
        for (int j = 3; j >= 0; --j) {    
            bin[idx] = (dec & (1 << j)) ? '1' : '0';  // bitwise
            idx ++;
        }
    }
}

// hex to ASCII
void Hex2Ascii(char *hex_str, int len, char *ascii)
{    
    int *dec_arr = malloc((len / 2));
    for (int i = 0; i < len; i += 2) {
        char *part = malloc(3 * sizeof(char));
        part[2] = '\0';
        substr(part, hex_str, i, 2);
        dec_arr[i / 2] = (int)Hex2Dec(part, strlen(part));
        ascii[i / 2] = (char)dec_arr[i / 2];
        free(part);
    }
    free(dec_arr);
}

// base64 index table
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// binary to  base64
void Bin2Base64(char *bin_str, int len, char *base64) {
    int mod = len % 3;
    int len_64 = len + mod * 8;

    char *bin = malloc((len_64 + 1) *sizeof(char));
    bin[len_64] = '\0';
    for(int i = 0; i < mod; ++i)
        strcat(bin_str, "00000000");
    substr(bin, bin_str, 0, len_64);

    int len_base = len_64 / 6;
    for (int i = 0; i < len_64 - mod * 8; i += 6) {
        char *part = malloc(7 *sizeof(char));   // 6 bits to base64
        part[6] = '\0';
        substr(part, bin_str, i, 6);
        // puts(part);
        int dec = Bin2Dec(part, strlen(part));
        base64[i / 6] = (char)base64_table[dec];
        // printf("%c\n\n", base64_table[dec]);
        free(part);
    }
    if (mod > 0)
        base64[len_base - 1] = '=';
    if (mod > 1)
        base64[len_base - 2] = '=';
}






    