#include <iostream>
#include <cstdio>
#include <list>
#include <utility>
#include <string>
#include <set>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	list<pair<long long, char>> events;
	for (int i = 0; i < n; i++){
		char op;
		scanf(" %c ", &op);
		if (op == '+'){
			long long index, number;
			scanf("%lld %lld", &index, &number);
			char e_type;
			cin >> e_type;
			index--;
			auto it = events.begin();
			long long curr_index = 0;
			while (it != events.end() && curr_index < index){
				auto it2 = it;
				it2++;
				if (it2 != events.end() && (*it).second == (*it2).second){
					(*it2).first += (*it).first;
					it = events.erase(it);
				}
				if ((*it).first + curr_index > index){
					pair<long long, char> e = *it;
					it = events.erase(it);
					it = events.insert(it, make_pair(index - curr_index, e.second));
					it++;
					it = events.insert(it, make_pair(e.first - (index - curr_index), e.second));
					curr_index = index;
				}
				else{
					curr_index += (*it).first;
					it++;
				}
			}
			it = events.insert(it, {number, e_type});
		}
		else if (op == '-'){
			long long index, number;
			scanf("%lld %lld", &index, &number);
			index--;
			auto it = events.begin();
			long long curr_index = 0;
			while (it != events.end() && curr_index < index){
				auto it2 = it;
				it2++;
				if (it2 != events.end() && (*it).second == (*it2).second){
					(*it2).first += (*it).first;
					it = events.erase(it);
				}
				if ((*it).first + curr_index > index){
					pair<long long, char> e = *it;
					it = events.erase(it);
					it = events.insert(it, make_pair(index - curr_index, e.second));
					it++;
					it = events.insert(it, make_pair(e.first - (index - curr_index), e.second));
					curr_index = index;
				}
				else{
					curr_index += (*it).first;
					it++;
				}
			}
			long long curr_delete = 0;
			while (it != events.end() && curr_delete < number){
				auto it2 = it;
				it2++;
				if (it2 != events.end() && (*it).second == (*it2).second){
					(*it2).first += (*it).first;
					it = events.erase(it);
				}
				if ((*it).first + curr_delete <= number){
					curr_delete = (*it).first + curr_delete;
					it = events.erase(it);
				}
				else{
					pair<long long, char> e = *it;
					it = events.erase(it);
					it = events.insert(it, make_pair(e.first - (number - curr_delete), e.second));
					curr_delete = number;
				}
			}
		}
		else{
			long long index, number;
			scanf("%lld %lld", &index, &number);
			index--;
			number = number - index;
			auto it = events.begin();
			long long curr_index = 0;
			set<char> e_set;
			long long curr_count = 0;
			while (it != events.end() && curr_index < index){
								
				auto it2 = it;
				it2++;
				if (it2 != events.end() && (*it).second == (*it2).second){
					(*it2).first += (*it).first;
					it = events.erase(it);
				}
				
				if ((*it).first + curr_index > index){
					e_set.insert((*it).second);

					curr_count = ((*it).first - (index - curr_index));
					curr_index = index;
					it++;
				}
				else{
					curr_index += (*it).first;
					it++;
				}
			}
			while (curr_count < number){
				e_set.insert((*it).second);
				curr_count += (*it).first;
				it++;
			}
			cout << e_set.size() << "\n";
		}
	}
}
