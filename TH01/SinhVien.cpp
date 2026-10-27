#include "SinhVien.h"
#include <iomanip>
#include <limits>

using namespace std;

int doDaiChuoi(const char chuoi[]) {
    int n = 0;
    while (chuoi[n] != '\0') ++n;
    return n;
}

int soSanhChuoi(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) ++i;
    if (a[i] == b[i]) return 0;
    if (a[i] < b[i]) return -1;
    return 1;
}

bool saoChepChuoi(char dich[], int kichThuocDich, const char nguon[]) {
    int n = doDaiChuoi(nguon);
    if (kichThuocDich <= n) return false;
    for (int i = 0; i <= n; ++i) dich[i] = nguon[i];
    return true;
}

char chuyenThanhChuThuong(char kyTu) {
    if (kyTu >= 'A' && kyTu <= 'Z') kyTu += 'a' - 'A';
    return kyTu;
}

// Cac ham noi bo chi su dung trong file nay.
namespace {
bool laKhoangTrang(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}

bool nhapChuoi(istream& in, const char* nhan, char dich[], int kichThuoc) {
    while (true) {
        if (&in == &cin) cout << nhan;
        in.getline(dich, kichThuoc);
        if (in.bad() || in.eof()) {
            in.setstate(ios::failbit);
            return false;
        }
        if (in.fail()) {
            if (&in != &cin) return false;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Du lieu qua dai. Vui long nhap lai.\n";
            continue;
        }
        // Bo khoang trang o hai dau, giu khoang trang giua ho ten.
        int dau = 0;
        int cuoi = doDaiChuoi(dich);
        while (dau < cuoi && laKhoangTrang(dich[dau])) ++dau;
        while (cuoi > dau && laKhoangTrang(dich[cuoi - 1])) --cuoi;
        int n = cuoi - dau;
        for (int i = 0; i < n; ++i) dich[i] = dich[dau + i];
        dich[n] = '\0';
        if (n > 0) return true;
        if (&in != &cin) {
            in.setstate(ios::failbit);
            return false;
        }
        cout << "Khong duoc de trong.\n";
    }
}

bool ngayHopLe(const char ngay[]) {
    if (doDaiChuoi(ngay) != 10 || ngay[2] != '/' || ngay[5] != '/') return false;
    for (int i = 0; i < 10; ++i) {
        if (i != 2 && i != 5 && (ngay[i] < '0' || ngay[i] > '9')) return false;
    }
    int d = (ngay[0] - '0') * 10 + ngay[1] - '0';
    int m = (ngay[3] - '0') * 10 + ngay[4] - '0';
    int y = 0;
    for (int i = 6; i < 10; ++i) y = y * 10 + ngay[i] - '0';
    if (y == 0 || m < 1 || m > 12) return false;
    int soNgay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) soNgay[1] = 29;
    return d >= 1 && d <= soNgay[m - 1];
}

bool baoLoi(istream& in, const char* thongBao) {
    if (&in == &cin && !in.eof() && !in.bad()) {
        cout << thongBao << '\n';
        return true;
    }
    in.setstate(ios::failbit);
    return false;
}

bool nhapDiem(istream& in, float& diem) {
    while (true) {
        if (&in == &cin) cout << "Diem trung binh [0, 10]: ";
        if (!(in >> diem)) {
            if (&in != &cin || in.eof() || in.bad()) return false;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            bool duLieuThua = false;
            // Kiem tra ca dong de khong chap nhan 8abc hoac 8 9.
            if (!in.eof()) {
                char c;
                while (in.get(c) && c != '\n') {
                    if (!laKhoangTrang(c)) duLieuThua = true;
                }
                if (in.bad()) return false;
                if (in.eof()) in.clear(ios::eofbit);
            }
            if (!duLieuThua && diem >= 0 && diem <= 10) return true;
        }
        if (!baoLoi(in, "Diem khong hop le. Vui long nhap so tu 0 den 10.")) return false;
    }
}

bool nhapThongTin(istream& in, char hoTen[], char ngaySinh[],
                  char gioiTinh[], char lop[], float& diem) {
    if (!nhapChuoi(in, "Ho ten: ", hoTen, 51)) return false;
    do {
        if (!nhapChuoi(in, "Ngay sinh (dd/mm/yyyy): ", ngaySinh, 11)) return false;
        if (ngayHopLe(ngaySinh)) break;
        if (!baoLoi(in, "Ngay sinh khong hop le.")) return false;
    } while (true);
    do {
        if (!nhapChuoi(in, "Gioi tinh (Nam/Nu/Khac): ", gioiTinh, 5)) return false;
        for (int i = 0; gioiTinh[i] != '\0'; ++i)
            gioiTinh[i] = chuyenThanhChuThuong(gioiTinh[i]);
        if (soSanhChuoi(gioiTinh, "nam") == 0 || soSanhChuoi(gioiTinh, "nu") == 0
            || soSanhChuoi(gioiTinh, "khac") == 0) {
            gioiTinh[0] -= 'a' - 'A';
            break;
        }
        if (!baoLoi(in, "Chi nhap Nam, Nu hoac Khac.")) return false;
    } while (true);
    return nhapChuoi(in, "Lop: ", lop, 16) && nhapDiem(in, diem);
}
} // namespace

