# QUẢN LÝ SINH VIÊN BẰNG OOP C++

## 1. Mục tiêu

Xây dựng chương trình console quản lý sinh viên, áp dụng các kiến thức OOP cơ bản nhưng chỉ sử dụng **một class `SinhVien`**. Chương trình chưa sử dụng kế thừa và đa hình.

Các chức năng chính:

1. Thêm sinh viên.
2. Sửa thông tin sinh viên.
3. Xóa sinh viên.
4. Tìm kiếm sinh viên.
5. Xem thông tin một sinh viên.
6. Xem toàn bộ danh sách.
7. Sắp xếp danh sách tăng hoặc giảm.

## 2. Các ràng buộc kỹ thuật

- Chỉ khai báo một class là `SinhVien`; không tạo thêm class quản lý danh sách.
- Không dùng thư viện `<string>` và không dùng `std::string`. `maSinhVien`, `hoTen`, `lop` là `char*`; `ngaySinh`, `gioiTinh` là mảng `char` có kích thước cố định.
- Không include `<cstring>` hoặc `<string.h>`, không gọi các hàm xử lý chuỗi thư viện như `strcmp`, `strstr`, `strcpy`. Các thao tác chuỗi cần thiết phải được tự cài đặt bằng vòng lặp trên mảng `char`.
- Danh sách sinh viên là mảng động, được cấp phát bằng `new[]` và giải phóng bằng `delete[]`.
- Không dùng `vector`, `list` hoặc thuật toán có sẵn trong STL.
- Không dùng kế thừa, lớp ảo hoặc đa hình.
- Chương trình được tách thành đúng ba file nguồn chính:
  - `SinhVien.h`: khai báo class `SinhVien`.
  - `SinhVien.cpp`: định nghĩa các phương thức của `SinhVien`.
  - `main.cpp`: quản lý mảng động, menu và các chức năng xử lý danh sách.
- Bắt buộc nạp chồng toán tử `>>` và `<<` để nhập, xuất một sinh viên.
- Phải tự định nghĩa `operator=` vì chương trình dùng phép gán giữa các đối tượng `SinhVien` khi thêm, tăng sức chứa, xóa và hoán đổi.
- Toán tử nào được dùng trực tiếp trên đối tượng `SinhVien` thì phải được nạp chồng tương ứng; không nạp chồng toán tử không dùng. Quy tắc này không áp dụng cho các phép toán có sẵn trên số, ký tự và con trỏ.

> Hai file `SinhVien.h` và `SinhVien.cpp` hiện đã dùng thiết kế kết hợp: ba thuộc tính `char*`, hai thuộc tính mảng cố định và các mảng cục bộ làm bộ đệm nhập.

## 3. Dữ liệu của một sinh viên

Class `SinhVien` dự kiến gồm các thuộc tính `private`:

| Thuộc tính | Kiểu dữ liệu | Ý nghĩa |
|---|---|---|
| `maSinhVien` | `char*` | Mã sinh viên, duy nhất và không rỗng |
| `hoTen` | `char*` | Họ và tên |
| `ngaySinh` | `char[11]` | Ngày sinh theo dạng `dd/mm/yyyy`, luôn có độ dài cố định |
| `gioiTinh` | `char[5]` | Nam, Nu hoặc Khac; đủ chứa `Khac` và `\0` |
| `lop` | `char*` | Mã lớp |
| `diemTrungBinh` | `float` | Điểm trung bình từ 0 đến 10 |

Mỗi thuộc tính con trỏ sở hữu một vùng nhớ riêng gồm `doDaiChuoi(nguon) + 1` phần tử `char`, có ký tự kết thúc `\0`. Hai mảng cố định đã dành sẵn một phần tử cho `\0`. `diemTrungBinh` vẫn là `float`.

Giữ giới hạn nhập hiện tại: mã sinh viên 15 byte, họ tên 50 byte, ngày sinh 10 byte, giới tính 4 byte và lớp 15 byte, chưa tính `\0`. Có thể dùng mảng cục bộ làm bộ đệm nhập.

Mã sinh viên được dùng làm khóa để xem, sửa và xóa. Khi sửa thông tin, nên giữ nguyên mã sinh viên để tránh làm thay đổi khóa và phát sinh trùng mã.

## 4. Thiết kế class `SinhVien`

### 4.1. Phương thức cần có

