#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isOp(char x){
		return x == '+' || x == '-';
	}
	string solveEquation(string equation) {
		int len = equation.size();
		int paraX = 0;
		int paraN = 0;
		int paraX1 = 0;
		int paraN1 = 0;
		int i;
		int eq = 0;
		while (equation[eq] != '='){
			eq++;
		}
		for (i = 0; i < eq; ){
			string tmp;
			tmp += equation[i++];
			while (i < eq && !isOp(equation[i])){
				tmp += equation[i];
				i++;
			}
			if (tmp[tmp.length() - 1] == 'x'){
				if (!isOp(tmp[0]) && tmp.length() != 1)
				{
					paraX = paraX + stoi(tmp.substr(0,tmp.length()-1));
				}else if (tmp.length() == 1){
					paraX = paraX + 1;
				}
				else if (isOp(tmp[tmp.length() - 2])){
					if (tmp[0] == '-'){
						paraX = paraX -1;
					}
					else{
						paraX = paraX + 1;
					}
				}
				else if (tmp[0] == '-'){
					paraX = paraX + (-1) * stoi(tmp.substr(1, tmp.length() - 2));
				}
				else{
					paraX = paraX + stoi(tmp.substr(1, tmp.length() - 2));
				}
			}
			else
			{
				if (tmp[0] == '-')
				{
					paraN = paraN - stoi(tmp.substr(1, tmp.length() -1));
				}
				else if(tmp[0] == '+')
				{
					paraN = paraN + stoi(tmp.substr(1, tmp.length() - 1));
				}
				else
				{
					paraN = paraN + stoi(tmp);
				}
			}

		}
		i++;
		for (; i < len; ){
			string tmp;
			tmp += equation[i++];
			while (i < len && !isOp(equation[i])) {
				tmp += equation[i];
				i++;
			}
			if (tmp[tmp.length() - 1] == 'x') {
				if (!isOp(tmp[0]) && tmp.length() != 1)
				{
					paraX1 = paraX1 + stoi(tmp.substr(0, tmp.length() - 1));
				}
				else if (tmp.length() == 1) {
					paraX1 = paraX1 + 1;
				}
				else if (isOp(tmp[tmp.length() - 2])) {
					if (tmp[0] == '-') {
						paraX1 = paraX1 - 1;
					}
					else {
						paraX1 = paraX1 + 1;
					}
				}
				else if (tmp[0] == '-') {
					paraX1 = paraX1 + (-1) * stoi(tmp.substr(1, tmp.length() - 2));
				}
				else {
					paraX1 = paraX1 + stoi(tmp.substr(1, tmp.length() - 2));
				}
			}
			else
			{
				if (tmp[0] == '-')
				{
					paraN1 = paraN1 - stoi(tmp.substr(1, tmp.length() - 1));
				}
				else if (tmp[0] == '+')
				{
					paraN1 = paraN1 + stoi(tmp.substr(1, tmp.length() - 1));
				}
				else
				{
					paraN1 = paraN1 + stoi(tmp);
				}
			}
		}
		int X = paraX - paraX1;
		int N = paraN1 - paraN;
		if (X == 0 && N == 0)
			return "Infinite solutions";
		else if (X == 0 && N != 0)
			return "No solution";
		else
			return "x=" +to_string(N / X);

	}
	
};
int main123123111111()
{
	string s = "2-x+x+3x=2x-x+x+3";
	Solution s1;
	string res = s1.solveEquation(s);
	cout << res << endl;
	return 0;
}