SinhVien::SinhVien()
    : maSinhVien(nullptr), hoTen(nullptr), lop(nullptr),
      ngaySinh{}, gioiTinh{}, diemTrungBinh(0) {
    try {
        this->ganChuoi(this->maSinhVien, "");
        this->ganChuoi(this->hoTen, "");
        this->ganChuoi(this->lop, "");
    } catch (...) {
        delete[] this->maSinhVien;
        delete[] this->hoTen;
        delete[] this->lop;
        throw;
    }
}

SinhVien::SinhVien(const SinhVien& other)
    : maSinhVien(nullptr), hoTen(nullptr), lop(nullptr),
      ngaySinh{}, gioiTinh{}, diemTrungBinh(other.diemTrungBinh) {
    try {
        this->ganChuoi(this->maSinhVien, other.maSinhVien);
        this->ganChuoi(this->hoTen, other.hoTen);
        this->ganChuoi(this->lop, other.lop);
        saoChepChuoi(this->ngaySinh, sizeof this->ngaySinh, other.ngaySinh);
        saoChepChuoi(this->gioiTinh, sizeof this->gioiTinh, other.gioiTinh);
    } catch (...) {
        delete[] this->maSinhVien;
        delete[] this->hoTen;
        delete[] this->lop;
        throw;
    }
}

SinhVien::~SinhVien() {
    delete[] this->maSinhVien;
    delete[] this->hoTen;
    delete[] this->lop;
}

void SinhVien::ganChuoi(char*& dich, const char nguon[]) {
    int kichThuoc = doDaiChuoi(nguon) + 1;
    char* chuoiMoi = new char[kichThuoc];
    saoChepChuoi(chuoiMoi, kichThuoc, nguon);
    delete[] dich;
    dich = chuoiMoi;
}

SinhVien& SinhVien::operator=(const SinhVien& other) {
    if (this != &other) {
        SinhVien tam(other);

        char* chuoiTam = this->maSinhVien;
        this->maSinhVien = tam.maSinhVien;
        tam.maSinhVien = chuoiTam;

        chuoiTam = this->hoTen;
        this->hoTen = tam.hoTen;
        tam.hoTen = chuoiTam;

        chuoiTam = this->lop;
        this->lop = tam.lop;
        tam.lop = chuoiTam;

        saoChepChuoi(this->ngaySinh, sizeof this->ngaySinh, other.ngaySinh);
        saoChepChuoi(this->gioiTinh, sizeof this->gioiTinh, other.gioiTinh);
        this->diemTrungBinh = other.diemTrungBinh;
    }
    return *this;
}

const char* SinhVien::getMaSinhVien() const {
    return this->maSinhVien;
}
const char* SinhVien::getHoTen() const {
    return this->hoTen;
}
const char* SinhVien::getLop() const {
    return this->lop;
}
float SinhVien::getDiemTrungBinh() const {
    return this->diemTrungBinh;
}

istream& operator>>(istream& in, SinhVien& sinhVien) {
    char maSinhVien[16];
    char hoTen[51];
    char ngaySinh[11];
    char gioiTinh[5];
    char lop[16];
    float diemTrungBinh;

    SinhVien tam;
    if (nhapChuoi(in, "Ma sinh vien: ", maSinhVien, 16)
        && nhapThongTin(in, hoTen, ngaySinh, gioiTinh, lop, diemTrungBinh)) {
        tam.ganChuoi(tam.maSinhVien, maSinhVien);
        tam.ganChuoi(tam.hoTen, hoTen);
        saoChepChuoi(tam.ngaySinh, sizeof tam.ngaySinh, ngaySinh);
        saoChepChuoi(tam.gioiTinh, sizeof tam.gioiTinh, gioiTinh);
        tam.ganChuoi(tam.lop, lop);
        tam.diemTrungBinh = diemTrungBinh;
        sinhVien = tam;
    }
    return in;
}

void SinhVien::capNhat() {
    char hoTen[51];
    char ngaySinh[11];
    char gioiTinh[5];
    char lop[16];
    float diemTrungBinh;

    if (nhapThongTin(cin, hoTen, ngaySinh, gioiTinh, lop, diemTrungBinh)) {
        SinhVien tam(*this);
        tam.ganChuoi(tam.hoTen, hoTen);
        saoChepChuoi(tam.ngaySinh, sizeof tam.ngaySinh, ngaySinh);
        saoChepChuoi(tam.gioiTinh, sizeof tam.gioiTinh, gioiTinh);
        tam.ganChuoi(tam.lop, lop);
        tam.diemTrungBinh = diemTrungBinh;
        *this = tam;
    }
}

ostream& operator<<(ostream& out, const SinhVien& sinhVien) {
    ios::fmtflags dinhDangCu = out.flags();
    streamsize doChinhXacCu = out.precision();
    char kyTuDemCu = out.fill();
    out << setfill(' ') << left
        << setw(17) << sinhVien.maSinhVien
        << setw(52) << sinhVien.hoTen
        << setw(12) << sinhVien.ngaySinh
        << setw(7) << sinhVien.gioiTinh
        << setw(17) << sinhVien.lop
        << fixed << setprecision(2) << sinhVien.diemTrungBinh;
    out.flags(dinhDangCu);
    out.precision(doChinhXacCu);
    out.fill(kyTuDemCu);
    return out;
}
