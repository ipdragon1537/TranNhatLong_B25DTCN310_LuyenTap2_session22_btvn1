#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;
Student ds[MAX];
int n = 0;
void xoaEnter() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void nhapMotHocSinh() {
    if (n >= MAX) {
        printf("Danh sach da day!\n");
        return;
    }
    printf("Nhap thong tin hoc sinh thu %d:\n", n+1);
    printf("  Ho ten: ");
    fgets(ds[n].name, sizeof(ds[n].name), stdin);
    ds[n].name[strcspn(ds[n].name, "\n")] = 0;
    printf("  Tuoi   : ");
    scanf("%d", &ds[n].age);
    printf("  Diem   : ");
    scanf("%f", &ds[n].grade);
    xoaEnter();
    n++;
    printf("Them hoc sinh thanh cong!\n\n");
}
void nhapDanhSach() {
    int k;
    printf("Ban muon nhap bao nhieu hoc sinh? ");
    scanf("%d", &k);
    xoaEnter();
    
    for(int i = 0; i < k; i++) {
        nhapMotHocSinh();
    }
}
void hienThiDanhSach() {
    if (n == 0) {
        printf("Chua co hoc sinh nao trong danh sach!\n\n");
        return;
    }
    
    printf("\n=== DANH SACH HOC SINH ===\n");
    printf("%-5s | %-25s | %-6s | %-6s\n", "STT", "Ho ten", "Tuoi", "Diem");
    printf("-----------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-5d | %-25s | %-6d | %-6.2f\n", 
               i+1, ds[i].name, ds[i].age, ds[i].grade);
    }
    printf("-----------------------------------------------------\n\n");
}
void tinhDiemTrungBinh() {
    if (n == 0) {
        printf("Chua co hoc sinh nao de tinh diem trung binh!\n\n");
        return;
    }
    
    float tong = 0;
    for(int i = 0; i < n; i++) {
        tong += ds[i].grade;
    }
    float tb = tong / n;
    printf("Diem trung binh cua %d hoc sinh la: %.3f\n\n", n, tb);
}
void menu() {
    printf("+-------------------------------------+\n");
    printf("|       QUAN LY HOC SINH             |\n");
    printf("+-------------------------------------+\n");
    printf("| 1. Nhap danh sach hoc sinh         |\n");
    printf("| 2. Hien thi danh sach hoc sinh     |\n");
    printf("| 3. Tinh diem trung binh            |\n");
    printf("| 0. Thoat chuong trinh              |\n");
    printf("+-------------------------------------+\n");
    printf("Chon chuc nang: ");
}
int main() {
    int chon;
    do {
        menu();
        scanf("%d", &chon);
        xoaEnter();
        switch(chon) {
            case 1:
                nhapDanhSach();
                break;
            case 2:
                hienThiDanhSach();
                break;
            case 3:
                tinhDiemTrungBinh();
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("Chuc nang khong hop le! Chon lai.\n\n");
        }
    } while(chon != 0);
    
    return 0;
}
