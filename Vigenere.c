#include <stdio.h>
#include <string.h>

//加密
int encrypt(char *text,char *result,char *k)
{
    int i,j=0,z=0;
    int m = strlen(k); //获取密钥的长度
    int l = strlen(text); //获取明文的长度
    for(i=0;i<l;i++)
    {
        //判断大小写
        if (text[i] >= 'A' && text[i] <= 'Z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-'A'+k[j]-'A')%26+'A';
            } else {
                result[z]=(text[i]-'A'+k[j]-'A')%26+'A';
            }
            j++;
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            } else {
                result[z]=(text[i]-'a'+k[j]-'a')%26+'a';
            }
            j++;
        } else{  //判断是否是空格
            result[z] = text[i];
        }
        z++;
    }
    return 0;
}

//解密
int decrypt(char *text,char *result,char *k)
{
    int i,j=0,z=0;
    int m = strlen(k); //获取密钥的长度
    int l = strlen(text); //获取密文的长度
    for(i=0;i<l;i++)
    {
        //判断是否是空格
        if (text[i] >= 'A' && text[i] <= 'Z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-k[j]+26)%26+'A';
            } else {
                result[z]=(text[i]-k[j]+26)%26+'A';
            }
            j++;
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            if(j==m){
                j=0;   //循环密钥
                result[z]=(text[i]-k[j]+26)%26+'a';
            } else {
                result[z]=(text[i]-k[j]+26)%26+'a';
            }
            j++;
        } else{
            result[z] = text[i];
        }
        z++;
    }
    return 0;
}

int main()
{
    char text[50]="";
    char result[50]="";
    char k[50]="";
    int type;
    int stop;
    /**欢迎**/
    printf("--------欢迎使用Vigenere密码-----------\n");
    printf("请填写明文或者密文\n");
    scanf("%[^\n]",text);
    printf("请选择加密方式，输入1加密，输入2解密\n");
    scanf("%d",&type);
    printf("请输入密钥k\n");
    scanf("%s",k);
    if(type == 1){
        /**加密**/
        encrypt(text,result,k);
        printf("明文%s的密文为:%s\n",text,result);
    }else if(type == 2){
        /**解密**/
        decrypt(text,result,k);
        printf("密文%s的明文为:%s\n",text,result);
    }

    scanf("%d",&stop);
    return 0;
}

