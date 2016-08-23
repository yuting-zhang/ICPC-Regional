#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct droplet_t{
	double x, y, vx, vy, r;
};

int main(){	
	int N;
	while (cin >> N){
		vector<droplet_t> droplets(N);
		double total = 0;
		for (int i = 0; i < N; i++)
			cin >> droplets[i].x >> droplets[i].y >> droplets[i].vx >> droplets[i].vy >> droplets[i].r;

		while (true){
			double time = -1;
			int d1, d2;
			for (int i = 0; i < N - 1; i++)
				for (int j = i + 1; j < N; j++){
					double A = pow(droplets[i].vx - droplets[j].vx, 2) + pow(droplets[i].vy - droplets[j].vy, 2);
					double B = 2 * ((droplets[i].x - droplets[j].x) * (droplets[i].vx - droplets[j].vx) +
							(droplets[i].y - droplets[j].y) * (droplets[i].vy - droplets[j].vy));
					double C = pow(droplets[i].x - droplets[j].x, 2) + pow(droplets[i].y - droplets[j].y, 2) -
						pow(droplets[i].r + droplets[j].r, 2);

					double delta = pow(B, 2) - 4 * A * C;
					if (A == 0 || delta < 0)
						continue;
					double t1 = (-B + sqrt(delta)) / 2 / A;
					double t2 = (-B - sqrt(delta)) / 2 / A;

					if (t1 >= 0 && (time == -1 || t1 < time)){
						time = t1;
						d1 = i;
						d2 = j;
					}
					if (t2 >= 0 && (time == -1 || t2 < time)){
						time = t2;
						d1 = i;
						d2 = j;
					}
				}

			if (time < 0)
				break;

			total += time;
			for (int i = 0; i < N; i++){
				droplets[i].x = droplets[i].x + time * droplets[i].vx;
				droplets[i].y = droplets[i].y + time * droplets[i].vy;
			}

			double x1 = droplets[d1].x;
			double x2 = droplets[d2].x;
			double y1 = droplets[d1].y;
			double y2 = droplets[d2].y;
			
			double a1 = pow(droplets[d1].r, 2);
			double a2 = pow(droplets[d2].r, 2);
			double area = a1 + a2;
			double w1 = a1 / area, w2 = a2 / area;
			double x = x1 * w1 + x2 * w2;
			double y = y1 * w1 + y2 * w2;
			double vx = droplets[d1].vx * w1 + droplets[d2].vx * w2;
			double vy = droplets[d1].vy * w1 + droplets[d2].vy * w2;
			droplets[d1].x = x;
			droplets[d1].y = y;
			droplets[d1].vx = vx;
			droplets[d1].vy = vy;
			droplets[d1].r = sqrt(area);
			droplets[d2] = droplets[N - 1];
			N--;
		}
		printf("%d %.6f\n", N, total);
	}
}
