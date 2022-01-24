#include <iostream>
#include <cmath>
using namespace std;

int eval_capicua(int num);
int eval_i_capicua(int num);
int eval_d_capicua(int num);
int eval_cant_dig(int num);
int first_dig(int num);



int main() {
	int num;
	int es_capicua, es_i_capicua, es_d_capicua;
	cout << "Ingrese el numero a evaluar: ";
	cin >> num;

	es_capicua   = eval_capicua(num);
	es_i_capicua = eval_i_capicua(num);
	es_d_capicua = eval_d_capicua(num);

	if (es_capicua || es_i_capicua || es_d_capicua) {
		cout << "El numero es Distinguido porque es:" << endl;
		if (es_capicua)   cout << "Capicua"   << endl;
		if (es_i_capicua) cout << "i-Capicua" << endl;
		if (es_d_capicua) cout << "d-Capicua" << endl;
	}
	else {
		cout << "No es un numero capicua.";
	}
}




int eval_capicua(int num) {
	int extract_dig, reverse_num = 0, temp = num;
	while (temp > 0) {
		extract_dig = temp % 10;
		reverse_num = reverse_num * 10 + extract_dig;
		temp = temp / 10;
	}
	if (reverse_num == num) return 1;
	else return 0;
}

int eval_i_capicua(int num) {
	int temp,temp_es_i_capicua;
	temp = num - (first_dig(num)*pow(10,eval_cant_dig(num)-1));
	temp_es_i_capicua = eval_capicua(temp);
	if (temp_es_i_capicua) return 1;
	else return 0;
}

int eval_d_capicua(int num) {
	int last_dig = num % 10;
	int temp = (num - last_dig) / 10; // Ex: 73379 -> 7337
	int temp_es_d_capicua = eval_capicua(temp);
	if (temp_es_d_capicua) return 1;
	else return 0;

}
int eval_cant_dig(int num) {
	int cant_dig=0;
	while (1) {
		num = num / 10;
		cant_dig++;
		if (num == 0) {
			break;
		}
	}
	return cant_dig;
}

int first_dig(int num) {
	int first_dig;
	while (num>=10) {
		num /= 10;  // <> num = num / 10;
	}
	return first_dig = num;
}
