#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char hex[9];

  char* S_Box[16][16] = {
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}
};

  char* Rcon[10] = {"01000000", "02000000", "04000000", "08000000", "10000000",
                 "20000000", "40000000", "80000000", "1B000000", "36000000"};

void singleshift(char key[])
{
    char temp=key[0];
    int i;
    for(i=0;i<7;i++)
    {
        key[i]=key[i+1];
    }
    key[7]=temp;
    key[8]='\0';
}
void hextobin(char h[],char bin[])
{    bin[0]='\0';
     for(int i=0;i<8;i++)
    {
        switch(h[i])
        {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'A':
                strcat(bin, "1010");
                break;
            case 'B':
                strcat(bin, "1011");
                break;
            case 'C':
                strcat(bin, "1100");
                break;
            case 'D':
                strcat(bin, "1101");
                break;
            case 'E':
                strcat(bin, "1110");
                break;
            case 'F':
                strcat(bin, "1111");
                break;
        }

    }
    bin[32]='\0';
}
void bintohex(char a[])
{
    for(int i=0,j=0;i<32;i++)
    {   char word[5];
        word[0]=a[i++];
        word[1]=a[i++];
        word[2]=a[i++];
        word[3]=a[i];
        word[4]='\0';
        if(strcmp(word,"0000")==0)
        hex[j++]='0';
        else if(strcmp(word,"0001")==0)
        hex[j++]='1';
        else if(strcmp(word,"0010")==0)
        hex[j++]='2';
        else if(strcmp(word,"0011")==0)
        hex[j++]='3';
        else if(strcmp(word,"0100")==0)
        hex[j++]='4';
        else if(strcmp(word,"0101")==0)
        hex[j++]='5';
        else if(strcmp(word,"0110")==0)
        hex[j++]='6';
        else if(strcmp(word,"0111")==0)
        hex[j++]='7';
        else if(strcmp(word,"1000")==0)
        hex[j++]='8';
        else if(strcmp(word,"1001")==0)
        hex[j++]='9';
        else if(strcmp(word,"1010")==0)
        hex[j++]='A';
        else if(strcmp(word,"1011")==0)
        hex[j++]='B';
        else if(strcmp(word,"1100")==0)
        hex[j++]='C';
        else if(strcmp(word,"1101")==0)
        hex[j++]='D';
        else if(strcmp(word,"1110")==0)
        hex[j++]='E';
        else if(strcmp(word,"1111")==0)
        hex[j++]='F';
    }
    hex[8]='\0';

}
char* add(char a[], char b[])
{   char sin[33],bin2[33];
    hextobin(a,sin);
    hextobin(b,bin2);
    for(int i=0;i<32;i++)
    {
        sin[i]=((sin[i]-'0')^(bin2[i]-'0'))+'0';
    }
    bintohex(sin);
    return hex;
}

char* workit(char a[],char b[],int j)
{
    singleshift(a);
    singleshift(a);

    for(int i=0;i<8;i+=2)
    {
        char well[3];
        well[0]=a[i];
        well[1]=a[i+1];
        well[2]='\0';
        int x,y;
        switch(well[0])
        {case '0':x=0;
        break;
        case '1':x=1;
        break;
        case '2':x=2;
        break;
        case '3':x=3;
        break;
        case '4':x=4;
        break;
        case '5':x=5;
        break;
        case '6':x=6;
        break;
        case '7':x=7;
        break;
        case '8':x=8;
        break;
        case '9':x=9;
        break;
        case 'A':x=10;
        break;
        case 'B':x=11;
        break;
        case 'C':x=12;
        break;
        case 'D':x=13;
        break;
        case 'E':x=14;
        break;
        case 'F':x=15;
        break;
        }
        switch(well[1])
        {case '0':y=0;
        break;
        case '1':y=1;
        break;
        case '2':y=2;
        break;
        case '3':y=3;
        break;
        case '4':y=4;
        break;
        case '5':y=5;
        break;
        case '6':y=6;
        break;
        case '7':y=7;
        break;
        case '8':y=8;
        break;
        case '9':y=9;
        break;
        case 'A':y=10;
        break;
        case 'B':y=11;
        break;
        case 'C':y=12;
        break;
        case 'D':y=13;
        break;
        case 'E':y=14;
        break;
        case 'F':y=15;
        break;
        }
        strcpy(well,S_Box[x][y]);
        a[i]=well[0];
        a[i+1]=well[1];

    }
    a[8]='\0';
    strcpy(a,add(a,Rcon[j-1]));
    strcpy(a,add(a,b));
return a;
}

