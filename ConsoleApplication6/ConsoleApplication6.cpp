#include <iostream>
#include"Directory.h"
using namespace std;
List_info Enter()
{
	
	cout << " Enter Firm Name : ";
	string str1;
	getline(cin, str1);

	cout << " Enter Owner : ";
	string str2;
	getline(cin, str2);

	cout << " Enter Mobile : ";
	string str3;
	getline(cin, str3);

	cout << " Enter Adress : ";
	string str4;
	getline(cin, str4);

	cout << " Enter career : ";
	string str5;
	getline(cin, str5);

	List_info tmp(str1, str2, str3, str4,str5);
	return tmp;

}
int main()
{
	setlocale(LC_ALL, "rus");
	//List_info first ("OOO Stroy Express","Ivan Ivanov","380636384862","pr. Kirova,20","Owner");
	Directory dir ;

	//dir.Add(first);
	dir.read_file();
	List_info second = Enter();
	dir.Add(second);
	dir.print();
	//dir.searchbyFirm("OOO Stroy Express");
	dir.searchbyName("Ivan Ivanov");
	dir.searchbyMobile("380674535335");
	//dir.searchbyCareer("Best specialist");

	cout << " Enter Firm Name for delete : ";
	string str1;
	getline(cin, str1);

	cout << " Enter Owner for delete : ";
	string str2;
	getline(cin, str2);
	dir.Remove(str1, str2);
	dir.print();
}

