#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "HexConvert.h"

void p_usage() {
    printf("usage: .\\compressor -i <txt>\n");
    exit(2);
}

int main(int argc, char **argv) {
    if (argc < 2)
        p_usage();
    int ch, str_num = 0;
    char out_str[200][200] = {};
    while((ch = getopt(argc, argv, "i:o:")) != -1) {
        switch(ch) {
            case 'i':
                printf("option i: %s\n", optarg);
                FILE *ifp = NULL;
                char str[255][255] = {};
                char out_str[255][255] = {};
                char bin[255][255] = {};
                int i = 0;

                ifp = fopen(argv[2], "r");
                while (!feof(ifp)) {
                    fgets(str[i], 255, ifp);
                    str[i][strlen(str[i]) - 1] = '\0';   // remove "\n"
                    puts(str[i]);
                    int len = strlen(str[i]);
                    if (len <= 0)
                        break;
                    Hex2Bin(str[i], len, bin[i]);
                    Bin2Base64(bin[i], strlen(bin[i]), out_str[i]);
                    ++i;
                }
                str_num = i;             
                fclose(ifp);
                break;

            case 'o':
                printf("option o: %s\n", optarg);
                FILE *ofp = NULL;
                ofp = fopen(optarg, "w");
                for (int i = 0; i < str_num; ++i) {
                    puts(out_str[i]);
                    fwrite(out_str[i], 1, strlen(out_str[i]), ofp);
                    fwrite("\n", 1, strlen("\n"), ofp);
                }
                fclose(ofp);
                break;

            case '?': 
                printf("unknown option \n");
                break;

            default:
                printf("default \n");
        }
    }
}


