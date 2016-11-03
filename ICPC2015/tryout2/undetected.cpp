#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

class UnionFind{
private:
	vector<int> p, rank, setSize;
	int numSets;
public:
	UnionFind(int N){
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i ){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else{
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
			
		}
	}
	int numDisjointSets(){
		return numSets;
	}
	int sizeOfSet(int i ){
		return setSize[findSet(i)];
	}
};

struct circle_t{
	int x, y, r;
};

bool collision(const circle_t& c1, const circle_t& c2){
	return pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2) < pow(c1.r + c2.r, 2);
}
int main(){
	int N;
	scanf("%d", &N);
	UnionFind UF(N + 2);
	int answer = 0;
	vector<circle_t> circle(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &circle[i].x, &circle[i].y, &circle[i].r);
	
	for (int i = 0; i < N; i++){
		if (circle[i].x - circle[i].r < 0)
			UF.unionSet(i, N);
		if (circle[i].x + circle[i].r > 200)
			UF.unionSet(i, N + 1);	
		for (int j = 0; j < i; j++)
			if (collision(circle[i], circle[j]))
				UF.unionSet(i, j);
		if (UF.isSameSet(N, N + 1))
			break;
		answer++;
	}
	printf("%d\n", answer);
	return 0;
}
