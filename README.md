
🧪 Automated Chemical Laboratory Robot (ChemLab v2.0)
🌟 Giới thiệu
Dự án này tập trung vào việc xây dựng một hệ thống robot hỗ trợ thí nghiệm hóa học tự động, giúp giảm thiểu rủi ro cho con người khi tiếp xúc với hóa chất độc hại. Hệ thống sử dụng Arduino làm bộ não điều khiển và một ứng dụng di động (Android) được phát triển qua MIT App Inventor để tương tác thời gian thực qua giao thức Bluetooth.

🚀 Tính năng cốt lõi
Precision Control: Sử dụng 3 động cơ Servo để điều phối các trục chuyển động (Hút/Bơm hóa chất, Nâng/Hạ Piston).

Wireless Interaction: Điều khiển từ xa qua module Bluetooth HC-05 với độ trễ thấp.

Slow-Motion Algorithm: Tích hợp thuật toán nội suy góc quay (slowServo) giúp robot chuyển động mượt mà, tránh hiện tượng quán tính làm đổ vỡ dụng cụ thí nghiệm.

Safety First: Thiết lập vị trí khởi động an toàn (Safe-start position) để bảo vệ phần cứng.

🛠 Cấu trúc kỹ thuật (Technical Stack)
Hardware: Arduino Uno/Nano, Servo Motors, HC-05 Bluetooth Module, L298N/L293D (cho Piston).

Firmware: C++ (Arduino Framework).

Software: MIT App Inventor (Mobile App).
