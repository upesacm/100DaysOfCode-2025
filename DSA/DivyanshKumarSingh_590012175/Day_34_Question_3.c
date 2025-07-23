#include <stdio.h>

int isBinPal(int n)
{
    int l = 0, r;
    int temp = n;

    while (temp >>= 1)
        l++;

    r = 0;
    while (l > r)
    {
        int a = (n >> l) & 1;
        int b = (n >> r) & 1;
        if (a != b)
            return 0;
        l--;
        r++;
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isBinPal(n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
