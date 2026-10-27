# ĐẶC TẢ CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN

## 1. Mục tiêu

Xây dựng chương trình quản lý sinh viên bằng lập trình hướng đối tượng C++, gồm hai lớp độc lập:

- `SinhVien`: lưu và xử lý thông tin của một sinh viên.
- `DSSV`: sở hữu và quản lý một danh sách sinh viên.

Chương trình có các chức năng cơ bản: thêm, xóa, sửa, tìm theo mã sinh viên và duyệt/xuất toàn bộ danh sách.

## 2. Ràng buộc kỹ thuật

- Chỉ sử dụng thư viện `<iostream>`.
- Không sử dụng `string`, `<cstring>`/`string.h` hoặc các hàm như `strlen`, `strcpy`, `strcmp`.
- Không sử dụng STL (`vector`, `list`, `algorithm`, ...).
- Không dùng kế thừa, lớp ảo hoặc đa hình.
- Mọi chuỗi trong `SinhVien` phải là mảng ký tự cấp phát động (`char*`), không dùng mảng ký tự có kích thước cố định làm thuộc tính.
- Danh sách là một mảng động các đối tượng sinh viên: `SinhVien* ds`.
- Các lớp tự quản lý bộ nhớ, sao chép sâu và không để rò rỉ bộ nhớ.
- Có nạp chồng `>>`, `<<`, `=` cho `SinhVien`. Chỉ nạp chồng thêm toán tử khi toán tử đó thực sự được dùng trực tiếp với đối tượng `SinhVien`; không gán ý nghĩa tùy tiện cho toán tử.

## 3. Cấu trúc tệp dự kiến

```text
QLSV/
|-- SinhVien.h
|-- SinhVien.cpp
|-- DSSV.h
|-- DSSV.cpp
|-- XuLyChuoi.h
|-- XuLyChuoi.cpp
|-- main.cpp
`-- docs.md
```

- Tệp `.h` chỉ khai báo lớp và hàm.
- Tệp `.cpp` cài đặt các hàm đã khai báo.
- `XuLyChuoi.h/.cpp` chứa các hàm xử lý `char*` và luồng nhập dùng chung.
- `main.cpp` tạo menu và gọi các chức năng của `DSSV`.

## 4. Lớp `SinhVien`

### 4.1. Thuộc tính

Theo `SinhVien.h` hiện tại:

| Thuộc tính | Kiểu | Ý nghĩa |
|---|---|---|
| `maSV` | `char*` | Mã sinh viên, duy nhất và không rỗng |
| `hoTen` | `char*` | Họ tên sinh viên |
| `lop` | `char*` | Tên/mã lớp |
| `diemTB` | `double` | Điểm trung bình |

Ba chuỗi phải có vùng nhớ độc lập, có đúng `độ_dài + 1` phần tử và kết thúc bằng ký tự `\0`.

### 4.2. Giao diện đề xuất

```cpp
class SinhVien {
private:
    char* maSV;
    char* hoTen;
    char* lop;
    double diemTB;

public:
    SinhVien();
    ~SinhVien();

    SinhVien& operator=(const SinhVien& sv);

