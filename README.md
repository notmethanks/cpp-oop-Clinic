🏥 Quản Lý Phòng Khám
📌 Giới thiệu

Ứng dụng mô phỏng hệ thống quản lý phòng khám nhỏ, hỗ trợ quản lý:

👨‍⚕️ Bác sĩ

🧑‍🦰 Bệnh nhân thường và bệnh nhân mãn tính

📅 Lịch hẹn khám

📝 Lịch sử khám chữa bệnh

✨ Chức năng chính

➕ Thêm bệnh nhân thường

➕ Thêm bệnh nhân mãn tính (kế thừa từ bệnh nhân thường, có thêm thông tin bệnh mãn tính)

➕ Thêm bác sĩ với chuyên khoa

📆 Lập lịch hẹn giữa bệnh nhân và bác sĩ

📋 Xem danh sách bệnh nhân, bác sĩ, lịch hẹn

🔄 Cập nhật trạng thái lịch hẹn (Scheduled / Completed / Cancelled)

🏗️ Cấu trúc chương trình
Lớp	Mô tả
Patient	Quản lý thông tin bệnh nhân cơ bản (ID, tên, tuổi, lịch sử khám)
ChronicPatient	Kế thừa từ Patient, thêm bệnh mãn tính & ngày tái khám
Doctor	Quản lý thông tin bác sĩ, chuyên khoa & danh sách lịch hẹn
Appointment	Chứa thông tin ngày, giờ, lý do, trạng thái, bệnh nhân & bác sĩ
Clinic	Lớp trung tâm quản lý toàn bộ bệnh nhân, bác sĩ, lịch hẹn
⚙️ Hướng dẫn sử dụng
🖥️ Biên dịch & chạy
g++ main.cpp -o clinic
./clinic

📜 Menu thao tác
Số	Chức năng
1	Thêm bệnh nhân
2	Thêm bệnh nhân mãn tính
3	Thêm bác sĩ
4	Xem danh sách bệnh nhân
5	Xem danh sách bác sĩ
6	Lập lịch hẹn
7	Xem danh sách lịch hẹn
0	Thoát
🧪 Ví dụ chạy thử

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

📚 Kết luận

Bài tập áp dụng kiến thức:

🏗️ Lập trình hướng đối tượng trong C++

🧩 Kế thừa và đa hình

📦 Quản lý dữ liệu bằng vector

🔑 Đóng gói và tổ chức chương trình khoa học
