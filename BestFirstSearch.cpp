#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
vector<vector<pi> > graph;
 

void themNode(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}
 

void best_first_search(int actual_Src, int target, int n)
{
	/*
	Tạo một vector visited có kích thước n (số đỉnh trong đồ thị) và tất cả các phần tử được khởi tạo là false.
	Vector này được sử dụng để đánh dấu các đỉnh đã được ghé thăm trong quá trình tìm kiếm.
	*/
    vector<bool> visited(n, false);
    
	// MIN HEAP priority queue
    priority_queue<pi, vector<pi>, greater<pi> > pq;

    // việc sắp xếp trong pq được thực hiện theo giá trị đầu tiên của cặp
    pq.push(make_pair(0, actual_Src));
    int s = actual_Src;
    visited[s] = true;

    while (!pq.empty()) {
        int x = pq.top().second;
        // Hiển thị đường đi có trọng số thấp nhất
        cout << x << " ";
        pq.pop();
        if (x == target)
            break;
		
		/*
		Nếu đỉnh kề chưa được ghé thăm (`!visited[graph[x][i].second]`),
		đánh dấu nó đã ghé thăm và thêm vào hàng đợi ưu tiên với trọng số tương ứng (`graph[x][i].first`) 
		và đỉnh kề (`graph[x][i].second`).
		*/
        for (int i = 0; i < graph[x].size(); i++) {
            if (!visited[graph[x][i].second]) {
                visited[graph[x][i].second] = true;
                pq.push(make_pair(graph[x][i].first,graph[x][i].second));
            }
        }
    }
}
 
int main()
{
    int v = 14;
	/*
	do{
		cout << "Số đỉnh đề bài cho: ";
		cin >> v;
	}while (v <= 0);
	*/
	graph.resize(v);

	/*
	int x, y, cost;
	for (int i = 0; i < v; i++);
	{
		cout << "Nhập đỉnh x, đỉnh kề đỉnh x(là y) và trọng số: ";
		cin >> x >> y >> cost;

		themNode(x, y, cost);
	}
	*/

    themNode(0, 1, 3);
    themNode(0, 2, 6);
    themNode(0, 3, 5);
    themNode(1, 4, 9);
    themNode(1, 5, 8);
    themNode(2, 6, 12);
    themNode(2, 7, 14);
    themNode(3, 8, 7);
    themNode(8, 9, 5);
    themNode(8, 10, 6);
    themNode(9, 11, 1);
    themNode(9, 12, 10);
    themNode(9, 13, 2);
 
    int source;
	cout << "Đỉnh bắt đầu: ";
	cin >> source;
    int target;
	cout << "Đỉnh đích muốn tìm: ";
	cin >> target;
    
    best_first_search(source, target, v);
 
    return 0;
}