#pragma once
#include <vector>
class Md
{
	std::vector<int> arr;
	int n;
	/*explicit Md(vector<int> arr, int n);*/

	public:
		int getMax() const;
		int getMin() const;
		int size() const;
		~Md() {arr.clear();};
		Md(const std::string filename);
		double midle() const;
		double midsq() const;
		void print() const;
		int countlarger(const int) const;
		/*static Md * create(std::string filename);*/
};//

bool geterror(const std::string filename);