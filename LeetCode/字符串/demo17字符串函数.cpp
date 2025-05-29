#include <bits/stdc++.h>

void my_strcpy(char *dst, char *src)
{
    if(dst == NULL || src == NULL)
        return;

    char *p = src;
    while (*p != '\0') {
        *dst++ = *p++;
    }
    *dst = '\0';
}

int my_strlen(char *str)
{
    if (str == nullptr) {
        return 0;
    }
    char *p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

void my_strcat(char *s1, char *s2)
{
    if(s1 == nullptr || s2 == nullptr)
        return;

    while (*s1 != '\0') {
        s1++;
    }
    char *p = s2;
    while (*p != '\0') {
        *s1++ = *p++;
    }
    *s1 = '\0';
}

int my_atoi (char* str)
{
    if(str == nullptr) {
        printf("Invalid Input\n");
        return 0;
    }
    const char* p = str;


    int sig = 1;
    while (*p == ' ')   p++;
    if(*p == '+')       p++;
    else if(*p == '-') {
        sig = -1;
        p++;
    } 
    int res = 0;
    while (*p != '\0')
    {
        if(*p >= '0' && *p <= '9')
            res = res * 10 + *p - '0';
        else {
            printf("Invalid Input\n");
            return -1;
        }
    }
    return res * sig;
}
