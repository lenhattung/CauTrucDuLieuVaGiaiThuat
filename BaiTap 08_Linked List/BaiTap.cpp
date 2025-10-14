/*

BÀI 1: HỆ THỐNG QUẢN LÝ LỊCH SỬ DUYỆT WEB 🌐
	Mô tả:
	Bạn được yêu cầu xây dựng hệ thống quản lý lịch sử duyệt web giống như trình duyệt Chrome/Firefox.
	Yêu cầu chức năng:

1. Quản lý thông tin trang web:
Mỗi trang web cần lưu:
	URL (địa chỉ website)
	Tiêu đề trang
	Thời gian truy cập
	Số lần truy cập
	Favicon (biểu tượng - tùy chọn)

2. Các thao tác cần hỗ trợ:
	Thêm trang mới vào lịch sử (mỗi khi user truy cập)
	Xem lịch sử (hiển thị từ mới nhất đến cũ nhất)
	Tìm kiếm theo URL hoặc tiêu đề
	Xóa một trang khỏi lịch sử
	Xóa lịch sử theo khoảng thời gian (hôm nay, 7 ngày, tháng này, tất cả)
	Thống kê trang được truy cập nhiều nhất
	QUAN TRỌNG: Nút Back (quay lại trang trước)
	QUAN TRỌNG: Nút Forward (tiến tới trang sau)
	Bookmark (đánh dấu trang yêu thích)

3. Ví dụ kịch bản sử dụng:
	User truy cập: google.com → facebook.com → youtube.com
	Hiện tại: youtube.com

	Nhấn Back:
	- Quay về: facebook.com

	Nhấn Back lần nữa:
	- Quay về: google.com

	Nhấn Forward:
	- Tiến tới: facebook.com

	Nhấn Forward lần nữa:
	- Tiến tới: youtube.com

*/

/*

BÀI 2: HỆ THỐNG QUẢN LÝ PLAYLIST NHẠC 🎵

1. Quản lý thông tin bài hát:
Mỗi bài hát cần lưu:
	ID bài hát
	Tên bài hát
	Ca sĩ/Nghệ sĩ
	Thể loại (Pop, Rock, Ballad, Rap, EDM...)
	Thời lượng (giây)
	Đường dẫn file
	Số lần nghe
	Rating (1-5 sao)
	Lời bài hát (tùy chọn)

2. Các thao tác cần hỗ trợ:
	Quản lý danh sách:
		Thêm bài hát vào playlist
		Xóa bài hát khỏi playlist
		Tìm kiếm theo tên/ca sĩ/thể loại
		Sắp xếp theo: Tên, Ca sĩ, Thời lượng, Rating

		Phát nhạc:
		Play: Phát bài hiện tại
		Next: Chuyển sang bài tiếp theo
		Previous: Quay lại bài trước
		Shuffle: Xáo trộn thứ tự (random)
	Repeat Mode:
		Repeat Off: Phát hết playlist thì dừng
		Repeat All: Phát hết playlist thì lặp lại từ đầu
		Repeat One: Lặp lại 1 bài hiện tại


	Auto Play: Tự động phát bài tiếp theo khi hết bài


3. Ví dụ kịch bản sử dụng:
	Playlist: [Bai 1] -> [Bai 2] -> [Bai 3] -> [Bai 4]
	Dang phat: Bai 2

	Nhan Next:
	-> Chuyen sang: Bai 3

	Nhan Previous:
	-> Quay lai: Bai 2

	Che do Repeat All BAT:
	Phat: Bai 1 -> Bai 2 -> Bai 3 -> Bai 4 -> (lap lai) Bai 1 -> Bai 2...

	Che do Shuffle:
	Thu tu ngau nhien: Bai 3 -> Bai 1 -> Bai 4 -> Bai 2 -> ...

*/