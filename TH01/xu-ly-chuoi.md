# Giải thích các hàm xử lý chuỗi

Tài liệu này giải thích bốn hàm tự viết đang được sử dụng trong `SinhVien.cpp`, được khai báo trong `SinhVien.h`. Các hàm thao tác trực tiếp trên mảng `char`, không dùng thư viện chuỗi.

## 1. Chuỗi trong mảng `char` hoạt động như thế nào?

```cpp
char ten[] = "An";
```

Mảng trên gồm ba phần tử:

| Chỉ số | 0 | 1 | 2 |
|---|---|---|---|
| Giá trị | `'A'` | `'n'` | `'\0'` |

`'\0'` là ký tự kết thúc chuỗi, có giá trị bằng 0. Nó khác ký tự chữ số `'0'`. Các hàm dựa vào dấu kết thúc này để biết lúc nào phải dừng đọc.

- `""` là chuỗi rỗng: phần tử đầu tiên đã là `'\0'`.
- `const char chuoi[]` trong tham số hàm tương đương `const char* chuoi`: hàm không được sửa ký tự thông qua tham số này.
- Tham số mảng không tự mang theo kích thước. Vì vậy, hàm sao chép cần nhận thêm kích thước mảng đích.
- Mọi chuỗi truyền vào phải tồn tại, không phải con trỏ null và có `'\0'` trong vùng nhớ hợp lệ. Các hàm này không tự kiểm tra những điều kiện đó.
- Với UTF-8, một chữ tiếng Việt có thể chiếm nhiều byte. Duyệt từng `char` là duyệt từng byte, không phải từng chữ người dùng nhìn thấy.

## 2. `doDaiChuoi`: đếm độ dài

```cpp
int doDaiChuoi(const char chuoi[]) {
    int n = 0;
    while (chuoi[n] != '\0') ++n;
    return n;
}
```

`n` vừa là chỉ số đang kiểm tra, vừa là số phần tử đã đi qua. Hàm bắt đầu từ chỉ số 0, tăng `n` cho đến khi gặp `'\0'`. Giá trị trả về không tính ký tự kết thúc.

Ví dụ với `"An"`: kiểm tra `'A'` rồi tăng `n` thành 1; kiểm tra `'n'` rồi tăng thành 2; gặp `'\0'` ở chỉ số 2 thì dừng và trả về 2.

```cpp
doDaiChuoi("An");  // 2
doDaiChuoi("");    // 0
```

Hàm được dùng để kiểm tra sức chứa trước khi sao chép, kiểm tra độ dài ngày sinh và bỏ khoảng trắng ở hai đầu dữ liệu nhập.

## 3. `soSanhChuoi`: so sánh hai chuỗi

```cpp
int soSanhChuoi(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) ++i;

    if (a[i] == b[i]) return 0;
    if (a[i] < b[i]) return -1;
    return 1;
}
```

Hàm bỏ qua các ký tự giống nhau ở đầu hai chuỗi. Vòng lặp dừng khi gặp một cặp ký tự khác nhau hoặc khi chuỗi `a` kết thúc. Các câu lệnh `if` trả về kết quả theo thứ tự của hai ký tự tại vị trí dừng.

| Kết quả | Ý nghĩa |
|---|---|
| `-1` | `a` đứng trước `b` theo thứ tự ký tự |
| Bằng 0 | Hai chuỗi giống nhau |
| `1` | `a` đứng sau `b` theo thứ tự ký tự |

Ví dụ:

```cpp
soSanhChuoi("An", "An");   // 0: cuoi cung so '\0' voi '\0'
soSanhChuoi("An", "Ao");   // Am: 'n' dung truoc 'o'
soSanhChuoi("B", "A");     // Duong: 'B' dung sau 'A'
soSanhChuoi("An", "Anh");  // Am: '\0' dung truoc 'h'
```

Không cần kiểm tra riêng `b[i] != '\0'` trong vòng lặp: nếu `b` kết thúc trước `a`, điều kiện `a[i] == b[i]` đã sai nên vòng lặp dừng.

Hàm không cần ép kiểu bằng `static_cast`, vì chỉ so sánh hai ký tự rồi trả về một trong ba số `-1`, `0`, `1`. Hàm có phân biệt chữ hoa/chữ thường và phù hợp với dữ liệu ASCII của bài. Nó không thực hiện sắp xếp theo quy tắc từ điển tiếng Việt.

Hiện tại, hàm này được dùng trong `nhapThongTin` để kiểm tra giới tính có bằng `"nam"`, `"nu"` hoặc `"khac"` hay không. Không dùng `a == b` để so nội dung hai mảng ký tự vì biểu thức đó thường so địa chỉ.

## 4. `saoChepChuoi`: sao chép có kiểm tra kích thước

