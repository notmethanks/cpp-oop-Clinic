Quản Lý Phòng Khám
Giới thiệu

Chương trình mô phỏng hệ thống quản lý phòng khám với các chức năng cơ bản: quản lý bệnh nhân, bác sĩ, lịch hẹn và lịch sử khám chữa bệnh.

Chức năng chính

Thêm bệnh nhân thường và bệnh nhân mãn tính

Thêm bác sĩ với chuyên khoa

Lập lịch hẹn giữa bệnh nhân và bác sĩ

Xem danh sách bệnh nhân, bác sĩ, lịch hẹn

Cập nhật tình trạng hẹn khám (ví dụ: Completed, Cancelled)

Cấu trúc chương trình

Patient: lớp bệnh nhân cơ bản

ChronicPatient: kế thừa từ Patient, có thêm thông tin bệnh mãn tính

Doctor: quản lý thông tin bác sĩ và các cuộc hẹn được giao

Appointment: chứa thông tin về ngày, giờ, lý do hẹn, tình trạng, mã bệnh nhân và mã bác sĩ

Clinic: lớp chính quản lý toàn bộ danh sách bệnh nhân, bác sĩ và lịch hẹn

Cách sử dụng

Biên dịch chương trình:

g++ main.cpp -o clinic


Chạy chương trình:

./clinic


Thực hiện các thao tác qua menu:

1: Thêm bệnh nhân

2: Thêm bệnh nhân mãn tính

3: Thêm bác sĩ

4: Xem danh sách bệnh nhân

5: Xem danh sách bác sĩ

6: Lập lịch hẹn

7: Xem danh sách lịch hẹn

0: Thoát

Ví dụ chạy thử

Input (qua menu):

1
BN01
Nguyen Van A
25
3
BS01
Tran Thi B
Tim mach
6
BN01
BS01
01/10/2025
08:00
Kiem tra suc khoe
7
0


Output:

Nguyen Van A can schedule appointment as needed.
Appointment scheduled successfully.
Appointment: 01/10/2025 08:00, Reason: Kiem tra suc khoe, Patient: BN01, Doctor: BS01, Status: Scheduled

Kết luận

Bài tập áp dụng kiến thức về:

Kế thừa, đa hình trong C++

Quản lý đối tượng bằng vector và con trỏ

Tổ chức chương trình theo hướng đối tượng
