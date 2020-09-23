#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void substr(char *targ, const char* src, unsigned int start, unsigned int cnt) {
    strncpy(targ, src + start, cnt);
    targ[cnt] = 0;
}

int Bin2Dec(char *bin_str, int len) {
    // int len = strlen(bin_str);
    int base = 1, out_dec = 0;
    for (int i = len - 1; i >= 0; --i) {
        int dec =  bin_str[i] - '0';
        out_dec += dec * base;
        base *= 2;
    }
    return out_dec;
}

int Hex2Dec_ch(char hex_ch) {    
    if ((hex_ch >= '0' && hex_ch <= '9') || (hex_ch >= 'A' && hex_ch <= 'F') || (hex_ch >= 'a' && hex_ch <= 'f')) {
        int dec = hex_ch - '0'; 
        return dec <= 9 ? dec : dec - 7;
    }
    else 
        return 0;
} 

int Hex2Dec(char *hex_str, int len) {
    // int len = strlen(hex_str);
    int base = 1, out_dec = 0;
    for (int i = len - 1; i >= 0; --i) {    
        int dec = Hex2Dec_ch(hex_str[i]);
        out_dec +=  dec * base;
        base *= 16;  
    }
    return out_dec;
}

void Hex2Bin(char *hex_str, int len, char *bin)
{
    // int len = strlen(hex_str);   
    // char *bin = malloc((4 * len + 1) * sizeof(char));
    // bin[4 * len] = '\0';
    // if (!bin)
    //     return NULL;
    for (int i = 0; i < len; ++i) {
        int dec = Hex2Dec_ch(hex_str[i]);
        int idx = i * 4;
        for (int j = 3; j >= 0; --j) {    
            bin[idx] = (dec & (1 << j)) ? '1' : '0';
            idx ++;
        }
    }
    // return bin;
}

char *Hex2Ascii(char *hex_str, int len)
{    
    // int len = strlen(hex_str);
    int *dec_arr = malloc((len / 2));
    char *ascii = malloc((len / 2) + 1);
    ascii[len / 2] = '\0';
    for (int i = 0; i < len; i += 2) {
        char *part = malloc(3 * sizeof(char));
        part[2] = '\0';
        substr(part, hex_str, i, 2);
        dec_arr[i / 2] = (int)Hex2Dec(part, strlen(part));
        // printf("%d  ", dec_arr[i / 2]);
        ascii[i / 2] = (char)dec_arr[i / 2];
        // printf("%c \n", ascii[i / 2]);
        free(part);
    }
    free(dec_arr);
    return ascii;
}

const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void Bin2Base64(char *bin_str, int len, char *base64) {
    // int len = strlen(bin_str);
    int mod = len % 3;
    int len_64 = len + mod * 8;

    char *bin = malloc((len_64 + 1) *sizeof(char));
    bin[len_64] = '\0';
    for(int i = 0; i < mod; ++i)
        strcat(bin_str, "00000000");
    substr(bin, bin_str, 0, len_64);

    int len_base = len_64 / 6;
    // printf("%d\n", len_base);
    // char *base64 = malloc((len_base + 1) * sizeof(char));
    // char base64[255] = {};
    // base64[len_base] = '\0';

    for (int i = 0; i < len_64 - mod * 8; i += 6) {
        char *part = malloc(7 *sizeof(char));
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
    // puts(base64);

    // return base64;
   
}

int main()
{
    char str[2][255] = {"21232A30393C3F405B5E606F7E", "2123"};  //21232A30393C3F405B5E606F7E
    // char s[] = "21232A30393C3F405B5E606F7E";
    int len = strlen(str[0]);
    printf("%d\n", len);

    /*---------- dec ---------*/
    // for (int i = 0; i < len; ++i) {
    //     printf("%d", Hex2Dec_ch(str[i]));
    // }  
    // printf("%d", Hex2Dec(str));

    /*---------- bin ---------*/
    // char *bin = Hex2Bin(str);
    // printf("%s", bin);
    // int base = 0;
    // for (int i = 0; i < len * 4; ++i) {
    //     if (!(i % 4)) {
    //         puts(" ");
    //         printf("%c\n", str[i / 4 + (i % 4) * base]);
    //         base++;
    //     }
    //     printf("%c ", bin[i]);
    // }
    // puts(" ");
    // printf("%d", Bin2Dec(bin));

    /*---------- ascii ----------*/
    // char *ascii = Hex2Ascii(str);
    // for (int i = 0; i < len / 2; ++i)
    //     printf("%c ", ascii[i]);
    // puts(" ");
    
    /*---------- base64 ----------*/
    char base64[2][255] = {};
    char bin[2][255] = {};
    
    for (int i = 0; i < 2; ++i) {
        puts(str[i]);
        int len = strlen(str[i]);
        Hex2Bin(str[i], len, bin[i]);
        // puts(bin);
        // Bin2Base64(bin);
        Bin2Base64(bin[i], strlen(bin[i]), base64[i]);
        printf("%i, %s\n", i, base64[i]);
        // free(bin);
        // free(base64);
    }
    
    

    return 0;   
}




    