#include <vector>
#include <algorithm>
#include<fstream>
#include<iostream>
#include "Header.h"
#include<iterator>
#include<functional>
#include<algorithm>
#include<numeric>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::string;

int Md::size() const
{
	return n;
}

vector <int> getarr(const string filename)
{
	std::ifstream a(filename);
	vector <int> b;
		int n;
		a >> n;
		istream_iterator<int> it(a);
		istream_iterator<int> end;
		auto x = [&b](auto t)
		{ 
		b.push_back(t); 
		};
		for_each(it, end, x);
		a.close();
	sort(b.begin(), b.end());
	return b;
}

int Md::getMin() const {
	return arr[0];
}

int Md::getMax()const {
	return arr[n-1];
}

int getn(const string filename)
{
	std::ifstream a(filename);
	istream_iterator<int> it(a);
	istream_iterator<int> end;
	if (!a.is_open())
		throw 2;
	if (end == it)
		throw 3;
		a.close();
	return *it;
}

Md::Md(const string filename) :arr(getarr(filename)), n(getn(filename)) {}

void geterror0(const string filename)
{
	int n = getn(filename);
	vector<int> b = getarr(filename);
	if (n != b.size())
		throw 1;
	else
		if (n == 0)
			throw 0;
}

double Md::midsq() const
{
	int a = std::inner_product(arr.begin(), arr.end(), arr.begin(), 0);
	return 1.0*a / n - midle()*midle();
}

double Md::midle() const
{
	int m = std::accumulate(arr.begin(), arr.end(), 0);
	return 1.0*m / n;
}

void Md::print() const {
	auto x = [](auto t) {
		cout << t;
	};
	cout << "arr: ";
	for_each(arr.begin(), arr.end(), x);
	cout << endl;
}

int Md:: countlarger(const int a) const
{
	auto x = [&a](int i) {return i - a > 0; };
	int t = std::count_if(arr.begin(), arr.end(), x);
	return t;
}

bool Md::geterror(const string filename)
{
	bool error = 1;
	try {
		geterror0(filename);
	}
	catch (int a)
	{
		if (a == 1)
			std::cout << "N!=n" << std::endl;
		if (a == 0)
			std::cout << "n=0" << std::endl;
		if (a == 2)
			std::cout << "file not found" << std::endl;
		if (a == 3)
			std::cout << "file cliar" << std::endl;
		error = 0;
	}
	return error;
}
//Md::Md(vector<int> arr2, int n2) { arr = arr2; n = n2; }

//Md* Md::create(string filename) {
//	try 
//	{
//		int n = getn(filename);
//		vector<int> arr = getarr(filename);
//		if (n != arr.size())
//			throw "razmeri ni sovpadaut";
//		if (n == 0)
//			throw "n=0";
//		return new Md(arr, n);
//	}
//	catch (char* t)
//	{
//		cout << t;
//	}
////	return Md({ 1 }, 1);
//}

