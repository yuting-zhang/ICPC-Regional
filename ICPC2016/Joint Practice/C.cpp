#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M, D, L;
int lane[60000];
int main()
{
	cin>>N>>M>>D>>L;
	vector<int> cow(60000);
	for (int i=0; i<N; i++)
		cin>>cow[i];
	sort(cow.begin(), cow.begin() + N);
	int pt = 0;
	for (int i=0; i<N; i++)
	{
		if (cow[i] >= lane[pt] * D + L) {
			lane[pt]++;
			pt = (pt+1)%M;
		}
	}
	int sum = 0;
	for (int i=0; i<M; i++)
		sum += lane[i];
	cout<<sum<<endl;
	return 0;
}
