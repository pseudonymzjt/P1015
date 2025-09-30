#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int main() {
    int N;
    char a[200] = { '0' };
    char r[200] = { '0' };
    scanf("%d%s", &N, a);
    int i;
    int len = strlen(a);
    for (i = 0; i < len; ++i) {
        if (a[i] <= '9' && a[i] >= '0')
            a[i] -= '0';
        else {
            a[i] = a[i] - 'A' + 10;
        }
    }
    int step = 0;
    for (;;) {
        for (i = 0; i < len; i++) {
            if (step % 2 == 0)
                r[i] = a[len - 1 - i];
            else
                a[i] = r[len - 1 - i];
        }
        if (strcmp(r, a) == 0) {
            printf("STEP=%d", step);
            break;
        }
        for (i = 0; i < len; i++) {
            r[i] += a[i];
            while (r[i] >= N) {
                r[i + 1]++;
                r[i] -= N;
            }
        }
        step++;
        len = strlen(r);
        if (step > 30) {
            printf("Impossible!");
            break;
        }
    }
    return 0;
}