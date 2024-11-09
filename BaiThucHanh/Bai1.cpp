#include <stdio.h>

// Hàm để tìm vị trí của ký tự 'p' trong mảng
void findPosition(char array[], int size, char target) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            printf("Vi tri cua '%c' trong mang la %d\n", target, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khi tu '%c' khong ton tai trong mang.\n", target);
    }
}

int main() {
    char array[6] = {'A', 'p', 't', 'e', 'c', 'h'};
    int size = sizeof(array) / sizeof(array[0]);

    //for
    printf("for :\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu %d cua mang la %c\n", i + 1, array[i]);
    }

    //while
    printf("while :\n");
    int j = 0;
    while (j < size) {
        printf("Phan tu %d cua mang la %c\n", j + 1, array[j]);
        j++;
    }

    //dowhile
    printf("do while :\n");
    int k = 0;
    do {
        printf("Phan tu %d cua mang la %c\n", k + 1, array[k]);
        k++;
    } while (k < size);

    //tim vi tri cua p
    printf("\nTim vi tri cua 'p':\n");
    findPosition(array, size, 'p');

    return 0;
}
