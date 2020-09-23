# Compressor

## Why
There is an input file, say A, in which all characters are **Hex** digits (0-F). The input is not always an even number. It becomes impossible to print out the contents of file B whose size is just half of A due to the incompatibility with the definition of ASCII. 
To solve it, I adopt **BASE64** to transform the unprintable file B. As a result, the overall compression ratio would be 2/3, instead of 1/2.

## Enviroment
```
$ uname -a
MSYS_NT-10.0-19041 DESKTOP-L3NKTB9 3.1.6-340.x86_64 2020-07-09 14:33 UTC x86_64 Msys
$ gcc --version
gcc (MinGW.org GCC-6.3.0-1) 6.3.0
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Programs
`compressor.c`： compress the hex digits

`HexConvert.h`： the function of hex digits convertion

`HexConvert.c`： test for HexConvert.h

## Function
* transform hex digits to binary
```
Hex2Bin(char *hex_str, int str_len, char *bin) 
```
* transform binary digits to Base64
```
Bin2Base64(char *bin_str, int str_len, char *base64)
```

## Think
[Base64](https://en.wikipedia.org/wiki/Base64) 為 6 個 binary bit 為一組

所以先將 input 的 hex digits 轉成 binary，再 6 個為一組做轉換，而若轉換後的 binary 無法被 3 整除，先在末尾補足 0bit，使其能夠被 3 整除，再進行 Base64 編碼，編碼完後會剩下之前補足的 0bit，取 6 個一組轉換成 "="。

[Flow chart](https://github.com/Wder4/DS/blob/master/HW1/flowchart.jpg)

![](https://github.com/Wder4/DS/blob/master/HW1/flowchart.jpg?raw=true)

## Parameter
```
.\compressor -i <input file name> -o <output file name>
```

## Demo
* compress
```
$ .\compressor -i input.txt -o output.txt
```
* return file "output.txt" and print
```
option i: input.txt
21232A30393C3F405B5E606F7E
2123

option o: output.txt
ISMqMDk8P0BbXmBvfg==
ISM=
```
![](https://github.com/Wder4/DS/blob/master/HW1/demo.jpg?raw=false)
