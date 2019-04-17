#include <stdio.h>
#include "utils1.h"
#include "seqlist_str.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

int main() {
    char original[999][99];
    char filter[999][99];
    FILE *fp = fopen("test.txt", "a+");
    char str[9999];
    char *compare;
    int i = 0, j = 0, l = 0, k = 0;
    while (fscanf(fp, "%s", str) != EOF) {
        //original[i] = str;
        if (containStr(str,original)) continue;
        strcpy(original[i],str);
        printf("added \"%s\"\n",original[i]);
        ++i;
    }
    fclose(fp);
    i = 0;
    for (int m = 0; m < getlength(original); m++) {
        printf("debug: original[%d] = %s\n",m,original[m]);
    }
    for (l = 0; l < getlength(original); ++l) {
        bool equal = false;
        bool contain = false;
        printf("handling %s\n",original[l]);
        for (j = 0; j < getlength(filter); j++) {
            printf("checking %s\n",filter[j]);
            char tempStr[9999];
            strcpy(tempStr,filter[j]);
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = filter[j]; //"abcd"
            if (strcmp(compare,original[l]) == 0) continue;
            printf("compare: %s vs %s (%s)\n",compare,original[l],filter[j]);
            equal = equal_char_arr(compare, original[l]);
            printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(filter[j],original[l]);
            printf("Checking contain :%s and %s\n",filter[j],original[l]);
            printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = filter[j]; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp,original[l]); // "abcd, bacd, abcd"
                strcpy(filter[j],temp);
                printf("filter[%d]: %s\n",j,filter[j]);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            strcpy(filter[i],original[l]);
            printf("added %s in filter \n",filter[i]);
            ++i;
        }
    }
    for (k = 0; k < getlength(filter); ++k) {
        printf("\n%s",filter[k]);
    }
    return 0;
}

int main22(){
    char **original = malloc(1000 * sizeof(*original));
    printf("length %d\n", getlength(original));
    original[0] = "hello";
    //strcpy(original[0],"hello");
    printf("length %d\n",getlength(original));
    original[1] = "world";
    printf("length %d\n",getlength(original));
    //strcpy(original[1],"world");
    original[2] = "shit";
    //strcpy(original[2],"shit");
    printf("length: %d\n",getlength(original));
    for (int i = 0; i < 3; ++i) {
        printf("%s\n",original[i]);
    }
    return 0;
}

int main222() {
    char **original = malloc(1000 * sizeof(*original));
    char **filter = malloc(1000 * sizeof(*filter));
    FILE *fp = fopen("test.txt", "a+");
    char str[9999];
    char *compare;
    int i = 0, j = 0, l = 0, k = 0;
    while (fscanf(fp, "%s", str) != EOF) {
        bool contain = containStr(str,original);
        printf("contain is %s\n",(contain ? "true" : "false"));
        if (contain) continue;
        original[i] = str;
        //strcpy(original[i],str);
        printf("added \"%s\"\n",original[i]);
        ++i;
    }
    fclose(fp);
    i = 0;
    for (int m = 0; m < getlength(original); m++) {
        printf("debug: original[%d] = %s\n",m,original[m]);
    }
    for (l = 0; l < getlength(original); ++l) {
        bool equal = false;
        bool contain = false;
        printf("handling %s\n",original[l]);
        for (j = 0; j < getlength(filter); j++) {
            printf("checking %s\n",filter[j]);
            char tempStr[9999];
            strcpy(tempStr,filter[j]);
            compare = strtok(tempStr, ", "); // "abcd, bacd"
            if (compare == NULL) compare = filter[j]; //"abcd"
            if (strcmp(compare,original[l]) == 0) continue;
            printf("compare: %s vs %s (%s)\n",compare,original[l],filter[j]);
            equal = equal_char_arr(compare, original[l]);
            printf("result: %s\n",(equal?"yes":"no"));
            //char *con = strstr(filter[j], original[l]);
            contain = str_contain(filter[j],original[l]);
            printf("Checking contain :%s and %s\n",filter[j],original[l]);
            printf("contain: %s\n",contain ? "true" : "false");
            if (equal){
                char *temp = filter[j]; // "abcd, bacd"
                char *dest = ", "; // ", "
                strcat(temp,dest); // "abcd, bacd, "
                //filter[j] = strcat(temp,dest);
                strcat(temp,original[l]); // "abcd, bacd, abcd"
                strcpy(filter[j],temp);
                printf("filter[%d]: %s\n",j,filter[j]);
                break;
            }
        }
        if (!equal && !contain) {
            //filter[i] = str;
            strcpy(filter[i],original[l]);
            printf("added %s in filter \n",filter[i]);
            ++i;
        }
    }
    for (k = 0; k < getlength(filter); ++k) {
        printf("\n%s",filter[k]);
    }
    return 0;
}


int shit(){
    ElementType as;
    ElementType *bs = (ElementType *) malloc(sizeof(ElementType));
    list string;
    initiate(&string);
    char str[9999];
    FILE *fp = fopen("test.txt","a+");
    int j = 1;
    while (fscanf(fp, "%s", str) != EOF) {
        add(&string,str);
        get(string,j,bs);
        printf("%d - %s\n",j,bs->text);
        ++j;
    }
    get(string,3,bs);
    printf("%d - %s\n",3,bs->text);
    printf("==========\n");
    for (int i = 1; i <= length(string); ++i) {
        get(string,i,bs);
        printf("%d - %s\n",i,bs->text);
    }
    printf("==========\n");

}