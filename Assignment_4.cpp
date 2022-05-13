#include <iostream>
using namespace std;
class Clientinfo
{
	int phoneNum;
	string name;
	friend class Hash;

public:
	Clientinfo()
	{
		phoneNum = 0;
		name = "----";
	}
	Clientinfo(int num, string name1)
	{
		phoneNum = num;
		name = name1;
	}
};
class Hash
{
	Clientinfo obj[10];

public:
	int hashFunc(int x)
	{
		return x % 10;
	}
	void display()
	{
		cout << "\n\nIndex"
			 << " PhoneNumber"
			 << "	Name\n";
		for (int i = 0; i < 10; i++)
		{
			cout << i << "       " << obj[i].phoneNum << "		" << obj[i].name
				 << endl;
		}
	}
	void insert(int num, string name)
	{
		int x = hashFunc(num);

		if (obj[x].phoneNum == 0)
		{
			obj[x].name = name;
			obj[x].phoneNum = num;
		}
		else 
		{
			while (obj[x].phoneNum != 0)
			{
				x = (x + 1) % 10;
			}
			obj[x].phoneNum = num;
			obj[x].name = name;
		}
	}
	void insertWR(int num, string name)
	{
		int x = hashFunc(num);
		if (obj[x].phoneNum == 0)
		{
			obj[x].name = name;
			obj[x].phoneNum = num;
		}
		else if (obj[x].phoneNum != 0)
		{

			if (obj[x].phoneNum % 10 == x)
			{
				while (obj[x].phoneNum != 0)
				{
					x = (x + 1) % 10;
				}
				obj[x].name = name;
				obj[x].phoneNum = num;
			}
			else
			{
				int tempnum = obj[x].phoneNum;
				string tempname = obj[x].name;
				obj[x].name = name;
				obj[x].phoneNum = num;
				while (obj[x].phoneNum != 0)
				{
					x = (x + 1) % 10;
				}
				obj[x].name = tempname;
				obj[x].phoneNum = tempnum;
			}
		}
	}
	int search(int num)
	{
		int x = hashFunc(num);
		int counter = 1;
		while (obj[x].phoneNum != num)
		{
			x = (x + 1) % 10;
			counter++;
			if (counter > 10)
			{
				return -1;
			}
		}
		cout << "Number of comparisons required for searching are " << counter << endl;
		return x;
	}
	void deletenum(int num)
	{
		int x = hashFunc(num);
		int counter = 1;
		while (obj[x].phoneNum != num)
		{
			x = (x + 1) % 10;
			counter++;
			if (counter > 10)
			{
				cout << "\nNumber does not exist in directory\n";
				return;
			}
		}
		obj[x].phoneNum = 0;
		obj[x].name = "---";
	}

};

int main()
{
	Hash h, hr;
	int pn, num, temp;
	string name;
	int choice, inchoice;
	while (true)
	{

		cout << "\n\nMenu\n";
		cout << "1.Linear probing without replacement\n";
		cout << "2.Linear probing with replacement\n";
		cout << "0.Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			for (int i = 0; i < 10; i++)
			{
				cout << "Enter phone number and name:";
				cin >> pn >> name;
				h.insert(pn, name);
			}
			h.display();
			while (inchoice != 3)
			{
				cout << "\n\n1.Search\n";
				cout << "2.Delete\n";
				cout << "3.Go back\n";
				cout << "Choose an option";
				cin >> inchoice;

				switch (inchoice)
				{
				case 1:
					cout << "Enter the phone number to be searched\n";
					cin >> num;
					temp = h.search(num);
					if (temp != -1)
					{
						cout << "Number is found at bucket " << temp << endl;
					}
					else
					{
						cout << "Number does not exist\n";
					}
					break;
				case 2:
					cout << "Enter the number to be deleted";
					cin >> num;
					h.deletenum(num);
					h.display();
					break;
				case 3:
					break;
				default:
					cout << "\n\nChoose valid options only!\n";
					break;
				}
			}

			break;

		case 2:
			for (int i = 0; i < 10; i++)
			{
				cout << "Enter phone number and name:";
				cin >> pn >> name;
				hr.insertWR(pn, name);
			}
			hr.display();
			inchoice=-1;
			while (inchoice != 3)
			{
				cout << "\n\n1.Search\n";
				cout << "2.Delete\n";
				cout << "3.Go back\n";
				cout << "Choose an option";
				cin >> inchoice;

				switch (inchoice)
				{
				case 1:
					cout << "Enter the phone number to be searched\n";
					cin >> num;
					temp = hr.search(num);
					if (temp != -1)
					{
						cout << "Number is found at bucket " << temp << endl;
					}
					else 
					{
						cout << "Number does not exist\n";
					}
					break;
				case 2:
					cout << "Enter the number to be deleted";
					cin >> num;
					hr.deletenum(num);
					hr.display();
					break;
				case 3:
					break;
				default:
					cout << "\n\nChoose valid options only!\n";
					break;
				}
			}

			break;
		default:
			cout << "Choose valid options only!\n";
			break;
		}
	}

	return 0;
}