```cpp
#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>

class SinhVien {
private:
    char* maSinhVien;
    char* hoTen;
    char ngaySinh[11];
    char gioiTinh[5];
    char* lop;
    float diemTrungBinh;

public:
    SinhVien();
    SinhVien(const SinhVien& other);
    ~SinhVien();
    SinhVien& operator=(const SinhVien& other);

    void capNhat();

    const char* getMaSinhVien() const;
    const char* getHoTen() const;
    const char* getLop() const;
    float getDiemTrungBinh() const;

    friend std::istream& operator>>(std::istream& in, SinhVien& sinhVien);
    friend std::ostream& operator<<(std::ostream& out, const SinhVien& sinhVien);
};

#endif
```

- Constructor mặc định cấp phát `new char[1]` cho ba thuộc tính con trỏ; khởi tạo hai mảng cố định thành chuỗi rỗng và đặt `this->diemTrungBinh = 0`.
- Constructor sao chép `SinhVien(const SinhVien& other)` cấp phát vùng nhớ mới cho ba con trỏ và sao chép nội dung hai mảng cố định.
- Destructor `~SinhVien()` chỉ gọi `delete[]` cho `maSinhVien`, `hoTen`, `lop`. Hai mảng cố định được hủy tự động cùng đối tượng.
- `operator>>` nhập đầy đủ dữ liệu cho một sinh viên mới.
- `operator<<` xuất thông tin một sinh viên theo định dạng cột.
- `operator=` thực hiện sao chép sâu và giải phóng dữ liệu cũ đúng cách.
- `capNhat()` cập nhật các trường được phép sửa, không đổi mã sinh viên.
- Các getter chỉ được bổ sung khi thật sự cần cho tìm kiếm, kiểm tra trùng và sắp xếp.
- Các hàm chỉ đọc dữ liệu được đánh dấu `const`.
- Trong thân hàm thành viên, truy cập thuộc tính của đối tượng hiện tại bằng `this->`, ví dụ `return this->maSinhVien;`. Các hàm `friend` không có `this`.
- Getter trả `const char*` chỉ cho phép đọc chuỗi; bên gọi không được `delete[]` con trỏ này hoặc giữ để dùng sau khi sinh viên bị cập nhật, gán lại hay hủy.

### 4.2. Nhập chuỗi an toàn

- Trong `operator>>`, dùng `in.getline(...)` để đọc vào các bộ đệm `char` cục bộ có kích thước phù hợp giới hạn nhập và `in >>` cho điểm; mọi thao tác đọc, kiểm tra lỗi, `clear` và `ignore` đều thực hiện trên luồng `in`.
- Sau khi dữ liệu hợp lệ, cấp phát mảng mới theo độ dài thực tế cho `maSinhVien`, `hoTen`, `lop`; sao chép `ngaySinh`, `gioiTinh` vào các mảng thành viên cố định. Không gán thuộc tính con trỏ vào bộ đệm cục bộ.
- Không đọc trực tiếp theo giới hạn tối đa vào thuộc tính mới được cấp phát 1 byte. Không dùng `sizeof(this->hoTen)` làm sức chứa: đó là kích thước con trỏ, không phải kích thước vùng nhớ đã cấp phát.
- Sau khi nhập số, phải bỏ phần còn lại của dòng trên chính luồng đó trước khi gọi `getline`. Phần menu cũng cần xử lý dòng chứa lựa chọn trước khi gọi `std::cin >> sinhVien`.
- Nếu luồng nhập lỗi hoặc dữ liệu vượt quá kích thước mảng, cần xóa trạng thái lỗi và bỏ phần dữ liệu thừa.
- Nếu gặp EOF, trả luồng về bên gọi để hủy thao tác và thoát menu, không lặp nhập vô hạn. Chỉ ghi dữ liệu vào danh sách khi nhập hoàn tất và hợp lệ.
- Kiểm tra điểm trung bình thuộc đoạn `[0, 10]`; nếu không hợp lệ thì yêu cầu nhập lại.
- Không dùng các hàm xử lý chuỗi của `<cstring>`; nếu cần sao chép hoặc so sánh chuỗi thì tự duyệt từng ký tự và luôn bảo đảm có ký tự kết thúc `\0`.

### 4.3. Các hàm xử lý mảng `char` tự cài đặt

