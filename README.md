Dưới đây là bài mô tả chi tiết và hướng dẫn sử dụng/biên dịch cho chương trình **Hệ thống Quản lý Kho sách & Mượn trả Thư viện Mini**. Bài viết được trình bày rõ ràng, mạch lạc, đúng chuẩn bài báo cáo bài tập lớn hoặc tài liệu hướng dẫn dành cho người mới nhập môn.

---

# BÀI MÔ TẢ VÀ HƯỚNG DẪN SỬ DỤNG

## HỆ THỐNG QUẢN LÝ KHO SÁCH & MƯỢN TRẢ THƯ VIỆN MINI

---

## 1. MÔ TẢ CHƯƠNG TRÌNH

### 1.1. Mục đích ứng dụng

Chương trình **Hệ thống Quản lý Kho sách & Mượn trả Thư viện Mini** được thiết kế nhằm giúp người mới học lập trình nắm vững tư duy ứng dụng **Cấu trúc dữ liệu và Giải thuật (Data Structures & Algorithms)** vào giải quyết bài toán thực tế.

Dù được triển khai dưới dạng ứng dụng Web trực quan, toàn bộ tư duy xử lý cốt lõi của chương trình đều mô phỏng 100% cấu trúc quản lý bộ nhớ và giải thuật trên con trỏ trong các ngôn ngữ lập trình cơ bản như C/C++.

---

### 1.2. Các tính năng chính

Chương trình tích hợp đầy đủ các chức năng quản lý kho sách cơ bản:

1. **Quản lý Sách (Thêm / Sửa / Xóa):**
* Cấp phát động node mới khi thêm sách.
* Cập nhật thông tin khi trùng Mã Sách.
* Giải phóng node khi xóa sách khỏi danh sách.


2. **Quản lý Mượn / Trả Sách & Kiểm tra tồn kho:**
* Cho phép mượn sách (giảm số lượng tồn kho) và kiểm tra điều kiện hết sách.
* Cho phép trả sách (tăng số lượng tồn kho).


3. **Tìm kiếm & Lọc dữ liệu:**
* **Tìm kiếm tuần tự (Linear Search):** Tìm sách dựa trên từ khóa tên sách.
* **Lọc sách theo thể loại:** Trích xuất các sách thuộc cùng một nhóm thể loại.


4. **Thuật toán Sắp xếp (Sorting Algorithms):**
* **Sắp xếp Chọn (Selection Sort):** Sắp xếp danh sách theo số lượng tồn kho tăng dần bằng cách hoán đổi dữ liệu node.
* **Sắp xếp Chèn (Insertion Sort):** Sắp xếp danh sách theo tên sách (A-Z) bằng cách tái liên kết các con trỏ `next`.


5. **Đọc & Ghi File văn bản (`.txt`):**
* Xuất danh sách hiện tại ra file `danh_sach_sach.txt`.
* Đọc dữ liệu từ file `.txt` có sẵn để khởi tạo lại Danh sách liên kết.



---

### 1.3. Cấu trúc dữ liệu và Giải thuật áp dụng

| Khái niệm / Giải thuật | Cách triển khai trong mã nguồn |
| --- | --- |
| **Node (Mắt xích)** | Lớp `Node` gồm dữ liệu sách và con trỏ `next` trỏ tới Node tiếp theo. |
| **Singly Linked List** | Con trỏ `head` quản lý node đầu tiên, duyệt qua danh sách bằng vòng lặp `while (p !== null)`. |
| **Cấp phát & Giải phóng** | Khởi tạo bằng `new Node()`, giải phóng bằng cách hủy liên kết và gán `temp = null`. |
| **Linear Search** | Duyệt lần lượt từng node từ `head` đến cuối danh sách để so sánh chuỗi. |
| **Selection Sort** | Tìm node có số lượng nhỏ nhất trong phần chưa sắp xếp và hoán đổi dữ liệu. |
| **Insertion Sort** | Rút từng node khỏi danh sách cũ và chèn vào vị trí thích hợp trong danh sách mới đã sắp xếp. |

---

## 2. HƯỚNG DẪN CÀI ĐẶT VÀ CHẠY CHƯƠNG TRÌNH

