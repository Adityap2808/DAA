#include <stdio.h>

int main() {
    int n, i, flag = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n / 2; i++) {
        if(arr[i] != arr[n - i - 1]) {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        printf("The array is a palindrome array.\n");
    else
        printf("The array is not a palindrome array.\n");

    return 0;
}
