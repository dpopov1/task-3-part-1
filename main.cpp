#include <iostream>
#include"Header.h"

using std::cout;
using std::endl;

int main()
{
	std::string filename = "data.txt";
	int comparison = 5 ; 
	/*Md a = Md::create(filename);*/
	if (geterror(filename))
	{
		const Md a(filename);
		a.print();
		cout << "midle: "<<a.midle() << endl << "max: "<<a.getMax() << endl << "min: "<<a.getMin() << endl<<"midsq: "<<a.midsq()<<endl<<a.countlarger(comparison)<<endl;
	}
	system("pause");
}//