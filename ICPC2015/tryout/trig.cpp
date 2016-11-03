#include <cmath>
#include <iostream>

using namespace std;

bool isTrig(double a, double b, double c){
	if (a + b > c && b + c > a && a + c > b)
		return true;
	return false;
}

int main(){
	double a, b, c;
	double pi = acos(-1);
	cin >> a >> b >> c;
	double d = 0.00001;
	while (d <= 200){
		if (isTrig(a, b, d) && isTrig(a, c, d) && isTrig(b, c, d)){
			double alpha = acos((a*a+b*b-d*d)/(2*a*b)),
						beta = acos((a*a+c*c-d*d)/(2*a*c)), 
				   		gamma = acos((b*b+c*c-d*d)/(2*b*c));
			if (abs(alpha + beta + gamma - 2 * pi) < 0.001){
				printf("%.3f\n", 0.5 * d * d * sin(pi / 3));
				return 0;
			}
		}
		d += 0.00001;
	}
	printf("-1.000\n");
}
