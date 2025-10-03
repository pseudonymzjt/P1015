#include <stdio.h>
#include <string.h>

#define MAX_LEN 105

// Check if the digit array (len digits) is a palindrome
int is_palindrome(int a[], int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (a[i] != a[len - 1 - i])
            return 0;
    }
    return 1;
}

// Reverse b into a (both arrays of len digits)
void reverse(int a[], int b[], int len) {
    for (int i = 0; i < len; ++i) {
        a[i] = b[len - 1 - i];
    }
}

// Add a and b (both len digits, little-endian), store in res, return new length
int add(int a[], int b[], int len, int base, int res[]) {
    int carry = 0, i = 0;
    for (; i < len; ++i) {
        int s = a[i] + b[i] + carry;
        res[i] = s % base;
        carry = s / base;
    }
    while (carry) {
        res[i++] = carry % base;
        carry /= base;
    }
    return i;
}

// Convert string to digit array (little-endian)
void str2arr(char* s, int a[], int* len) {
    *len = strlen(s);
    for (int i = 0; i < *len; ++i) {
        char c = s[*len - 1 - i];
        if (c >= '0' && c <= '9') a[i] = c - '0';
        else a[i] = c - 'A' + 10;
    }
}

int main() {
    int k;
    char s[MAX_LEN];
    int a[MAX_LEN], b[MAX_LEN], c[MAX_LEN];
    int len, step = 0;

    scanf("%d", &k);
    scanf("%s", s);
    str2arr(s, a, &len);

    while (step <= 30) {
        if (is_palindrome(a, len)) {
            printf("STEP=%d\n", step);
            return 0;
        }
        reverse(b, a, len);
        int newlen = add(a, b, len, k, c);

        // Copy c to a, update len
        for (int i = 0; i < newlen; ++i) a[i] = c[i];
        len = newlen;

        ++step;
    }
    printf("Impossible!\n");
    return 0;
}