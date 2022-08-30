#include <stdio.h>

/* 这是书中 21 题的扩展部分，用一个函数指针来传入不同的比较操作，实现
 * 代码解耦，使得主体代码更加通用。另外，这个题还让我复习了一下函数指针的
 * 内容，一次编译通过，这让我感到快乐。 */

void divide_array(int *arr, int arr_size, int (*func)(int))
{
    if (arr == NULL || arr_size == 0)
        return;
    int p1, p2, tmp;

    p1 = 0;
    p2 = arr_size - 1;
    while (p1 < p2) {
        while (p1 < p2 && !func(arr[p1]))
            p1++;
        while (p1 < p2 && func(arr[p2]))
            p2--;
        if (p1 < p2) {
            tmp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = tmp;
        }
    }
}

int is_odd(int num)
{
    return num & 0x01;
}

int is_negative(int num)
{
    return num < 0;
}

int is_divided_three(int num)
{
    return num % 3;
}

struct {
    int arr[10];
    int arr_size;
    int (*func) (int);
} tests[] = {
    {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, is_odd},
    {{-1, 2, -3, 4, -5, 6, -7, 8, -9, 10}, 10, is_negative},
    {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, is_divided_three},
};

void print_arr(int *arr, int arr_size)
{
    int i;

    for (i = 0; i < arr_size; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void run_test()
{
    int i;

    for (i = 0; i < 3; i++) {
        printf("%d:\n", i);
        printf("Before:");
        print_arr(tests[i].arr, tests[i].arr_size);
        divide_array(tests[i].arr, tests[i].arr_size, tests[i].func);
        printf("After: ");
        print_arr(tests[i].arr, tests[i].arr_size);
        printf("\n");
    }
}

int main(void)
{
    run_test();
    return 0;
}
