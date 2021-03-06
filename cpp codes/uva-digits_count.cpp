#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;
string toString(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

struct Digits{
	int d[10];
	Digits(){
		memset(d, 0, sizeof d);
	}
	Digits operator + (const Digits &o){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] + o.d[i];
		return ans;
	}
	Digits operator + ( int n )	{
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] + n;
		return ans;
	}
	Digits operator - (const Digits &o){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] - o.d[i];
		return ans;
	}
	Digits operator * (int n){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] * n;
		return ans;
	}
	void print(){
		string space = "";
		for(int i = 0; i < 10; ++i){
			cout << space <<d[i];
			space = " ";
		}
		cout << endl;
	}

};

Digits c[10];

void precalculate(){ //calculates the digits of powers of 1 - powers of 10
	for(int i = 1; i < 9 ; ++i){
		c[i] = c[i-1] * 10; // each digit will be needed x 10 because it will put 10 different digits to its left
		c[i] = c[i] + pow(10,i-1); //we add to each digit how much it will have on the left

		if(i != 1)
			c[i].d[0] -= 10;
	}

}

/*
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
10 20 20 20 20 20 20 20 20 20
189 299 299 299 299 299 299 299 299 299
2880 3990 3990 3990 3990 3990 3990 3990 3990 3990
38789 49899 49899 49899 49899 49899 49899 49899 49899 49899
487880 598990 598990 598990 598990 598990 598990 598990 598990 598990
5878790 6989900 6989900 6989900 6989900 6989900 6989900 6989900 6989900 6989900
68787889 79898999 79898999 79898999 79898999 79898999 79898999 79898999 79898999 79898999

*/
Digits get(int num){
	Digits ans;
	string n = toString(num);
	for(int i = 0; i < n.size(); ++i){

		int dig = n[i] - '0';
		int cant = n.size()-i-1;//says how many digits there are to the right of the i-th digit
		// YXX..XX for each digit 1 to 'dig' you have to reuse all the c [cant]
		ans = ans + (c[cant] * dig) ;

		// each digit from 1 to (dig-1) has to be repeated XYYYY ZYYYY AYYYY
		for(int j = 1; j < dig; ++j)
			ans.d[j] += pow(10, cant );

		//the digit dig only uses the number of numbers on the right
		ans.d[dig] += (num % (int)pow(10,cant) )  ;
	}

	//now we will add the additional zeros generated by X0..01 X0 ... 02
	for(int i = 0; i < n.size(); ++i){
		int dig = n[i] - '0';
		int cant = n.size() - i - 1;
		int adicional = 0;
		for(int j = 1; j < cant; ++j)
			adicional += pow(10, j);
		if(i == 0)//we are in the first digit
			ans.d[0] += ( (dig - 1) * adicional);//the previous numbers do not have zero to the right (000001 not valid)
		else{
			ans.d[0] += (dig * adicional);
			if( dig ) // if the digit is not zero then before dig there were zeros in that position
				ans.d[0] += pow(10,cant);
		}
	}
	if(num < 10)
		ans.d[0]++;
	return ans;
}

int main(){


	precalculate();
	int ini,fin;
	while(cin >> ini >> fin && !(ini==0 && fin==0)){
		Digits a,b;
		a = get(ini);
		b = get(fin+1);
		(b-a).print();
	}
	return 0;
}
