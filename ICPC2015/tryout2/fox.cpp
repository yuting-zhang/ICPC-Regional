#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	while (N--){
		string line;
		getline(cin, line);
		int state = 0;
		for (int i = 0; i < line.size(); i++){
			if (line[i] >= 'A' && line[i] <= 'Z')
				line[i] = line[i] + ('a' - 'A');
			if (line[i] >= 'a' && line[i] <= 'z')
				state |= (1 << (line[i] - 'a'));
		}
		if (state == (1 << 26) - 1)
			printf("pangram\n");
		else{
			printf("missing ");
			for (int i = 0; i < 26; i++)
				if (!(state & (1 << i)))
					printf("%c", i + 'a');
			printf("\n");
		}
		
	}
	return 0;
}

