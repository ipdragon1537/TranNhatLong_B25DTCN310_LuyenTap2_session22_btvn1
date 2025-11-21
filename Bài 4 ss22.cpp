#include <stdio.h>
#include <string.h>
#define MAX 1000
typedef struct {
    int ngay, thang, nam;
} Ngay;
typedef struct {
    char madh[20];
    char tenkh[50];
    Ngay ngaydat;
    double tongtien;
    char trangthai[20];
} DonHang;
DonHang ds[MAX];
int sodon = 0;
void boEnter(char s[]) {
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n'){
	    s[len-1] = '\0';
    }
}
void nhapDonHang() {
    if (sodon >= MAX) {
        printf("Danh sach da day!\n\n");
        return;
    }
    printf("=== NHAP DON HANG MOI ===\n");
    printf("Ma don hang       : ");
    fgets(ds[sodon].madh, 20, stdin);
    boEnter(ds[sodon].madh);
    printf("Ten khach hang    : ");
    fgets(ds[sodon].tenkh, 50, stdin);
    boEnter(ds[sodon].tenkh);
    printf("Ngay dat (ngay thang nam): ");
    scanf("%d %d %d", &ds[sodon].ngaydat.ngay, &ds[sodon].ngaydat.thang, &ds[sodon].ngaydat.nam);
    printf("Tong tien         : ");
    scanf("%lf", &ds[sodon].tongtien);
    getchar();
    printf("Trang thai (Dang xu ly/Da giao/Huy): ");
    fgets(ds[sodon].trangthai, 20, stdin);
    boEnter(ds[sodon].trangthai);
    sodon++;
    printf("Them don hang thanh cong!\n\n");
}
void hienThi() {
    if (sodon == 0) {
        printf("Chua co don hang nao!\n\n");
        return;
    }
    printf("\n%-12s %-20s %-12s %-15s %-15s\n",
           "Ma DH", "Khach hang", "Ngay dat", "Tong tien", "Trang thai");
    printf("--------------------------------------------------------------------------------\n");
    for(int i = 0; i < sodon; i++) {
        printf("%-12s %-20s %02d/%02d/%d   %-15.0lf   %-15s\n",
               ds[i].madh, ds[i].tenkh,
               ds[i].ngaydat.ngay, ds[i].ngaydat.thang, ds[i].ngaydat.nam,
               ds[i].tongtien, ds[i].trangthai);
    }
    printf("--------------------------------------------------------------------------------\n\n");
}
int timViTri(char ma[]) {
    for(int i = 0; i < sodon; i++) {
        if (strcmp(ds[i].madh, ma) == 0)
            return i;
    }
    return -1;
}
void capNhatTrangThai() {
    char ma[20];
    printf("Nhap ma don hang can cap nhat: ");
    fgets(ma, 20, stdin);
    boEnter(ma);

    int vt = timViTri(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang %s\n\n", ma);
        return;
    }
    printf("Trang thai cu: %s\n", ds[vt].trangthai);
    printf("Nhap trang thai moi: ");
    fgets(ds[vt].trangthai, 20, stdin);
    boEnter(ds[vt].trangthai);
    printf("Cap nhat thanh cong!\n\n");
}
void xoaDonHang() {
    char ma[20];
    printf("Nhap ma don hang can xoa: ");
    fgets(ma, 20, stdin);
    boEnter(ma);
    int vt = timViTri(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang %s\n\n", ma);
        return;
    }
    for(int i = vt; i < sodon-1; i++) {
        ds[i] = ds[i+1];
    }
    sodon--;
    printf("Da xoa don hang %s thanh cong!\n\n", ma);
}
void sapXepTongTien() {
    int chon;
    printf("1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &chon);
    getchar();

    for(int i = 0; i < sodon-1; i++) {
        for(int j = i+1; j < sodon; j++) {
            if ((chon == 1 && ds[i].tongtien > ds[j].tongtien) ||
                (chon == 2 && ds[i].tongtien < ds[j].tongtien)) {
                DonHang tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }
    printf("Sap xep thanh cong!\n\n");
}
void timKiem() {
    char ma[20];
    printf("Nhap ma don hang can tim: ");
    fgets(ma, 20, stdin);
    boEnter(ma);
    int vt = timViTri(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang %s\n\n", ma);
        return;
    }
    printf("\nTHONG TIN DON HANG:\n");
    printf("%-12s %-20s %02d/%02d/%d   %-.0lf   %-15s\n",
           ds[vt].madh, ds[vt].tenkh,
           ds[vt].ngaydat.ngay, ds[vt].ngaydat.thang, ds[vt].ngaydat.nam,
           ds[vt].tongtien, ds[vt].trangthai);
    printf("\n");
}
void menu() {
    printf("+---------------------------------+\n");
    printf("|       QUAN LY DON HANG          |\n");
    printf("|---------------------------------|\n");
    printf("| 1. Nhap don hang moi            |\n");
    printf("| 2. Hien thi tat ca              |\n");
    printf("| 3. Cap nhat trang thai          |\n");
    printf("| 4. Xoa don hang                 |\n");
    printf("| 5. Sap xep theo tong tien       |\n");
    printf("| 6. Tim kiem don hang            |\n");
    printf("| 7. Thoat                        |\n");
    printf("+---------------------------------+\n");
    printf("Ban chon: ");
}
int main() {
    int chon;
    do {
        menu();
        scanf("%d", &chon);
        getchar();
        switch(chon) {
            case 1: nhapDonHang(); break;
            case 2: hienThi(); break;
            case 3: capNhatTrangThai(); break;
            case 4: xoaDonHang(); break;
            case 5: sapXepTongTien(); break;
            case 6: timKiem(); break;
            case 7: printf("Cam on ban da su dung!\n"); break;
            default: printf("Sai chuc nang, nhap lai di!\n\n");
        }
    } while(chon != 7);
    return 0;
}
