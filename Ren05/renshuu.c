#include <stdio.h>

struct test {
    char mem_1;
    int mem_2;
};

void main()
{
    struct test a[10];
    struct test *pa;                          // �\���̂̃|�C���^�ϐ���`
    pa = &a[0];    // �܂��� pa = a;     // �|�C���^�ϐ��� a �̃A�h���X����
    (pa + 1)->mem_1 = 'Z';// �|�C���^���g�p����'Z'����

	printf("%p\n%p\n",(pa+1),&a );

    printf("%c\n", a[1].mem_1);              // �\����a[1]��\��
    printf("%c\n", (pa + 1)->mem_1);   // �\����a[1]��\��
}