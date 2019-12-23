#include <iostream>
#include <string>

using namespace std;


int goldNum(int y){
	return ((y % 19) + 1);
}

int solCorr(int y){
	return ((y - 1600) / 100) - ((y - 1600) / 400);
}

int lunCorr(int y){
	return ((((y - 1400) / 100) * 8) / 25);
}

int corrP(int y){
	int g = goldNum(y);
	int p_uncc = ((3 - (11 * g) + solCorr(y) - lunCorr(y)) % 30);
	if ((p_uncc == 29) || (p_uncc == 28 && g > 11)) return p_uncc - 1;
	return p_uncc;
}

int domLett(int y){
	return ((8 - ((y + (y / 4) - (y / 100) + (y / 400)) % 7)) % 7);
}

int actualP(int y){
	 return ((80 + corrP(y)) % 7);
}

int x(int y){
	int uncorr_x = domLett(y) - actualP(y);
	return (((uncorr_x - 1) % 7) + 1);
}

string easterDate(int y) {
	string day = "";
	int e = corrP(y) + x(y);
	if (e < 11) {
		day = "March " + std::to_string(e + 21);
	}else{
	 day = "April " + std::to_string(e - 10);
	}
	return day;
}