#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct answer_t{
	int x1, y1, x2, y2;
};

bool cmp(const answer_t& lhs, const answer_t& rhs){
	if (lhs.x1 < rhs.x1)
		return true;
	if (lhs.x1 > rhs.x1)
		return false;
	if (lhs.y1 < rhs.y1)
		return true;
	if (lhs.y1 > rhs.y1)
		return false;
	if (lhs.x2 < rhs.x2)
		return true;
	if (lhs.x2 > rhs.x2)
		return false;
	return lhs.y2 < rhs.y2;
}
void testHorizontal(vector<vector<char>>& image, vector<answer_t>& answer){
	int row = image.size(), col = image[0].size();
	for (int i = 1; i < row; i++){
		bool ok = true;
		for (int r = 0; r < i; r++){
			int r2 = i - r + i - 1;
			if (r2 >= row)
				break;
			for (int c = 0; c < col; c++)
				if (image[r][c] == image[r2][c]){
					ok = false;
					break;
				}
			if (!ok)
				break;
		}
		for (int r 
		for (int r = 2 * i; r < row; r++){
			for (int c = 0; c < col; c++)
				if (image[r][c] != '#'){
					ok = false;
					break;
				}
			if (!ok)
				break;
		}
		if (ok){
			answer.push_back({i, 0, i, col - 1});
			return;
		}
	}
}


void testVertical(vector<vector<char>>& image, vector<answer_t>& answer){
	int row = image.size(), col = image[0].size();
	for (int i = 1; i < col; i++){
		bool ok = true;
		for (int c = 0; c < i; c++){
			int c2 = i - c + i - 1;
			if (c2 >= col)
				break;
			for (int r = 0; r < row; r++)
				if (image[r][c] == image[r][c2]){
					ok = false;
					break;
				}
			if (!ok)
				break;
		}
		for (int c = 2 * i; c < col; c++){
			for (int r = 0; r < row; r++)
				if (image[r][c] != '#'){
					ok = false;
					break;
				}
			if (!ok)
				break;
		}
		if (ok){
			answer.push_back({0, i, row - 1, i});
			return;
		}
	}
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<char>> image(m, vector<char>(m));
	for (int row = 0; row < n; row++)
		for (int col = 0; col < m; col++)
			scanf(" %c ", &image[col][row]);
	
	vector<answer_t> answer;
	testHorizontal(image, answer);
	testVertical(image, answer);

	sort(answer.begin(), answer.end(), cmp);
	cout << answer[0].x1 + 1 << " " << answer[0].y1 + 1 << " " << answer[0].x2 + 1 << " " << answer[0].y2 + 1;
	return 0;
}
