/*************************************************************************
	> File Name: solve.cpp
	> Author: yctseng
	> Created Time: Sun Jun  7 18:32:53 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	fstream file;
	file.open("./songs/gekkou/hell.txt", ios::in);
	getline(file, s);
	getline(file, s);
	vector<int> cache;
	while( getline(file, s) ){
		stringstream ss(s);
		int num;
		ss >> num;
		cache.push_back(num);
	}
	for(int i=0; i<cache.size(); i++){
		cout << cache[i] << " ";
	}
	cout << endl;
	int flag[] = {89, 74, 75, 43, 126, 69, 120, 109, 68, 109, 109, 97, 73, 110, 45, 113, 102, 64, 121, 47, 111, 119, 111, 71, 114, 125, 68, 105, 127, 124, 94, 103, 46, 107, 97, 104 };
	int flag_len = sizeof(flag)/sizeof(flag[0]);
	for(int i=0; i<cache.size(); i++){
		flag[ i % flag_len ] ^= cache[i];	
	}
	for(int i=0; i<flag_len; i++){
		cout << (char)flag[i];
	}
	return 0;
}
