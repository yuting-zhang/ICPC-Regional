#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

double epsilon = 0.000001;

double qTor(vector<int> A){
	double sum = 0.0;
	for (int i = A.size()-1; i> 0; i--){
			sum += A[i];
			sum = 1.0 /sum;
	}
	return sum + A[0];
}

vector<int> rToq(double r){
	if (fabs(r) < epsilon){
		vector <int> a;
		a.push_back(0);
		return a;
	}
		
	vector<int> a;
	while (1){
		int intPart = floor( r);
		a.push_back(intPart);
		r = r- intPart;
		if (fabs(r) < epsilon)
			break;
		r = 1.0 / r;
		if ( fabs(r - floor(r)) < epsilon) {
			a.push_back(floor(r));
			break;
		}
		if ( fabs(r  -floor(r) - 1) < epsilon)
		{
			a.push_back(floor(r) + 1);
			break;
		}
	}
	if (a.size() > 1){
		if (a[a.size()-1] == 1){
			a[a.size()-2] += 1;
			a.pop_back();
		}
	}
	return a;
}

int main(){
	
//	freopen("in.txt","r",stdin);
	int n1, n2,cat;
	cin >> n1 >> n2;
	vector <int> a1;
	vector <int> a2;
	for (int  i =0; i < n1; i++)
		{
				cin >> cat;
				a1.push_back(cat);
		}
	for (int  i =0; i < n2; i++)
		{
				cin >> cat;
				a2.push_back(cat);
		}
	double r1 = qTor(a1);
	double r2 = qTor(a2);
	double plus = r1 + r2;
	double minus = r1 - r2;
	double by = r1 * r2;
	double divide = r1 / r2;

	//cout << r1 << " " <<  r2 << " " << plus << " " << minus << " " << by << " " << divide << " "<< endl;

	vector <int> plusAns = rToq(plus);
	vector <int> minusAns = rToq(minus);
	vector <int> byAns = rToq(by);
	vector <int> divideAns = rToq(divide);


	for (int i = 0 ;i < (int)plusAns.size() - 1; i++){
		cout << plusAns[i] << " ";
	} 
	cout << plusAns[plusAns.size()-1] << endl;
	
	for (int i = 0 ;i < (int)minusAns.size() - 1; i++){
		cout << minusAns[i] << " ";
	} 
	cout << minusAns[minusAns.size()-1] << endl;

	for (int i = 0 ;i < (int)byAns.size() - 1; i++){
		cout << byAns[i] << " ";
	} 
	cout << byAns[byAns.size()-1] << endl;

	for (int i = 0 ;i < (int)divideAns.size() - 1; i++){
		cout << divideAns[i] << " ";
	} 
	cout << divideAns[divideAns.size()-1] << endl;

	
	return 0;
}
