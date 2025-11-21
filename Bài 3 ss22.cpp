#include <stdio.h>
#include <string.h>
#define MAX 1000
typedef struct {
    int ngay, thang, nam;
} NgaySinh;
typedef struct {
    char mssv[15];
    char hoten[50];
    NgaySinh ns;
    char diachi[100];
    char dienthoai[15];
} SinhVien;
SinhVien ds[MAX];
int n = 0;
void boEnter(char s[]) {
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n'){
	    s[len-1] = '\0';
	} 
}
void nhapMotSV() {
    if (n >= MAX) {
        printf("Danh sach da day!\n");
        return;
    }
    printf("Nhap thong tin sinh vien thu %d:\n", n+1);
    printf("Ma sinh vien: ");
    fgets(ds[n].mssv, 15, stdin);
    boEnter(ds[n].mssv);
    printf("Ho va ten   : ");
    fgets(ds[n].hoten, 50, stdin);
    boEnter(ds[n].hoten);
    printf("Ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &ds[n].ns.ngay, &ds[n].ns.thang, &ds[n].ns.nam);
    getchar(); 
    printf("Dia chi     : ");
    fgets(ds[n].diachi, 100, stdin);
    boEnter(ds[n].diachi);
    printf("Dien thoai  : ");
    fgets(ds[n].dienthoai, 15, stdin);
    boEnter(ds[n].dienthoai);
    n++;
    printf("Them sinh vien thanh cong!\n\n");
}
void themCuoi() {
    nhapMotSV();
}
void hienThi() {
    if (n == 0) {
        printf("Danh sach trong!\n\n");
        return;
    }
    printf("\n%-12s %-25s %-12s %-30s %-15s\n", 
           "MSSV", "Ho ten", "Ngay sinh", "Dia chi", "Dien thoai");
    printf("------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-12s %-25s %02d/%02d/%d   %-30s %-15s\n",
               ds[i].mssv, ds[i].hoten, 
               ds[i].ns.ngay, ds[i].ns.thang, ds[i].ns.nam,
               ds[i].diachi, ds[i].dienthoai);
    }
    printf("------------------------------------------------------------------------------------------\n\n");
}
int timTheoMSSV(char ma[]) {
    for(int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, ma) == 0) {
        	return i;
		}
    }
    return -1;
}
void xoaTheoMSSV() {
    char ma[15];
    printf("Nhap ma sinh vien can xoa: ");
    fgets(ma, 15, stdin);
    boEnter(ma);
    int vt = timTheoMSSV(ma);
    if (vt == -1) {
        printf("Khong tim thay sinh vien co ma %s\n\n", ma);
        return;
    }
    for(int i = vt; i < n-1; i++) {
        ds[i] = ds[i+1];
    }
    n--;
    printf("Da xoa sinh vien %s thanh cong!\n\n", ma);
}
void capNhatTheoMSSV() {
    char ma[15];
    printf("Nhap ma sinh vien can cap nhat: ");
    fgets(ma, 15, stdin);
    boEnter(ma);
    int vt = timTheoMSSV(ma);
    if (vt == -1) {
        printf("Khong tim thay sinh vien co ma %s\n\n", ma);
        return;
    }
    printf("Cap nhat thong tin moi cho sinh vien %s:\n", ma);
    printf("Ho va ten moi: ");
    fgets(ds[vt].hoten, 50, stdin);
    boEnter(ds[vt].hoten);
    
    printf("Ngay sinh moi (ngay thang nam): ");
    scanf("%d %d %d", &ds[vt].ns.ngay, &ds[vt].ns.thang, &ds[vt].ns.nam);
    getchar();
    
    printf("Dia chi moi: ");
    fgets(ds[vt].diachi, 100, stdin);
    boEnter(ds[vt].diachi);
    printf("Dien thoai moi: ");
    fgets(ds[vt].dienthoai, 15, stdin);
    boEnter(ds[vt].dienthoai);
    printf("Cap nhat thanh cong!\n\n");
}
void sapXepTheoTen() {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if (strcmp(ds[i].hoten, ds[j].hoten) > 0) {
                SinhVien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }
    printf("Da sap xep danh sach theo ho ten (A-Z)\n\n");
}
void timKiem() {
    char ma[15];
    printf("Nhap ma sinh vien can tim: ");
    fgets(ma, 15, stdin);
    boEnter(ma);
    int vt = timTheoMSSV(ma);
    if (vt == -1) {
        printf("Khong tim thay sinh vien co ma %s\n\n", ma);
        return;
    }
    
    printf("\nThong tin sinh vien tim thay:\n");
    printf("%-12s %-25s %02d/%02d/%d   %-30s %-15s\n",
           ds[vt].mssv, ds[vt].hoten, 
           ds[vt].ns.ngay, ds[vt].ns.thang, ds[vt].ns.nam,
           ds[vt].diachi, ds[vt].dienthoai);
    printf("\n");
}
void menu() {
    printf("==============================\n");
    printf("     QUAN LY SINH VIEN        \n");
    printf("==============================\n");
    printf("1. Nhap thong tin sinh vien\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Them sinh vien vao cuoi\n");
    printf("4. Xoa sinh vien theo MSSV\n");
    printf("5. Cap nhat thong tin SV\n");
    printf("6. Sap xep theo ho ten (A-Z)\n");
    printf("7. Tim kiem theo MSSV\n");
    printf("8. Thoat\n");
    printf("------------------------------\n");
    printf("Chon chuc nang: ");
}
int main() {
    int chon;
    do {
        menu();
        scanf("%d", &chon);
        getchar(); 
        
        switch(chon) {
            case 1: nhapMotSV(); break;
            case 2: hienThi(); break;
            case 3: themCuoi(); break;
            case 4: xoaTheoMSSV(); break;
            case 5: capNhatTheoMSSV(); break;
            case 6: sapXepTheoTen(); break;
            case 7: timKiem(); break;
            case 8: printf("Tam biet thay/co!\n"); break;
            default: printf("Chon sai roi, nhap lai di!\n\n");
        }
    } while(chon != 8);
    return 0;
}