char* substitute(char a[])
{

    for(int i=0;i<8;i+=2)
    {
        char well[3];
        well[0]=a[i];
        well[1]=a[i+1];
        well[2]='\0';
        int x,y;
        switch(well[0])
        {case '0':x=0;
        break;
        case '1':x=1;
        break;
        case '2':x=2;
        break;
        case '3':x=3;
        break;
        case '4':x=4;
        break;
        case '5':x=5;
        break;
        case '6':x=6;
        break;
        case '7':x=7;
        break;
        case '8':x=8;
        break;
        case '9':x=9;
        break;
        case 'A':x=10;
        break;
        case 'B':x=11;
        break;
        case 'C':x=12;
        break;
        case 'D':x=13;
        break;
        case 'E':x=14;
        break;
        case 'F':x=15;
        break;
        }
        switch(well[1])
        {case '0':y=0;
        break;
        case '1':y=1;
        break;
        case '2':y=2;
        break;
        case '3':y=3;
        break;
        case '4':y=4;
        break;
        case '5':y=5;
        break;
        case '6':y=6;
        break;
        case '7':y=7;
        break;
        case '8':y=8;
        break;
        case '9':y=9;
        break;
        case 'A':y=10;
        break;
        case 'B':y=11;
        break;
        case 'C':y=12;
        break;
        case 'D':y=13;
        break;
        case 'E':y=14;
        break;
        case 'F':y=15;
        break;
        }
        strcpy(well,S_Box[x][y]);
        a[i]=well[0];
        a[i+1]=well[1];

    }
    a[8]='\0';
return a;
}

void cpy(char w[4][3],char ans[4][3]) {
    for(int i=0;i<4;i++) {
        strcpy(ans[i],w[i]);
    }
}

int strtoint(char c){
    if(c<='9'&&c>='0') return (int) (c - '0');
    return (int) (c -'A' + 10);
}
int strtonum(char s[3]) {
    int v1 = strtoint(s[0]);
    int v2 = strtoint(s[1]);
    return v1*16 + v2;
}

int galoismult(char a[3], int b) {
    int a1 = strtonum(a);
    int b1=b;
    int p = 0;
    int hi_bit = 0;
    for(int i = 0;i<8;i++) {
        if(b1&1==1) p^=a1;
        hi_bit = a1 & 0x80;
        a1 <<= 1;
        if(hi_bit == 0x80) a1 ^=0x1b;
        b1 >>=1;
    }
    int ans = p%256;
    return ans;
}

void mixColone(char column[4][3]) {
    char temp[4][3];
    cpy(column,temp);
    int a = galoismult(temp[0],2) ^ galoismult(temp[1],3) ^ galoismult(temp[2],1) ^ galoismult(temp[3],1);
    int b = galoismult(temp[0],1) ^ galoismult(temp[1],2) ^ galoismult(temp[2],3) ^ galoismult(temp[3],1);
    int c = galoismult(temp[0],1) ^ galoismult(temp[1],1) ^ galoismult(temp[2],2) ^ galoismult(temp[3],3);
    int d = galoismult(temp[0],3) ^ galoismult(temp[1],1) ^ galoismult(temp[2],1) ^ galoismult(temp[3],2);
    snprintf(column[0],3, "%02X", a);
    snprintf(column[1],3, "%02X", b);
    snprintf(column[2],3, "%02X", c);
    snprintf(column[3],3, "%02X", d);
}

