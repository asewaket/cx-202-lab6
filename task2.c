#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *reverse_string(const char *str) {
    int len = string_length(str);
    char *rev_str = (char*)malloc((len + 1) * sizeof(char));

    if (rev_str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0, j = len - 1; i < len; i++, j--) {
        rev_str[i] = str[j];
    }
    rev_str[len] = '\0';

    return rev_str;
}

int main() {
    char *str, *rev_str;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = string_length(str);
    rev_str = reverse_string(str);

    printf("Reversed string: %s\n", rev_str);

    free(rev_str);

    return 0;
}