Chỉ triển khai hàm có nơi gọi thực tế. Hiện tại hai file `SinhVien.h` và `SinhVien.cpp` chỉ giữ `doDaiChuoi`, `soSanhChuoi`, `saoChepChuoi` và `chuyenThanhChuThuong`. Khi triển khai `main.cpp`, chỉ bổ sung hàm tìm chuỗi nếu chức năng tìm kiếm thực sự cần dùng.

Các hàm hỗ trợ chuỗi là **hàm tự do**, không phải class mới. Có thể khai báo trong `main.cpp` hoặc khai báo ở `SinhVien.h` và định nghĩa trong `SinhVien.cpp` nếu cả hai file cần dùng:

```cpp
int doDaiChuoi(const char chuoi[]);
int soSanhChuoi(const char a[], const char b[]);
bool saoChepChuoi(char dich[], int kichThuocDich, const char nguon[]);
char chuyenThanhChuThuong(char kyTu);
```

Quy ước:

- `doDaiChuoi` duyệt đến `\0` và trả về số ký tự.
- `soSanhChuoi` thay cho `strcmp`: trả `-1` nếu `a < b`, `0` nếu hai chuỗi bằng nhau và `1` nếu `a > b`. Hàm dùng các phép so sánh trực tiếp, không dùng `static_cast`.
- `chuyenThanhChuThuong` kiểm tra ký tự trong đoạn `'A'`–`'Z'`, rồi cộng khoảng cách `'a' - 'A'`; hàm không dùng `static_cast`. Phạm vi xử lý là ASCII, không phải chuyển hoa/thường đầy đủ cho tiếng Việt UTF-8.
- `saoChepChuoi` tự duyệt ký tự, kiểm tra mảng đích đủ chỗ cho cả `\0`; trả `false` nếu không đủ và không sửa đích. Khi đủ chỗ, sao chép cả ký tự kết thúc rồi trả `true`. Khi sao chép sâu, cấp phát đích trước và truyền sức chứa thực tế `doDaiChuoi(nguon) + 1`, không dùng `sizeof` trên con trỏ.

### 4.4. Nạp chồng toán tử

Chương trình bắt buộc tự định nghĩa ba toán tử `>>`, `<<` và `=` trong `SinhVien.cpp`. Hai toán tử nhập, xuất là hàm tự do được khai báo `friend` trong class:

```cpp
std::istream& operator>>(std::istream& in, SinhVien& sinhVien);
std::ostream& operator<<(std::ostream& out, const SinhVien& sinhVien);
```

Yêu cầu đối với hai toán tử:

- Tham số và giá trị trả về dùng `istream`/`ostream` thay vì viết cố định `cin`/`cout`, nhờ đó toán tử vẫn dùng được với các luồng khác.
- `operator>>` trả về `istream&` để hỗ trợ cách viết nối tiếp như `cin >> a >> b`.
- `operator<<` nhận `const SinhVien&` vì việc xuất không làm thay đổi đối tượng và trả về `ostream&` để hỗ trợ `cout << a << b`.
- Hai toán tử được khai báo `friend` vì cần truy cập trực tiếp các thuộc tính `private`.
- Phần kiểm tra điểm và xử lý mảng `char` an toàn được đặt trong `operator>>` hoặc các hàm hỗ trợ dùng chung.
- `operator<<` ghi toàn bộ dữ liệu qua `out`, không ghi cố định vào `std::cout`.

Cách sử dụng trong chương trình:

```cpp
std::cin >> sinhVien;
std::cout << sinhVien;
```

Ngoài `>>` và `<<`, không nạp chồng toán tử chỉ để đủ số lượng. Ví dụ, các tiêu chí sắp xếp vẫn được biểu diễn bằng hàm so sánh và con trỏ hàm nên không cần `operator<` hay `operator>`.

Toán tử gán là hàm thành viên với khai báo:

```cpp
SinhVien& operator=(const SinhVien& other);
```

Phải tự viết phần thân: nếu `this == &other`, trả về `*this` ngay. Nếu khác đối tượng, tạo `SinhVien tam(other)` bằng constructor sao chép, đổi ba con trỏ của đối tượng hiện tại với `tam`, sao chép hai mảng cố định và điểm, rồi trả về `*this`. Khi `tam` bị hủy, destructor giải phóng ba vùng nhớ động cũ của đối tượng đích.

Không viết `this->hoTen = other.hoTen`: cách đó làm hai sinh viên dùng chung vùng nhớ. Constructor sao chép cũng phải sao chép sâu ba thuộc tính con trỏ. `ngaySinh` và `gioiTinh` được sao chép từng ký tự bằng `saoChepChuoi`. Constructor sao chép và destructor cần thiết theo quy tắc ba hàm.

