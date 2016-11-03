#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

struct Point{
	double x,y;
	Point(double x = 0,double y = 0):x(x),y(y){}
};

typedef Point Vector;

Vector operator-(Point A,Point B){
	return Vector(A.x-B.x, A.y-B.y);
}

double Cross(Vector A, Vector B){
	return A.x* B.y - A.y * B.x;
}

double PolygonArea(vector<Point> p, int n){
	double area = 0;
	for(int i = 1; i < n; i++){
		area += Cross(p[i]-p[0],p[i+1]-p[0]);
	}
	return area /2;
}

int main(){
	freopen("in.txt","r",stdin);
	int N,D,L;
	cin >> N >> D >> L;
	vector<Point> points;
	for (int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		Point p(x,y);
		points.push_back(p);
	}
	//readin
	L *= 1000;
	double area = abs(PolygonArea(points,N));
	cout << fixed << setprecision(2) << L / area << endl;
	return 0;
}
