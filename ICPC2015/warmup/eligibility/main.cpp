#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin >> n;
	while (n--){
		string name, enterdates, birth, course;
		cin >> name >> enterdates >> birth >> course;
		bool e = false;
		//readin
		if (stoi(enterdates.substr(0,4)) > 2010)
			e = true;
		if (stoi(birth.substr(0,4)) > 1991)
			e = true;
		if (e){
			cout << name;
			cout << "eligible" << endl;
		}
		else if ( course >= 41	
		){//inelible
			cout << name;
			cout << "ineligible" << endl;
		}
		else{
			cout << name;
			cout << "coach petitions" << endl;
		}
			
	}
	return 0;
}