    const char* getMaSV() const;
    double getDiemTB() const;
    void setMaSV(const char* ma);
    void setHoTen(const char* ten);
    void setLop(const char* tenLop);
    void setDiemTB(double diem);

    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
};
```

`getMaSV()` được dùng khi tìm kiếm và kiểm tra trùng mã. `getDiemTB()` được dùng trong các hàm so sánh khi sắp xếp. Bốn setter được dùng khi sửa thông tin sinh viên. Không khai báo `getHoTen()` hoặc `getLop()` vì các chức năng hiện tại không cần đọc riêng hai giá trị này.

### 4.3. Quản lý bộ nhớ

Trong phạm vi bài toán này, `SinhVien` cần:

1. Destructor: `delete[]` từng chuỗi.
2. Toán tử gán `=`: kiểm tra tự gán, sao chép sâu và trả về `*this`. Toán tử này được dùng khi thêm, xóa và dịch chuyển phần tử trong mảng `DSSV`.

Không cần constructor có tham số hoặc copy constructor vì quy trình cơ bản chỉ tạo sinh viên bằng constructor mặc định, nhập bằng `>>` và sao chép bằng toán tử `=`. Không truyền hay trả về `SinhVien` theo giá trị.

Trong toàn bộ chương trình phải tránh câu lệnh khởi tạo sao chép như `SinhVien b = a;` vì bài không cài copy constructor. Khi cần sao chép, tạo đối tượng trước rồi dùng `b = a;`.

Toán tử gán không được chỉ gán địa chỉ con trỏ vì sẽ làm hai đối tượng cùng sở hữu một vùng nhớ, dẫn đến thay đổi dữ liệu ngoài ý muốn và lỗi giải phóng hai lần.

Một hàm setter chuỗi nên cấp phát vùng nhớ mới trước, sau đó mới giải phóng vùng nhớ cũ. Cách này vẫn giữ nguyên dữ liệu cũ nếu việc cấp phát thất bại và cũng xử lý an toàn trường hợp nguồn chính là chuỗi hiện tại của đối tượng.

### 4.4. Hàm xử lý chuỗi tự cài đặt

Không dùng `string.h`; các hàm hỗ trợ được khai báo trong `XuLyChuoi.h` và cài đặt trong `XuLyChuoi.cpp`:

```cpp
int doDaiChuoi(const char* s);
void saoChepChuoi(char* dich, const char* nguon);
bool haiChuoiBangNhau(const char* a, const char* b);
```

Quy ước:

- Các hàm phải xử lý được con trỏ `nullptr`.
- `saoChepChuoi` sao chép từng ký tự từ chuỗi nguồn sang vùng nhớ đích đã được cấp phát đủ chỗ.
- Dữ liệu nhập được đọc qua mảng tạm `char[100]`; các thuộc tính của `SinhVien` vẫn được cấp phát động theo đúng độ dài thực tế.
- Không cần đưa các hàm chỉ dùng nội bộ vào giao diện công khai của lớp.

### 4.5. Nạp chồng toán tử

#### Toán tử nhập `>>`

`operator>>` nhập đủ mã, họ tên, lớp và điểm trung bình. Chuỗi được đọc cả khoảng trắng và được cấp phát đúng kích thước. Điểm phải được kiểm tra trong khoảng `[0, 10]`; nếu nhập sai thì yêu cầu nhập lại.

Hàm trả về `istream&` để cho phép viết:

```cpp
cin >> sv1 >> sv2;
```

#### Toán tử xuất `<<`

`operator<<` chỉ ghi dữ liệu vào luồng `out`, không tự in lời nhắc nhập và không dùng trực tiếp `cout` bên trong. Hàm trả về `ostream&` để có thể nối các phép xuất.

#### Toán tử gán `=`

`operator=` thực hiện sao chép sâu và trả về `SinhVien&`:

```cpp
SinhVien& SinhVien::operator=(const SinhVien& sv);
```

Trong phạm vi chức năng hiện tại không cần nạp chồng `==`, `<` hoặc `>` vì tìm kiếm có thể so sánh mã qua hàm xử lý chuỗi. Nếu phần cài đặt dùng trực tiếp biểu thức như `sv1 == sv2`, toán tử tương ứng phải được khai báo và định nghĩa rõ; khi đó `==` nên biểu thị hai sinh viên có cùng mã.

## 5. Lớp `DSSV`

### 5.1. Thuộc tính và quyền sở hữu

```cpp
class DSSV {
private:
    SinhVien* ds;
    int soLuong;
};
```

- `ds` trỏ đến một mảng động chứa `soLuong` đối tượng `SinhVien` liên tiếp.
- Mảng được cấp phát bằng `new SinhVien[soLuong]` và giải phóng bằng `delete[] ds`.
- Mỗi phần tử được truy cập trực tiếp bằng `ds[i]`, không cần giải tham chiếu con trỏ hai lần.
- `DSSV` sở hữu toàn bộ mảng đối tượng này.
- Danh sách rỗng có trạng thái `ds == nullptr` và `soLuong == 0`.

### 5.2. Giao diện đề xuất

```cpp
class DSSV {
private:
    SinhVien* ds;
    int soLuong;

public:
    DSSV();
    ~DSSV();

