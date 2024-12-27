#include <stdio.h>
#include <stdlib.h>

// Hàm tạo và nhập giá trị cho ma trận
int** taoMaTran(int hang, int cot) {
    // Cấp phát bộ nhớ cho ma trận
    int** maTran = (int**)malloc(hang * sizeof(int*));
    for (int i = 0; i < hang; i++) {
        maTran[i] = (int*)malloc(cot * sizeof(int));
    }

    // Nhập giá trị cho từng phần tử trong ma trận
    printf("Nhập các giá trị cho ma trận (%dx%d):\n", hang, cot);
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Phần tử [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }

    return maTran;
}

// Hàm in ma trận ra màn hình
void inMaTran(int** maTran, int hang, int cot) {
    printf("Ma trận (%dx%d):\n", hang, cot);
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

// Giải phóng bộ nhớ của ma trận
void giaiPhongMaTran(int** maTran, int hang) {
    for (int i = 0; i < hang; i++) {
        free(maTran[i]);
    }
    free(maTran);
}

int main() {
    int hang, cot;
    printf("Nhập số hàng và số cột của ma trận: ");
    scanf("%d %d", &hang, &cot);

    // Tạo và in ma trận
    int** maTran = taoMaTran(hang, cot);
    inMaTran(maTran, hang, cot);

    // Giải phóng bộ nhớ
    giaiPhongMaTran(maTran, hang);

    return 0;
}