Nếu một lần cấp phát thất bại, phải thu hồi các vùng nhớ tạm đã cấp phát trước đó và truyền tiếp lỗi; phép gán phải giữ nguyên đối tượng đích. Constructor cũng phải thu hồi phần đã cấp phát nếu chưa xây dựng xong đối tượng, vì destructor của đối tượng chưa hoàn tất sẽ không tự được gọi.

Các phép `<`, `>`, `==` trên điểm hoặc kết quả `soSanhChuoi` là phép toán trên kiểu cơ bản, không cần nạp chồng cho `SinhVien`. Nếu khi triển khai dùng trực tiếp `a < b`, `a > b` hoặc `a == b` với hai sinh viên thì phải tự định nghĩa toán tử tương ứng và nêu rõ ý nghĩa so sánh.

## 5. Quản lý danh sách bằng mảng động

Danh sách được quản lý trong `main.cpp` bằng ba biến:

```cpp
SinhVien* danhSach = nullptr;
int soLuong = 0;
int sucChua = 0;
```

Không tạo class thứ hai để quản lý danh sách. Các thao tác danh sách là các hàm tự do trong `main.cpp`.

### 5.1. Tăng sức chứa

Khi `soLuong == sucChua`:

1. Chọn sức chứa mới: `2` nếu mảng đang rỗng, ngược lại là `sucChua * 2`.
2. Cấp phát một mảng mới có sức chứa lớn hơn.
3. Sao chép `soLuong` phần tử từ mảng cũ sang mảng mới bằng vòng lặp, gọi `operator=` sao chép sâu cho từng phần tử. Nếu sao chép thất bại, giải phóng mảng mới và giữ nguyên mảng cũ.
4. Giải phóng mảng cũ bằng `delete[]`; destructor của từng sinh viên sẽ giải phóng các chuỗi thuộc về phần tử đó.
5. Gán con trỏ danh sách sang mảng mới và cập nhật sức chứa.

Cuối chương trình luôn gọi `delete[] danhSach` đúng một lần. `delete[] nullptr` là hợp lệ.

Có hai cấp bộ nhớ: mảng động các đối tượng `SinhVien` do phần quản lý danh sách sở hữu, và ba mảng ký tự động của mỗi đối tượng. Không tự giải phóng các chuỗi qua getter từ `main.cpp`.

### 5.2. Các hàm xử lý danh sách dự kiến

```cpp
void tangSucChua(SinhVien*& danhSach, int soLuong, int& sucChua);
int timViTriTheoMa(const SinhVien* danhSach, int soLuong, const char ma[]);

void themSinhVien(SinhVien*& danhSach, int& soLuong, int& sucChua);
void suaSinhVien(SinhVien* danhSach, int soLuong);
void xoaSinhVien(SinhVien* danhSach, int& soLuong);
void timKiemSinhVien(const SinhVien* danhSach, int soLuong);
void xemMotSinhVien(const SinhVien* danhSach, int soLuong);
void xemDanhSach(const SinhVien* danhSach, int soLuong);
```

Quy ước truyền tham số:

- Dùng `SinhVien*&` khi hàm có thể cấp phát lại và thay đổi địa chỉ mảng.
- Dùng `int&` khi hàm cần thay đổi số lượng hoặc sức chứa.
- Dùng con trỏ tới `const SinhVien` cho các hàm chỉ đọc danh sách.

## 6. Chi tiết các chức năng

### 6.1. Thêm sinh viên

1. Nhập thông tin sinh viên tạm bằng `cin >> sinhVienTam`.
2. Kiểm tra mã có rỗng hay đã tồn tại bằng `timViTriTheoMa` và hàm `soSanhChuoi` tự cài đặt.
3. Nếu hợp lệ, tăng sức chứa khi cần rồi gán sinh viên vào cuối mảng.
4. Tăng `soLuong`.

Không cho phép hai sinh viên có cùng mã.

### 6.2. Sửa sinh viên

1. Nhập mã cần sửa.
2. Tìm vị trí chính xác theo mã.
3. Nếu tìm thấy, hiển thị thông tin hiện tại bằng `cout << danhSach[viTri]` rồi gọi `capNhat()`.
4. Nếu không tìm thấy, thông báo rõ cho người dùng.

### 6.3. Xóa sinh viên

