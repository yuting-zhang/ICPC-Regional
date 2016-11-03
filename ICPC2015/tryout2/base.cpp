#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

long long  MAXINT = (static_cast<long long>(1) << 32) - 1;

int getDigit(char ch){
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return (ch - 'a') + 10;
}

int convert(string op, int base){
	if (base == 1){
		for (int i = 0; i < op.size(); i++)
			if (op[i] != '1')
				return -1;
		return op.size();
	}

	long long result = 0;
	for (int i = 0; i < op.size(); i++){
		int digit = getDigit(op[i]);
		if (digit >= base)
			return -1;
		result = result * base + digit;
		if (result > MAXINT)
			return -1;
	}
	return static_cast<int>(result);
}

long long compute(int op1, int op2, char opcode){
	long long result;
	if (opcode == '+')
		result = op1 + op2;
	if (opcode == '-')
		result = op1 - op2;
	if (opcode == '*')
		result = op1 * op2;
	if (opcode == '/'){
		result = op1 / op2;
		if (result * op2 != op1)
			return -1;
	}

	if (result > MAXINT)
		return -1;
	return result;
}

void print_base(int base){
	if (base >= 1 && base <= 9)
		printf("%d", base);
	else if (base >= 10 && base <= 35)
		printf("%c", static_cast<char>(base - 10 + 'a'));
	else
		printf("0");
}

int main(){
	int N;
	scanf("%d\n", &N);
	while (N--){
		bool valid = false;
		string op1, op2, result;
		char opcode, temp;
		cin >> op1 >> opcode >> op2 >> temp >> result;
		for (int B = 1; B <= 36; B++){
			int d_op1 = convert(op1, B);
			int d_op2 = convert(op2, B);
			int d_result = convert(result, B);
			if (d_op1 != -1 && d_op2 != -1 && d_result != -1){
				if (d_result == compute(d_op1, d_op2, opcode)){
					print_base(B);
					valid = true;
				}
			}
		}
		if (!valid)
			printf("invalid\n");
		else
			printf("\n");
	}
	return 0;
}