Do chương trình được viết hoàn toàn bằng **HTML, CSS và JavaScript thuần (Vanilla JS)** trên cùng 1 tệp duy nhất, bạn **không cần cài đặt bất kỳ trình biên dịch (compiler) phức tạp hay máy chủ (server) nào**.

### Cách 1: Chạy trực tiếp trên trình duyệt Web (Khuyên dùng)

1. **Tạo tệp mã nguồn:**
* Tạo một tệp tin mới đặt tên là `index.html`.
* Dán toàn bộ đoạn mã HTML/JS đã được cung cấp vào tệp này và lưu lại (`Ctrl + S`).


2. **Khởi chạy ứng dụng:**
* Nhấp đôi chuột (double click) vào tệp `index.html`.
* Hoặc chuột phải vào tệp `index.html` $\rightarrow$ Chọn **Open with** $\rightarrow$ Chọn trình duyệt web bất kỳ (Google Chrome, Microsoft Edge, Mozilla Firefox, Brave,...).



---

### Cách 2: Chạy và biên dịch qua Extension "Live Server" trong VS Code

Nếu bạn đang sử dụng trình soạn thảo **Visual Studio Code**:

1. Mở thư mục chứa tệp `index.html` trong VS Code.
2. Vào mục **Extensions** (`Ctrl + Shift + X`), tìm kiếm extension tên **Live Server** và nhấn **Install**.
3. Chuột phải vào tệp `index.html` trong giao diện VS Code và chọn **Open with Live Server**.
4. Trình duyệt sẽ tự động mở trang web quản lý thư viện tại địa chỉ `[http://127.0.0.1:5500/index.html](http://127.0.0.1:5500/index.html)`.

---

## 3. HƯỚNG DẪN SỬ DỤNG CÁC CHỨC NĂNG

### 3.1. Thêm / Cập nhật sách

1. Nhập **Mã Sách**, **Tên Sách**, **Thể Loại**, và **Số Lượng**.
2. Nhấn nút **"Lưu Sách Vào Danh Sách"**:
* Nếu Mã Sách **mới**: Chương trình sẽ tạo một Node mới và nối vào cuối Danh sách liên kết.
* Nếu Mã Sách **đã tồn tại**: Chương trình tự động cập nhật lại thông tin của Node đó.



### 3.2. Mượn / Trả sách

1. Di chuyển đến mục **2. Mượn / Trả Sách**.
2. Nhập Mã Sách cần thao tác (VD: `S01`).
3. Nhấn nút **"Mượn 1 Cuốn"** (số lượng tồn kho giảm 1) hoặc **"Trả 1 Cuốn"** (số lượng tồn kho tăng 1).

### 3.3. Tìm kiếm & Lọc sách

* **Tìm kiếm theo tên:** Nhập từ khóa vào ô tìm kiếm $\rightarrow$ Nhấn **"Tìm Kiếm"** (Thực hiện thuật toán tìm kiếm tuần tự).
* **Lọc thể loại:** Nhập tên thể loại (VD: `Cong nghe`) $\rightarrow$ Nhấn **"Lọc Sách"**.
* Nhấn nút **"Hiển Thị Tất Cả"** để quay lại danh sách ban đầu.

### 3.4. Sắp xếp danh sách

* Nhấn nút **"Sắp Xếp Chọn (Selection Sort)..."** để sắp xếp danh sách theo số lượng tồn kho tăng dần.
* Nhấn nút **"Sắp Xếp Chèn (Insertion Sort)..."** để sắp xếp danh sách theo tên sách theo thứ tự bảng chữ cái A-Z.

### 3.5. Đọc & Ghi File (.txt)

* **Ghi File:** Nhấn nút **"Xuất / Lưu Danh Sách Ra File (.txt)"**, trình duyệt sẽ tải về tệp `danh_sach_sach.txt` chứa dữ liệu các node dạng: `Mã,Tên,ThểLoại,SốLượng`.
* **Đọc File:** Nhấn nút **"Choose File"** (hoặc **"Chọn tệp"**) $\rightarrow$ Chọn tệp `.txt` có định dạng tương tự để chương trình đọc và xây dựng lại Danh sách liên kết mới.
