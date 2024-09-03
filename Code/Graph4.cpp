#include <bits/stdc++.h>
using namespace std;
// Danh sách kề sang ma trận kề
int main()
{
    int A[100][100];
    int vertise;
    cin >> vertise;
    cin.ignore();
    for (int i = 1; i <= vertise; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num)
        {
            A[i][stoi(num)] = 1;
        }
    }
    for (int i = 1; i <= vertise; i++)
    {
        for (int j = 1; j <= vertise; j++)
            cout << A[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
/*
Đoạn lệnh đó dùng để chuyển đổi một dòng chuỗi thành các số nguyên và lưu vào ma trận A.

Chi tiết giải thích các dòng lệnh:

stringstream ss(s);: Đây là một đối tượng stringstream được khởi tạo từ chuỗi s. 
stringstream cho phép xử lý chuỗi dưới dạng stream và giúp chúng ta trích xuất các giá trị từ chuỗi một cách thuận tiện.

while (ss >> num): Vòng lặp này sẽ chạy cho đến khi không còn giá trị nào có thể trích xuất từ stringstream. 
Mỗi lần lặp, giá trị được trích xuất từ stringstream và gán vào biến num.

A[i][stoi(num)] = 1;: Đây là phần gán giá trị vào ma trận A. 
Biến num được chuyển đổi thành số nguyên bằng cách sử dụng hàm stoi(). 
Giá trị số nguyên này được sử dụng như một chỉ số để gán giá trị 1 vào ma trận A. 
Điều này đại diện cho một liên kết từ đỉnh i tới đỉnh có chỉ số là num trong đồ thị.

Tóm lại, đoạn mã này đọc từng dòng chuỗi đầu vào, 
chuyển đổi các giá trị trong dòng thành số nguyên và gán giá trị 1 vào ma trận A tại các vị trí tương ứng. 
Điều này cho phép biểu diễn danh sách kề của các đỉnh trong đồ thị dưới dạng ma trận kề.
*/