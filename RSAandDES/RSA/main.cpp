#include"Encrypt.h"



int main()
{


	Encrypt e1;
	e1.Set_c();
	cout << "����:";
	e1.print_c();
	e1.Set_m();
	cout << "����:";
	e1.print_m();
	e1.Deal_c();
	cout << endl;
	return 0;
}