    int timTheoMa(const char* ma) const;
    bool them(const SinhVien& sv);
    bool xoaTheoMa(const char* ma);
    bool suaTheoMa(const char* maCu, const SinhVien& thongTinMoi);
    bool xuatTheoMa(const char* ma, ostream& out) const;
    void sapXep(bool (*hamSoSanh)(const SinhVien&, const SinhVien&));
    static bool soSanhTang(const SinhVien& sv1, const SinhVien& sv2);
    static bool soSanhGiam(const SinhVien& sv1, const SinhVien& sv2);
    void duyet(ostream& out) const;
};
```

Không khai báo copy constructor, `operator=` hoặc `getSoLuong()` cho `DSSV` vì các chức năng cơ bản không gọi chúng. Chương trình chỉ tạo một đối tượng `DSSV` trong `main` và không sao chép hay gán danh sách. `DSSV` chỉ cần constructor mặc định để tạo danh sách rỗng và destructor để giải phóng mảng.

### 5.3. Tìm kiếm theo mã

`timTheoMa` duyệt tuần tự từ đầu đến cuối:

- Trả về chỉ số `0 .. soLuong - 1` nếu tìm thấy.
- Trả về `-1` nếu không tìm thấy hoặc mã đầu vào không hợp lệ.
- So sánh nội dung chuỗi bằng `haiChuoiBangNhau`, không so sánh hai địa chỉ `char*` bằng `==`.

Độ phức tạp: `O(n)`.

### 5.4. Thêm sinh viên

`them(const SinhVien& sv)`:

1. Từ chối nếu mã rỗng hoặc đã tồn tại.
2. Cấp phát mảng mới bằng `new SinhVien[soLuong + 1]`.
3. Gán lần lượt các phần tử cũ sang mảng mới bằng `SinhVien::operator=`.
4. Gán `sv` vào vị trí cuối: `temp[soLuong] = sv`.
5. Giải phóng mảng cũ bằng `delete[] ds`.
6. Cập nhật `ds`, tăng `soLuong` và trả về `true`.

Nếu mã bị trùng thì không thay đổi danh sách và trả về `false`.

### 5.5. Xóa theo mã

`xoaTheoMa(const char* ma)`:

1. Tìm vị trí cần xóa; nếu không có thì trả về `false`.
2. Nếu đây là phần tử duy nhất, `delete[] ds`, đặt `ds = nullptr`, `soLuong = 0`.
3. Nếu còn phần tử, tạo mảng mới bằng `new SinhVien[soLuong - 1]`.
4. Gán mọi phần tử, trừ phần tử tại vị trí cần xóa, sang mảng mới.
5. `delete[] ds`; thao tác này tự gọi destructor của từng phần tử trong mảng cũ.
6. Cập nhật `ds`, giảm `soLuong` và trả về `true`.

Không gọi `delete ds[i]` hoặc `delete[] ds[i]` vì `ds[i]` là một đối tượng `SinhVien`, không phải con trỏ.

### 5.6. Sửa theo mã

Mã truyền vào ban đầu dùng để xác định sinh viên cần sửa. Sau khi tìm thấy, chương trình cho phép nhập lại mã sinh viên, họ tên, lớp và điểm trung bình.

Trước khi gọi `setMaSV()`, `DSSV` phải kiểm tra mã mới:

1. Mã mới không được rỗng.
2. Gọi `timTheoMa(maMoi)` để kiểm tra mã đã tồn tại hay chưa.
3. Nếu mã mới thuộc một sinh viên khác thì từ chối cập nhật mã.
4. Nếu mã mới chính là mã hiện tại, hoặc chưa tồn tại trong danh sách, thì được phép gọi `setMaSV(maMoi)`.

Ví dụ kiểm tra theo vị trí:

```cpp
int viTriCu = timTheoMa(maCu);
int viTriMoi = timTheoMa(maMoi);

if (viTriMoi != -1 && viTriMoi != viTriCu) {
    cout << "Ma sinh vien da ton tai!\n";
    return false;
}