```cpp
bool saoChepChuoi(char dich[], int kichThuocDich, const char nguon[]) {
    int n = doDaiChuoi(nguon);
    if (kichThuocDich <= n) return false;
    for (int i = 0; i <= n; ++i) dich[i] = nguon[i];
    return true;
}
```

Các tham số lần lượt là mảng nhận dữ liệu, số phần tử thực tế của mảng đó và chuỗi cần sao chép.

Hàm đếm độ dài nguồn là `n`. Mảng đích phải chứa được `n + 1` phần tử, bao gồm `'\0'`. Nếu không đủ chỗ, hàm trả về `false` ngay và giữ nguyên đích.

Vòng lặp dùng `i <= n`, thay vì `i < n`, để sao chép cả ký tự kết thúc nằm ở vị trí `n`.

```cpp
char dich[3];
saoChepChuoi(dich, sizeof dich, "An"); // true: can 3 phan tu

char nho[2] = "X";
saoChepChuoi(nho, sizeof nho, "An");  // false: nho van chua "X"
```

Trong `ganChuoi`, hàm được gọi sau khi cấp phát đúng số phần tử:

```cpp
int kichThuoc = doDaiChuoi(nguon) + 1;
char* chuoiMoi = new char[kichThuoc];
saoChepChuoi(chuoiMoi, kichThuoc, nguon);
```

Ba thuộc tính `maSinhVien`, `hoTen`, `lop` là `char*`, vì vậy không dùng `sizeof` để tính sức chứa của chúng. Kích thước vùng nhớ động được tính bằng độ dài nội dung cộng một phần tử cho `'\0'`. Với `ngaySinh[11]` và `gioiTinh[5]`, `sizeof` cho đúng sức chứa vì chúng là mảng thành viên cố định.

Hàm được thiết kế cho nguồn và đích riêng biệt như các thuộc tính của hai sinh viên; không dùng để dịch dữ liệu giữa những vùng nhớ chồng lấn. Người gọi phải truyền đúng sức chứa thực tế của đích.

## 5. `chuyenThanhChuThuong`: đổi một ký tự ASCII

```cpp
char chuyenThanhChuThuong(char kyTu) {
    if (kyTu >= 'A' && kyTu <= 'Z') kyTu += 'a' - 'A';
    return kyTu;
}
```

Nếu ký tự thuộc `'A'` đến `'Z'`, hàm cộng khoảng cách giữa chữ thường và chữ hoa vào ký tự. Sau đó hàm trả về ký tự đã chuyển.

Ví dụ khoảng cách `'a' - 'A'` cũng chính là khoảng cách từ `'C'` đến `'c'`. Phép `+=` cập nhật trực tiếp biến `kyTu`, nên không cần `static_cast`.

```cpp
chuyenThanhChuThuong('C'); // 'c'
chuyenThanhChuThuong('c'); // 'c'
chuyenThanhChuThuong('7'); // '7'
```

Ký tự được truyền bằng giá trị, nên hàm chỉ trả kết quả, không tự sửa biến của người gọi. Muốn sửa biến phải gán lại:

```cpp
char c = 'C';
c = chuyenThanhChuThuong(c);
```

Hàm chỉ chuyển chữ hoa ASCII; không chuyển được đầy đủ các chữ như `Đ`, `Ă`, `Ê` trong UTF-8.

## 6. Chi phí xử lý

Gọi `n` là độ dài chuỗi nguồn:

| Hàm | Thời gian trong trường hợp xấu nhất |
|---|---|
| `doDaiChuoi` | O(n) |
| `soSanhChuoi` | O(min(độ dài a, độ dài b) + 1) |
| `saoChepChuoi` | O(n), gồm đếm rồi sao chép |
| `chuyenThanhChuThuong` | O(1) |

Tất cả các hàm chỉ dùng một số biến đếm hoặc giá trị tạm, không cấp phát mảng phụ; bộ nhớ phụ là O(1).

## 7. Các vị trí sử dụng thực tế

| Hàm | Nơi gọi hiện tại |
|---|---|
| `doDaiChuoi` | `saoChepChuoi`, `nhapChuoi`, `ngayHopLe` |
| `soSanhChuoi` | `nhapThongTin`: kiểm tra giới tính |
| `saoChepChuoi` | `SinhVien::ganChuoi`: sao chép nội dung vào vùng nhớ mới |
| `chuyenThanhChuThuong` | `nhapThongTin`: chuẩn hóa giới tính |

Hai hàm tìm chuỗi con chưa có nơi gọi nên đã được bỏ khỏi code. Khi triển khai chức năng tìm kiếm trong `main.cpp`, chỉ bổ sung hàm tìm chuỗi phù hợp với cách tìm kiếm thực sự được chọn.
