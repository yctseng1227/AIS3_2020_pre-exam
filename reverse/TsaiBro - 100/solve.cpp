/*************************************************************************
	> File Name: solve.cpp
	> Author: yctseng
	> Created Time: Sun Jun  7 20:54:45 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	fstream file;
	file.open("TsaiBroSaid", ios::in);
	getline(file, s);	
	file >> s;
	s = regex_replace(s, regex("發財"), " ");
	stringstream ss(s);
	vector<int> v;
	while( getline(ss, s, ' ') ){
		if(s.length())
			v.push_back(s.length());
	}

	string table = "56789{}_WXY0yzABabcdmnopSTUVGHIJKLMNuvwxefghqrstijklOPQRCDEF1234";
	for(int i=0; i<v.size(); i+=2){
		int idx = v[i+1] + (v[i]-1) * 8 - 1;
		cout << table[idx];
		//cout << (char)((v[i]-1) * 8);
		//cout << v[i] << " " << v[i+1] << endl;
	}
	return 0;
}
