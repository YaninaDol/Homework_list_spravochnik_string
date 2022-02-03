#include "List_info.h"
#include <fstream>
#include <string>

class Directory
{
private:
	List_info* mas;
	int size;
public:
	Directory()
	{
		this->size = 0;
		this->mas = new List_info[this->size];
	}
	List_info& operator[](const int index)
	{
		if (index < size)
		{
			return this->mas[index];
		}
		else return mas[1];
	}
	void Add(List_info& tmp)
	{

		List_info* new_id = new List_info[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			new_id[i] = this->mas[i];
		}
		new_id[size] = tmp;
		delete[] this->mas;
		this->mas = new_id;
		this->size++;
	}
	void read_file()
	{
		string path = "Data1.txt";
		ifstream fin;
		fin.open(path);

		if (!fin.is_open())
		{
			cout << " Error!";
		}
		else
		{
			string str;
			while (getline(fin, str))
			{
				size_t pos = 0;
				pos = str.find('\t');
				string Firm = str.substr(0, pos);
				str.erase(0, pos + 1);
				pos = str.find('\t');
				string Name = str.substr(0, pos);
				str.erase(0, pos + 1);
				pos = str.find('\t');
				string Mob = str.substr(0, pos);
				str.erase(0, pos + 1);
				pos = str.find('\t');
				string Adress = str.substr(0, pos);
				str.erase(0, pos + 1);
				pos = str.find('\n');
				string Func = str.substr(0, pos);

				List_info exampl(Firm, Name, Mob, Adress, Func);
				this->Add(exampl);

			}
			cout << " Чтение произведено! \n";
		}
		fin.close();

	}

	void Delete(int pos)
	{
		List_info* new_id = new List_info[this->size - 1];
		for (int j = 0; j < pos && j < size; j++)
		{
			new_id[j] = mas[j];
		}
		for (int j = pos + 1; j < size; j++)
		{
			new_id[j - 1] = mas[j];
		}
		size--;
		delete[](mas);
		mas = new_id;
		cout << " Абонент удален! \n";
	}

	void Remove(string Firm, string Name)
	{
		int f = 0;
		int pos = -1;
		for (int i = 0; i < size; i++)
		{
			if ((this->mas[i].getFirma() == Firm) && (this->mas[i].getName() == Name))
			{
				pos = i;
				f = 1;
			}


		}
		if (f == 1)
		{
			this->Delete(pos);
		}
		else
		{
			cout << "Нет такого абонента! \n";

		}

	}

	void searchbyFirm(string Firma)
	{
		int f = 0;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getFirma() == Firma)
			{
				f = 1;
				this->Show(mas[i]);
			}
		}
		if (f == 0)
		{
			cout << "Not found";
		}
	}

	void searchbyName(string Name)
	{
		int f = 0;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getName() == Name)
			{
				f = 1;
				this->Show(mas[i]);
			}
		}
		if (f == 0)
		{
			cout << "Not found";
		}
	}

	void searchbyMobile(string Mobile)
	{
		int f = 0;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getMob() == Mobile)
			{
				f = 1;
				this->Show(mas[i]);
			}
		}
		if (f == 0)
		{
			cout << "Not found";
		}
	}
	void searchbyCareer(string Career)
	{
		int f = 0;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getFunction() == Career)
			{
				f = 1;
				this->Show(mas[i]);
			}
		}
		if (f == 0)
		{
			cout << "Not found";
		}
	}
	

	void Show(List_info tmp)
	{
		cout << tmp;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << this->mas[i];
		}
	}
	~Directory()
	{
		string path = "Data1.txt";
		ofstream fout;
		fout.open(path, ofstream::out);
		if (!fout.is_open())
		{
			cout << " Error!";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{

				fout << this->mas[i];
			}
			cout << " Запись произведена! \n";
		}
		fout.close();
	}

};

