#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool judgeCircle(string moves) {
		int len = moves.length();
		if (len == 0) return true;
		int RLcount = 0;
		int UDcount = 0;
		for (int i = 0; i < len; ++i)
		{
			if (moves[i] == 'R') {
				++RLcount;
			}else if(moves[i] == 'L'){
				--RLcount;
			}else if(moves[i] == 'U'){
				++UDcount;
			}else if(moves[i] == 'D'){
				--UDcount;
			}
		}
		return RLcount == 0 && UDcount == 0;
	}
};