1. Nhập mã cần xóa và tìm vị trí.
2. Yêu cầu xác nhận trước khi xóa.
3. Dịch từng phần tử phía sau sang trái một vị trí.
4. Giảm `soLuong`.

Không cần cấp phát lại mảng sau mỗi lần xóa; vùng nhớ đã cấp phát được tái sử dụng cho lần thêm sau.

Các phép dịch phần tử gọi `operator=` sao chép sâu. Phần tử nằm ngoài `soLuong` vẫn là đối tượng hợp lệ trong mảng đã cấp phát; dữ liệu của nó sẽ được giải phóng khi gán đè hoặc khi `delete[]` cả mảng. Không gọi destructor thủ công cho phần tử đó.

### 6.4. Tìm kiếm sinh viên

Hỗ trợ tìm gần đúng theo tên hoặc mã lớp:

- Duyệt tuần tự toàn bộ mảng.
- Khi triển khai chức năng này, tự viết một hàm kiểm tra chuỗi con và chỉ giữ hàm đó nếu được gọi thực tế; không dùng `strstr`.
- In tất cả kết quả phù hợp, không chỉ kết quả đầu tiên.
- Nếu muốn tìm không phân biệt chữ hoa/chữ thường, tự chuyển đổi và so sánh từng ký tự; không tạo `std::string` trung gian và không dùng STL algorithm.

### 6.5. Xem một sinh viên

Nhập mã sinh viên, dùng `timViTriTheoMa`, sau đó xuất phần tử tìm thấy bằng toán tử `<<`. Chức năng này tìm chính xác theo mã và khác với chức năng tìm kiếm gần đúng.

### 6.6. Xem danh sách

- Nếu `soLuong == 0`, thông báo danh sách trống.
- Nếu có dữ liệu, in tiêu đề cột và lần lượt dùng `cout << danhSach[i]` cho từng phần tử.
- Có thể dùng `<iomanip>` để căn cột; thư viện này không phải cấu trúc dữ liệu hay thuật toán STL bị cấm.

## 7. Sắp xếp bằng một hàm duy nhất và con trỏ hàm

Chỉ xây dựng **một hàm sắp xếp**. Chiều tăng/giảm và tiêu chí so sánh được quyết định bởi hàm so sánh truyền vào.

```cpp
typedef bool (*HamSoSanh)(const SinhVien&, const SinhVien&);

void sapXep(SinhVien* danhSach, int soLuong, HamSoSanh soSanh);

bool diemTang(const SinhVien& a, const SinhVien& b);
bool diemGiam(const SinhVien& a, const SinhVien& b);
bool tenTang(const SinhVien& a, const SinhVien& b);
bool tenGiam(const SinhVien& a, const SinhVien& b);
```

Ví dụ cách gọi:

```cpp
sapXep(danhSach, soLuong, diemTang);
sapXep(danhSach, soLuong, diemGiam);
```

`sapXep` có thể dùng selection sort hoặc interchange sort tự cài đặt. Điều kiện đổi chỗ hoàn toàn do `soSanh` quyết định, vì vậy không viết hai hàm sắp xếp riêng cho tăng và giảm.

Quy ước cho hàm so sánh: trả về `true` khi `a` cần đứng sau `b`. `diemTang` so sánh điểm của `a` lớn hơn điểm của `b`; `diemGiam` so sánh ngược lại. Khi điểm bằng nhau, so mã sinh viên tăng dần bằng `soSanhChuoi`. Các hàm so sánh họ tên dùng `soSanhChuoi` trên toàn bộ họ tên, rồi so mã tăng dần nếu trùng họ tên. Đây là thứ tự theo byte, không phải thứ tự từ điển tiếng Việt. Tiêu chí phụ giúp kết quả xác định; không có nghĩa thuật toán là sắp xếp ổn định.

Việc hoán đổi có thể thực hiện bằng một biến tạm kiểu `SinhVien`; không dùng `std::sort` hoặc `std::swap`.

```cpp
SinhVien tam;
tam = danhSach[i];
danhSach[i] = danhSach[j];
danhSach[j] = tam;
```

Cả ba phép gán trên đều gọi `operator=` tự định nghĩa.

## 8. Menu chương trình

```text
========== QUAN LY SINH VIEN ==========
1. Them sinh vien
2. Sua thong tin sinh vien
3. Xoa sinh vien
4. Tim kiem sinh vien
5. Xem mot sinh vien
6. Xem danh sach
7. Sap xep tang
8. Sap xep giam
0. Thoat
========================================
```

