#include <iostream>
#include <string>

using namespace std;

string showNumber(int n);
string showMyNumber (int number);
unsigned long long int findMyBin(unsigned long long int n);
unsigned long long int dec2bin(unsigned long long int n);

int main(int argc, char *argv[]) 
{
	if (argc > 1){
		int number = atoi(argv[1]);
		unsigned long long int k = findMyBin(number);
		if (k == 0) cout << "Nie ma takiej liczby w zakresie <1;1000000> dla n = " << number << endl;
		else {
			cout << number << " * " << showMyNumber(k/number) << " = " << showMyNumber(k) <<  endl;
		}
	}
	else cout << "Nie podano liczby\n";
}

unsigned long long int findMyBin(unsigned long long int number) 
{
	for (int i = 1; dec2bin(i) < 1000000; i++){
		unsigned long long int div = dec2bin(i);
		if (div%number == 0) {
			 return div;
		}
	}
	return 0;
}
/*
Algorytm dziala tak: Dla kazdej kolejnej liczby od 1 szukany jest jej zapis binarny, 
ale ta wartosc wpisywana jest do inta dziesietnie, tzn.
1 -> 1
2 -> 10 (dziesiec)
3 -> 11 (jedenascie)
4 -> 100 (sto)
itd.
Następnie dla danego n sprawdzane jest, czy n dzieli każdą kolejną liczbę binarną.
Jeśli tak, jest to szukane k.
Sprawdzanie wykonywane jest do liczby binarnej o zapisie "1000000", bo większych liczb program nie wyswietla.
*/

unsigned long long int dec2bin(unsigned long long int n) 
{
	string bin = "";
	while (n > 0){
		char digit = n%2 + '0';
		n = n/2;
		bin = digit + bin;
	}
	n = bin[0] - '0';
	for (int i = 1; i < bin.length(); i++){
		n = n*10 + (bin[i] - '0');
	}
	return n;
}

string showMyNumber (int number)
{
	string result = "";
	if (number > 1000000) return "wiecej niz milion";
	else {
		if (number == 1000000) return "milion";
		else {
			if (number == 0) return "zero";
			if (number >= 1000){
				if (number >= 2000) result += showNumber(number/1000);
				if ((number/1000)%100 == 11 || (number/1000)%100 == 12 || (number/1000)%100 == 13 || (number/1000)%100 == 14) result += " tysiecy ";
				else if ((number/1000)%10 == 1) result += " tysiac ";
				else if ((number/1000)%10 < 5 && (number/1000)%10 != 0) result += " tysiace ";
				else result += " tysiecy ";
				result += showNumber(number%1000);
			}
			else result += showNumber(number);
		}
	}
	return result;
}

string showNumber(int n)
{
	string num[10] = {"", "jeden", "dwa", "trzy","cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	string result = "";
	
	switch ((n/100)%10){
		case 0: break;
		case 1: result += "sto "; break;
		case 2: result += "dwiescie "; break;
		case 3: case 4: result += num [(n/100)%10] + "sta "; break;
		default:  result += num [(n/100)%10] + "set ";
	}
	if (n%100>=10 && n%100<20){
		switch (n%10){
			case 0: result += "dziesiec"; break;
			case 1: case 6: result += num[n%10] + "\bnascie"; break;
			case 5: case 9: result += num[n%10] + "\btnascie"; break;
			default:  result += num[n%10] + "nascie";
		}
	}
	else {
		result += num[(n%100)/10];
		switch ((n%100)/10){
			case 0: break;
			case 2: result += "dziescia "; break;
			case 3: result += "dziesci "; break;
			case 4: result += "\bdziesci "; break;
			default: result += "dziesiat "; break;
		}
		result += num[n%10];
	}
	return result;
}