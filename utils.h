#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void alpha_sort(char arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

bool str_contain(const char* source, const char* text){
    char to_compare[99];
    strcpy(to_compare,source);
    char* compare = strtok(to_compare,", ");
    while (compare != NULL){
        if (strcmp(compare,text) == 0) return true;
        compare = strtok(NULL,", ");
    }
    return false;
}

bool equal_char_arr(const char arr[], const char arr2[]) {
    int len = strlen(arr);
    int len2 = strlen(arr2);
    if (len != len2) return false;
    char ch[9999];
    char ch2[9999];
    strcpy(ch, arr);
    strcpy(ch2, arr2);
    alpha_sort(ch, len);
    alpha_sort(ch2, len2);
    int i;
    bool result = true;
    for (i = 0; i < len; i++) {
        result = result && ch[i] == ch2[i];
    }
    return result;
}


int getlen(const char *str[]) {
    int i = -1;
    while (str[++i] != NULL) {}
    return i;
}

bool equal_char_arr2(char ch[], char ch2[]) {
    int i;
    int len = 0, len2 = 0;
    for (i = 0; i < strlen(ch); i++) {
        len += ch[i];
    }
    for (i = 0; i < strlen(ch2); i++) {
        len2 += ch2[i];
    }
    return len == len2 ? true : false;
}