Khi chọn sắp xếp tăng/giảm, chương trình có thể hỏi thêm tiêu chí (điểm trung bình hoặc họ tên), rồi truyền con trỏ hàm tương ứng vào `sapXep`.

Menu chạy trong vòng lặp cho đến khi người dùng chọn `0`. Lựa chọn không hợp lệ phải được thông báo và yêu cầu nhập lại, không làm chương trình kết thúc bất ngờ.

## 9. Luồng hoạt động tổng quát

```text
Bắt đầu
   |
Khởi tạo danhSach = nullptr, soLuong = 0, sucChua = 0
   |
Hiển thị menu và đọc lựa chọn
   |
Gọi hàm chức năng tương ứng
   |
Quay lại menu nếu lựa chọn khác 0
   |
delete[] danhSach
   |
Kết thúc
```

## 10. Trường hợp cần kiểm thử

1. Xem, sửa, xóa và tìm kiếm khi danh sách rỗng.
2. Thêm sinh viên đầu tiên khi con trỏ đang là `nullptr`.
3. Thêm đủ phần tử để mảng phải tăng sức chứa nhiều lần.
4. Thêm sinh viên có mã rỗng hoặc trùng mã.
5. Nhập họ tên có khoảng trắng.
6. Nhập điểm nhỏ hơn `0`, lớn hơn `10`, ký tự hoặc luồng nhập lỗi.
7. Sửa hoặc xóa một mã không tồn tại.
8. Xóa phần tử đầu, giữa, cuối và phần tử duy nhất.
9. Tìm kiếm không có kết quả và có nhiều kết quả.
10. Sắp xếp tăng/giảm với danh sách rỗng, một phần tử, các điểm bằng nhau và dữ liệu đã có thứ tự.
11. Thoát chương trình và kiểm tra không rò rỉ bộ nhớ.
12. Kiểm tra phép gán sao chép đầy đủ các trường, tự gán `a = a` và gán nối tiếp `a = b = c`.
13. Kiểm tra các hàm chuỗi với chuỗi rỗng, chuỗi bằng nhau, chuỗi tiền tố và giới hạn kích thước mảng đích.
14. Kiểm tra EOF trong menu và khi nhập sinh viên để bảo đảm chương trình thoát được và giải phóng mảng.
15. Khởi tạo sao chép `SinhVien b(a)`, sửa `b` và kiểm tra `a` không đổi; hủy một đối tượng rồi kiểm tra đối tượng còn lại vẫn sử dụng được.
16. Gán hoặc cập nhật nhiều lần với chuỗi dài/ngắn khác nhau, kiểm tra không rò rỉ bộ nhớ và không giải phóng trùng.

## 11. Tiêu chí hoàn thành

- Biên dịch được từ ba file `SinhVien.h`, `SinhVien.cpp`, `main.cpp`.
- Chỉ có class `SinhVien`.
- `maSinhVien`, `hoTen`, `lop` là `char*`; `ngaySinh` là `char[11]`, `gioiTinh` là `char[5]`; điểm trung bình là `float`.
- Có destructor, constructor sao chép và `operator=` quản lý đúng ba vùng nhớ động; hai mảng cố định được sao chép nội dung.
- Không include `<string>` và không xuất hiện `std::string`, `vector`, `list`, `std::sort` hoặc STL algorithm.
- Không include `<cstring>`, `<string.h>` và không dùng hàm xử lý chuỗi có sẵn như `strcmp`, `strstr`, `strcpy`; các thao tác cần thiết đều được tự cài đặt trên mảng `char`.
- Mảng động tăng sức chứa đúng và được giải phóng khi kết thúc.
- Mã sinh viên không trùng.
- Đủ sáu nhóm chức năng thêm, sửa, xóa, tìm kiếm, xem một sinh viên và xem danh sách.
- Chỉ có một hàm sắp xếp, sử dụng con trỏ hàm cho cả tăng và giảm.
- Có tự định nghĩa `operator>>`, `operator<<` và `operator=`, sử dụng thật sự trong chương trình.
- Mọi toán tử khác dùng trực tiếp trên đối tượng `SinhVien` đều được nạp chồng tương ứng; không có toán tử nạp chồng dư thừa.
- Xử lý được các dữ liệu nhập sai cơ bản mà không làm chương trình bị treo hoặc kết thúc bất thường.