ds[viTriCu].setMaSV(maMoi);
```

Sau khi mã hợp lệ, hàm dùng `setHoTen()`, `setLop()` và `setDiemTB()` để cập nhật các thông tin còn lại. Hàm trả về `false` nếu không tìm thấy sinh viên hoặc mã mới không hợp lệ, đồng thời không được thay đổi phần tử khác.

### 5.7. Xuất kết quả tìm kiếm và duyệt danh sách

`xuatTheoMa(const char* ma, ostream& out)` gọi `timTheoMa()`. Nếu tìm thấy, hàm xuất sinh viên tương ứng và trả về `true`; nếu không tìm thấy thì trả về `false`. Hàm này được menu sử dụng cho chức năng tìm kiếm theo mã.

`duyet(ostream& out) const` đi từ `0` đến `soLuong - 1` và xuất từng đối tượng bằng toán tử `<<`:

```cpp
out << ds[i];
```

`ds[i]` đã là một đối tượng `SinhVien`, nên toán tử `<<` của lớp được gọi trực tiếp.

### 5.8. Sắp xếp theo điểm bằng con trỏ hàm

Chương trình chỉ có một hàm sắp xếp:

```cpp
void sapXep(bool (*hamSoSanh)(const SinhVien&, const SinhVien&));
```

Con trỏ `hamSoSanh` nhận địa chỉ một trong hai hàm:

```cpp
static bool soSanhTang(const SinhVien& sv1, const SinhVien& sv2);
static bool soSanhGiam(const SinhVien& sv1, const SinhVien& sv2);
```

`soSanhTang` trả về `true` khi sinh viên thứ nhất có điểm lớn hơn sinh viên thứ hai. `soSanhGiam` trả về `true` khi sinh viên thứ nhất có điểm nhỏ hơn sinh viên thứ hai. Khi hàm so sánh trả về `true`, `sapXep()` đổi chỗ hai sinh viên.

Hai cách gọi vẫn dùng chung một thuật toán:

```cpp
danhSach.sapXep(DSSV::soSanhTang);
danhSach.sapXep(DSSV::soSanhGiam);
```

Biến tạm đổi chỗ phải được tạo mặc định rồi mới gán:

```cpp
SinhVien tam;
tam = ds[i];
```

Không viết `SinhVien tam = ds[i];` vì cách đó gọi copy constructor, trong khi phiên bản cơ bản không cài copy constructor.

## 6. Hủy danh sách đúng cách

Destructor của `DSSV` chỉ cần giải phóng mảng:

```cpp
delete[] ds;
```

`delete[] ds` tự gọi destructor của từng `SinhVien`. Mỗi destructor tiếp tục giải phóng `maSV`, `hoTen` và `lop` của chính sinh viên đó.

## 7. Menu chương trình

Menu trong `main.cpp` có thể gồm:

```text
1. Them sinh vien
2. Xoa sinh vien theo ma
3. Sua sinh vien theo ma
4. Tim sinh vien theo ma
5. Xuat danh sach sinh vien
0. Thoat
```

Luồng xử lý đề xuất:

- Chức năng thêm: tạo một `SinhVien` tạm, dùng `cin >> sv`, rồi gọi `danhSach.them(sv)`.
- Chức năng tìm: gọi `timTheoMa`; nếu tìm thấy thì xuất sinh viên tại vị trí đó thông qua một hàm công khai phù hợp hoặc cung cấp hàm `xuatTheoMa`.
- Các thông báo thành công/thất bại nên đặt ở `main.cpp`; các hàm nghiệp vụ trả về `bool` để không phụ thuộc trực tiếp vào giao diện menu.
- Phải xử lý ký tự xuống dòng còn lại trước khi đọc một dòng mới.

## 8. Các bất biến cần bảo đảm

Sau mọi thao tác, chương trình phải luôn thỏa mãn:

- `soLuong >= 0`.
- `soLuong == 0` khi và chỉ khi `ds == nullptr`.
- Khi `soLuong > 0`, `ds` trỏ đến một mảng hợp lệ gồm đúng `soLuong` đối tượng.
- Không có hai sinh viên có cùng `maSV`.
- Mỗi vùng nhớ động chỉ có đúng một chủ sở hữu và được giải phóng đúng một lần.
- Phép gán một `SinhVien` không làm hai đối tượng dùng chung các chuỗi động.
- Không thực hiện sao chép hoặc gán trực tiếp đối tượng `DSSV` trong phiên bản cơ bản.

## 9. Kịch bản kiểm thử tối thiểu

1. Tạo danh sách rỗng rồi duyệt, tìm và xóa.
2. Thêm một sinh viên hợp lệ.
3. Thử thêm sinh viên có mã trùng.
4. Thêm nhiều sinh viên, kể cả họ tên có khoảng trắng.
5. Tìm mã ở đầu, giữa, cuối và mã không tồn tại.
6. Sửa sinh viên tồn tại và không tồn tại; thử giữ nguyên mã, đổi sang mã mới và đổi sang mã đã thuộc sinh viên khác.
7. Xóa phần tử đầu, giữa, cuối; xóa đến khi danh sách rỗng.
8. Gán `sv = sv` để kiểm tra tự gán.
9. Dùng toán tử gán giữa hai `SinhVien`, sửa đối tượng nhận rồi kiểm tra đối tượng nguồn không đổi.
10. Kết thúc chương trình và kiểm tra không rò rỉ, không giải phóng hai lần.

## 10. Phạm vi hoàn thiện

Phiên bản cơ bản chỉ cần đáp ứng đầy đủ các chức năng trên. Không khai báo trước hàm chưa dùng. Sắp xếp, lưu tệp, thống kê, copy constructor/toán tử gán của `DSSV`, toán tử `[]` hoặc các toán tử so sánh sinh viên chỉ được bổ sung khi có chức năng thực tế gọi đến.
