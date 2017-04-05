#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct datum {
    struct datum *ptr;
    int health;
};

void add(struct datum *data, char *str, int health) {
    int i = 0;
    while (str[i] != 0) {
        int o = str[i] - 'a';
        if (str[i+1] == 0) {
            data[o].health = health;
        } else {
            data[o].ptr = (struct datum *)calloc(26, sizeof(struct datum));
            data = data[o].ptr;
        }
        i++;
    }
}

int lookup(struct datum *data, char *str, int n) {
    int sum = 0;
    while (n > 0 && *str != 0) {
        int o = *str - 'a';
        sum += data[o].health;
        if (data[o].ptr != NULL) {
            data = data[o].ptr;
        } else {
            break;
        }
        str++;
        n--;
    }
    return sum;
}

int main(){
    struct datum *data;
    data = (struct datum *)calloc(26, sizeof(struct datum));

    int n;
    scanf("%d",&n);
    char* *genes = malloc(sizeof(char*) * n);
    for(int genes_i = 0; genes_i < n; genes_i++){
        genes[genes_i] = (char *)malloc(10240 * sizeof(char));
        scanf("%s",genes[genes_i]);
    }
    int *health = malloc(sizeof(int) * n);
    for(int health_i = 0; health_i < n; health_i++){
        scanf("%d",&health[health_i]);
    }

    for (int i = 0; i < n; i++) {
        add(data, genes[i], health[i]);
    }
    int greatest = 0;
    int least = INT_MAX;

    int s;
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        char* d = (char *)malloc(512000 * sizeof(char));
        scanf("%d %d %s",&first,&last,d);
        // your code goes here
        for (int i = first; i <= last; i++) {
            int val = lookup(data, d + first, last - first + 1);
            if (val > greatest) greatest = val;
            if (val < least) least = val;
        }
    }
    printf("%d %d\n", least, greatest);
    return 0;
}
