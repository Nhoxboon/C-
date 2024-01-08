#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Tạo ra neighbors của x
vector<int> generate_neighbors(int x) 
{
    vector<int> neighbors;
    int step = 1;

    // Thêm các neighbors mới bằng cách tăng và giảm giá trị của x
    neighbors.push_back(x - step); 
    neighbors.push_back(x + step);

    return neighbors;
}


int hill_climbing(int (*f)(int), int x0)
{
	int x = x0; // Giá trị đầu
	while (true) {
		vector<int> neighbors = generate_neighbors(x); //TÌm nút kề của x
		int best_neighbor = *max_element(neighbors.begin(), neighbors.end(),
			[f](int a, int b) {
				return f(a) < f(b);
			}); // tìm nút kề có giá trị hàm mục tiêu cao nhất
		if (f(best_neighbor) <= f(x)) // nếu nút kề tốt nhất mà vẫn không tốt hơn x thì dừng chương trình
			return x;
		x = best_neighbor; //Nếu nút hàng xóm tốt nhất có giá trị hàm mục tiêu cao hơn giá trị của x, thuật toán tiếp tục với hàng xóm tốt nhất
	}
}

int main()
{
	// Example usage
	int x0 = 1;
	int x = hill_climbing([](int x) { return x * x; }, x0);
	cout << "Result: " << x << endl;
	return 0;
}
