#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#define CONVERTSTRINGSIZE 12
#define NUMERO -348

using namespace std;

const char *string_to_str(string s) {
	return s.c_str();
}

const char *int_to_str(int i) {
	char *str = (char *) malloc(CONVERTSTRINGSIZE * sizeof(*str));
	// porque um int vai ter no máximo dez dígitos, mas pode haver o sinal
	// -2147483648 a 2147483647
	snprintf(str, CONVERTSTRINGSIZE, "%d", i);
	return str;
}

int main(void) {
	string s("Batata");
	cout << "Converti " << s << " para '";
	printf("%s", string_to_str(s));
	cout << "'" << endl;	
	cout << "Converti " << NUMERO << " para '";
	printf("%s",int_to_str((int)NUMERO));
	cout << "'" << endl;	

	return 0;
}