void mixCol(char p[4][4][3]) {
    for(int i = 0;i<4;i++) {
        char col[4][3];
        for(int j = 0;j<4;j++) {
            strcpy(col[j],p[j][i]);
        }
        mixColone(col);
        for(int j = 0;j<4;j++) {
            strcpy(p[j][i],col[j]);
        }
    }
}


int main()
{ char plaintext[33];
  char initialkey[33];
  scanf("%s",plaintext);
  scanf("%s",initialkey);
  plaintext[strlen(plaintext)]='\0';
  initialkey[strlen(initialkey)]='\0';
 char keys[11][33];
 char w[43][9];
 int k=0;
 for(int i=0;i<8;i++,k++)
 {
     w[0][i]=initialkey[k];
 }
 w[0][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     w[1][i]=initialkey[k];
 }
 w[1][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     w[2][i]=initialkey[k];
 }
 w[2][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     w[3][i]=initialkey[k];
 }
 w[3][8]='\0';
strcpy(keys[0],initialkey);

 for(int i=1;i<11;i++)
 {
    char temp[9];
    strcpy(temp,w[(4*i)-1]);
    strcpy(w[(4*i)],workit(temp,w[(4*i)-4],i));
    strcpy(w[(4*i)+1],add(w[4*i],w[(4*i)-3]));
    strcpy(w[(4*i)+2],add(w[(4*i)+1],w[(4*i)-2]));
    strcpy(w[(4*i)+3],add(w[(4*i)+2],w[(4*i)-1]));
    int k=0;
    keys[i][0]='\0';
    strcat(keys[i],w[4*i]);
    strcat(keys[i],w[(4*i)+1]);
    strcat(keys[i],w[(4*i)+2]);
    strcat(keys[i],w[(4*i)+3]);
    keys[i][32]='\0';
    printf("%s\n",keys[i]);
 }
char plainword[4][9];
 k=0;
 for(int i=0;i<8;i++,k++)
 {
     plainword[0][i]=plaintext[k];
 }
 plainword[0][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     plainword[1][i]=plaintext[k];
 }
 plainword[1][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     plainword[2][i]=plaintext[k];
 }
 plainword[2][8]='\0';
 for(int i=0;i<8;i++,k++)
 {
     plainword[3][i]=plaintext[k];
 }
  plainword[3][8]='\0';
 strcpy(plainword[0],add(plainword[0],w[0]));
 strcpy(plainword[1],add(plainword[1],w[1]));
 strcpy(plainword[2],add(plainword[2],w[2]));
 strcpy(plainword[3],add(plainword[3],w[3]));
 for(int z=1;z<=10;z++)
 {
 for(int i=0;i<4;i++)
 {
    strcpy(plainword[i],substitute(plainword[i]));
 }
char matrix[4][4][3];
for(int i=0;i<4;i++)
{   k=0;
    for(int j=0;j<4;j++)
    {
        matrix[j][i][0]=plainword[i][k++];
        matrix[j][i][1]=plainword[i][k++];
        matrix[j][i][2]='\0';
    }
}
for(int t=0;t<3;t++)
{for(int i=1+t;i<4;i++)
 {    char tell[3];
     strcpy(tell,matrix[i][0]);
    for(int j=0;j<3;j++)
    {
     strcpy(matrix[i][j],matrix[i][j+1]);

    }
    strcpy(matrix[i][3],tell);
 }
}
if(z!=10)
{mixCol(matrix);
}
for(int i=0;i<4;i++)
{   k=0;
    for(int j=0;j<4;j++)
    {
        plainword[i][k++]=matrix[j][i][0];
        plainword[i][k++]=matrix[j][i][1];
    }

}
 strcpy(plainword[0],add(plainword[0],w[4*z]));
 strcpy(plainword[1],add(plainword[1],w[4*z+1]));
 strcpy(plainword[2],add(plainword[2],w[4*z+2]));
 strcpy(plainword[3],add(plainword[3],w[4*z+3]));
}
printf("%s%s%s%s\n",plainword[0],plainword[1],plainword[2],plainword[3]);

}
