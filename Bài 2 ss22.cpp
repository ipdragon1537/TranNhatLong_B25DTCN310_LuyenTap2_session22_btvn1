#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

Contact danhba[MAX];
int somoi = 0;

void boEnter(char s[]) {
    int len = strlen(s);
    if (s[len-1] == '\n') s[len-1] = '\0';
}

void themLienHe() {
    if (somoi >= MAX) {
        printf("Danh ba da day! Khong the them!\n\n");
        return;
    }
    printf("=== Them lien he moi ===\n");
    printf("Ho va ten: ");
    fgets(danhba[somoi].name, 50, stdin);
    boEnter(danhba[somoi].name);
    printf("So dien thoai: ");
    fgets(danhba[somoi].phone, 15, stdin);
    boEnter(danhba[somoi].phone);
    printf("Email: ");
    fgets(danhba[somoi].email, 50, stdin);
    boEnter(danhba[somoi].email);
    somoi++;
    printf("Them thanh cong!\n\n");
}

void hienThi() {
    if (somoi == 0) {
        printf("Danh ba trong khong co ai het!\n\n");
        return;
    }
    printf("\n%-4s %-25s %-15s %-30s\n", "STT", "Ho ten", "Dien thoai", "Email");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0; i < somoi; i++) {
        printf("%-4d %-25s %-15s %-30s\n", 
               i+1, danhba[i].name, danhba[i].phone, danhba[i].email);
    }
    printf("-----------------------------------------------------------------\n\n");
}

void timKiem() {
    char ten[50];
    printf("Nhap ten can tim: ");
    fgets(ten, 50, stdin);
    boEnter(ten);
    int timthay = 0;
    printf("\nKet qua tim kiem:\n");
    for(int i = 0; i < somoi; i++) {
        char tmp1[50], tmp2[50];
        strcpy(tmp1, danhba[i].name);
        strcpy(tmp2, ten);
        for(int j=0; tmp1[j]; j++) tmp1[j] = tolower(tmp1[j]);
        for(int j=0; tmp2[j]; j++) tmp2[j] = tolower(tmp2[j]);
        if (strstr(tmp1, tmp2) != NULL) {
            printf("%-4d %-25s %-15s %-30s\n", 
                   i+1, danhba[i].name, danhba[i].phone, danhba[i].email);
            timthay = 1;
        }
    }
    if (!timthay) printf("Khong tim thay ai co ten chua '%s'\n\n", ten);
    else printf("\n");
}

void xoaLienHe() {
    char ten[50];
    printf("Nhap ten lien he can xoa: ");
    fgets(ten, 50, stdin);
    boEnter(ten);
    int vitri = -1;
    for(int i = 0; i < somoi; i++) {
        char tmp1[50], tmp2[50];
        strcpy(tmp1, danhba[i].name);
        strcpy(tmp2, ten);
        for(int j=0; tmp1[j]; j++) tmp1[j] = tolower(tmp1[j]);
        for(int j=0; tmp2[j]; j++) tmp2[j] = tolower(tmp2[j]);
        if (strcmp(tmp1, tmp2) == 0) {
            vitri = i;
            break;
        }
    }
    if (vitri == -1) {
        printf("Khong tim thay lien he ten '%s' de xoa!\n\n", ten);
        return;
    }
    for(int i = vitri; i < somoi-1; i++) {
        danhba[i] = danhba[i+1];
    }
    somoi--;
    printf("Da xoa thanh cong lien he '%s'\n\n", ten);
}

void menu() {
    printf("+------------------------------------------+\n");
    printf("¦           QUAN LY DANH BA DIEN THOAI     ¦\n");
    printf("¦------------------------------------------¦\n");
    printf("¦ 1. Them lien he moi                      ¦\n");
    printf("¦ 2. Hien thi tat ca lien he               ¦\n");
    printf("¦ 3. Tim kiem theo ten                     ¦\n");
    printf("¦ 4. Xoa lien he theo ten                  ¦\n");
    printf("¦ 0. Thoat chuong trinh                   ¦\n");
    printf("+------------------------------------------+\n");
    printf("Ban chon: ");
}

int main() {
    int chon;
    do {
        menu();
        scanf("%d", &chon);
        getchar();
        switch(chon) {
            case 1: themLienHe(); break;
            case 2: hienThi(); break;
            case 3: timKiem(); break;
            case 4: xoaLienHe(); break;
            case 0: printf("Tam biet! Hen gap lai lan sau nha\n"); break;
            default: printf("Nhap sai roi, chon lai di ban!\n\n");
        }
    } while(chon != 0);
    return 0;
}
