#include <stdio.h>

struct test {
    char mem_1;
    int mem_2;
};

void main()
{
    struct test a[10];
    struct test *pa;                          // 構造体のポインタ変数定義
    pa = &a[0];    // または pa = a;     // ポインタ変数へ a のアドレスを代入
    (pa + 1)->mem_1 = 'Z';// ポインタを使用して'Z'を代入

	printf("%p\n%p\n",(pa+1),&a );

    printf("%c\n", a[1].mem_1);              // 構造体a[1]を表示
    printf("%c\n", (pa + 1)->mem_1);   // 構造体a[1]を表示
}