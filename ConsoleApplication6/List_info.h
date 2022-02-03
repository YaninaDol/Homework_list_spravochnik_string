#include <iostream>
using namespace std;

class List_info
{
private:
	string firma;
	string own_name;
	string mobile;
	string adress;
	string function;
	
public:
	List_info()
	{
		this->firma = ' ';
		this->own_name = ' ';
		this->mobile = ' ';
		this->adress = ' ';
		this->function = ' ';
	}
	List_info(string Firm, string Name,  string Mob,string Adress, string Func)
	{
		this->firma = Firm;
		this->own_name = Name;
		this->mobile = Mob;
		this->adress = Adress;
		this->function = Func;
	}
	string getName()
	{
		return this->own_name;
	}
	string getFirma()
	{
		return this->firma;
	}

	string getMob()
	{
		return this->mobile;
	}
	string getAdress()
	{
		return this->adress;
	}
	string getFunction()
	{
		return this->function;
	}
	void setFirm(string str1)
	{
		this->firma = str1;
	}
	void setName(string str2)
	{
		this->own_name = str2;
	}

	void setMobile(string Mob)
	{
		this->mobile = Mob;
	}
	void setAdress(string Adress)
	{
		this->adress = Adress;
	}
	void setFunc(string str3)
	{
		this->function = str3;
	}
	friend std::ostream& operator<<(std::ostream& out, const List_info us)
	{
		out  << us.firma << "\t" << us.own_name << "\t" << us.mobile << "\t" << us.adress << "\t" << us.function<<"\n";
		return out;
	}
};

