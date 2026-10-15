Hệ thống Quản lý Kho sách & Mượn trả Thư viện Mini

1. Giới thiệu đề tài
   
Dự án Hệ thống Quản lý Kho sách & Mượn trả Thư viện Mini được xây dựng bằng ngôn ngữ C++ nhằm hỗ trợ quản lý thông tin sách, theo dõi số lượng sách trong kho và thực hiện các nghiệp vụ mượn, trả sách cơ bản trong thư viện.

Chương trình sử dụng danh sách liên kết đơn (Singly Linked List) để lưu trữ và quản lý dữ liệu sách. Cấu trúc này cho phép cấp phát bộ nhớ động và linh hoạt thêm, sửa hoặc cập nhật thông tin trong quá trình chương trình hoạt động.

Bên cạnh đó, dự án áp dụng các thuật toán tìm kiếm tuần tự, sắp xếp chọn (Selection Sort) và sắp xếp chèn (Insertion Sort) trên danh sách liên kết đơn. Dữ liệu được hỗ trợ đọc và ghi từ file .txt nhằm lưu trữ thông tin và sử dụng lại trong những lần chạy tiếp theo.

2. Mục tiêu đề tài

Vận dụng cấu trúc dữ liệu danh sách liên kết đơn trong bài toán quản lý sách.

Thực hành cấp phát và giải phóng bộ nhớ động trong C++.

Áp dụng các thuật toán tìm kiếm và sắp xếp trên danh sách liên kết đơn.

Xây dựng các chức năng quản lý sách và nghiệp vụ mượn, trả sách.

Thực hành thao tác đọc, ghi file văn bản để lưu trữ dữ liệu.

Rèn luyện kỹ năng lập trình, kiểm thử và làm việc nhóm thông qua GitHub.

3. Các chức năng chính

3.1. Quản lý thông tin sách

Thêm sách mới vào danh sách.

Sửa thông tin sách đã có.

Quản lý các thông tin cơ bản như mã sách, tên sách, tác giả, thể loại và số lượng.

3.2. Tìm kiếm và sắp xếp

Tìm kiếm sách bằng thuật toán tìm kiếm tuần tự.

Sắp xếp danh sách sách bằng thuật toán Selection Sort.

Sắp xếp danh sách sách bằng thuật toán Insertion Sort.

3.3. Quản lý mượn và trả sách

Thực hiện nghiệp vụ mượn sách.

Cập nhật số lượng sách còn trong kho khi mượn.

Thực hiện nghiệp vụ trả sách.

Cập nhật lại số lượng sách sau khi trả.

Kiểm tra tính hợp lệ của số lượng sách trước khi thực hiện giao dịch.

3.4. Quản lý tồn kho và lọc sách

Kiểm tra số lượng sách còn trong kho.

Lọc và hiển thị sách theo thể loại.

Hỗ trợ theo dõi tình trạng sách trong quá trình quản lý.

3.5. Lưu trữ dữ liệu

Đọc dữ liệu sách từ file .txt khi khởi động chương trình (nếu được triển khai).

Ghi dữ liệu vào file .txt để lưu trữ thông tin.

Giải phóng bộ nhớ động đã cấp phát khi không còn sử dụng.

4. Công nghệ và kiến thức sử dụng

Ngôn ngữ lập trình: C++.

Cấu trúc dữ liệu: Danh sách liên kết đơn (Singly Linked List).

Cấu trúc Node: Sử dụng struct hoặc class với con trỏ liên kết đến Node tiếp theo.

Quản lý bộ nhớ: Cấp phát và giải phóng bộ nhớ động.

Thuật toán tìm kiếm: Tìm kiếm tuần tự (Linear Search).

Thuật toán sắp xếp: Selection Sort và Insertion Sort.

Lưu trữ dữ liệu: File văn bản .txt.

Quản lý mã nguồn: Git và GitHub.

5. Yêu cầu cài đặt

Để biên dịch và chạy chương trình, máy tính cần có:

Hệ điều hành Windows, Linux hoặc macOS.

Trình biên dịch C++ hỗ trợ chuẩn C++11 trở lên, ví dụ GCC/G++.

Trình soạn thảo mã nguồn như Visual Studio Code, Code::Blocks hoặc Dev-C++.

Các file mã nguồn .cpp, file tiêu đề .h (nếu có) và file dữ liệu cần thiết của dự án.
