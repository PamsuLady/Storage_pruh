#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Product {
private:
	string name, id, qty, fullPrice;

public:
	void setName(string a) { name = a; }
	void setId(string b) { id = b; }
	void setQty(string c) { qty = c; }
	void setFullPrice(string d) { fullPrice = d; }

	string getName() { return name; }
	string getId() { return id; }
	string getQty() { return qty; }
	string getFullPrice() { return fullPrice; }
};

void addProduct(int counter);
void deleteProduct(int counter);
void editProduct(int counter);
void viewAllProducts(int counter);
void quit();

int counter = 0;

void increment(int a) {
	a++;
	counter = a;
}

void decrement(int a) {
	a--;
	counter = a;
}

Product products[50];

int main() {
	string choice;
	system("CLS");

	cout << "\n\t[1]ADD PRODUCT\n";
	cout << "\n\t[2]DELETE PRODUCT\n";
	cout << "\n\t[3]EDIT PRODUCT\n";
	cout << "\n\t[4]VIEW ALL PRODUCT\n";
	cout << "\n\t[5]QUIT\n\n";

	cout << "\n\tENTER CHOICE: ";
	cin >> choice;
	system("CLS");

	if (choice == "1") {
		addProduct(counter);
	}
	else if (choice == "2") {
		deleteProduct(counter);
	}
	else if (choice == "3") {
		editProduct(counter);
	}
	else if (choice == "4") {
		viewAllProducts(counter);
	}
	else if (choice == "5") {
		quit();
	}
	else {
		main();
	}
	_getch();
	system("pause>0");
	return 0;
}

//addProduct function
void addProduct(int counter) {
	string name, id, qty, fullPrice;
	cout << "\n\tADD PRODUCT\n";
	if (counter < 50) {
		cout << "\n\tEnter Name: ";
		cin >> name;
		cout << "\n\tEnter Id: ";
		cin >> id;
		cout << "\n\tEnter Qty: ";
		cin >> qty;
		cout << "\n\tEnter sale price: ";
		cin >> fullPrice;

		products[counter].setName(name);
		products[counter].setId(id);
		products[counter].setQty(qty);
		products[counter].setFullPrice(fullPrice);

		increment(counter);
		cout << "\n\tPRODUCT ADDED SUCCESSFULLY!\n\tPress any key to continue . . .";
		_getch();
		main();
	}
	else {
		cout << "\n\tYOU HAVE REACHED THE MAXIMUM NUMBER OF PRODUCT TO BE ADDED!\n\tPress any key to continue . . .";
		_getch();
		main();
	}
}

//deleteProduct function
void deleteProduct(int counter) {
	string name;
	int choice;
	cout << "\n\tDELETE PRODUCT \n\n";
	if (counter == 0) {
		cout << "\n\tTHERE IS NO PRODUCT TO DELETE!\n\tPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "\n\tEnter Name: ";
	cin >> name;

	for (int i = 0; i < counter; i++) {
		if (products[i].getName() == name) {
			cout << "\n\tPRODUCT FOUND\n\n";
			cout << "\n\tDo you want to delete?\n\t[1]Yes\n\t[2]No\n\tEnter Choice: ";
			cin >> choice;
			if (choice == 1) {
				products[i].getName();
				products[i].getId();
				products[i].getQty();
				products[i].getFullPrice();
				for (int a = i; a < counter; a++) {
					products[a] = products[a + 1];
				}
				products[49].setName(""); 
				products[49].setId("");
				products[49].setQty("");
				products[49].setFullPrice("");

				decrement(counter);
				cout << "\n\tPRODUCT SUCCESSFULLY DELETED!\n\tPress any key to continue . . .";
				_getch();
				main();
			}
			else {
				main();
			}
		}
	}
	cout << "\n\tPRODUCT NOT FOUND!\n\tPress any key to continue . . .";
	_getch();
	main();

}
void editProduct(int counter) {
	system("CLS");
	string editName, choice;
	string name, id, qty, fullPrice;
	cout << "\n\tEDIT PRODUCT\n\n";
	if (counter == 0) {
		cout << "\n\tTHERE IS NO PRODUCT TO EDIT!\n\tPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "\n\tEnter Name: ";
	cin >> editName;
	for (int i = 0; i < counter; i++) {
		if (products[i].getName() == editName) {
			cout << "\tPRODUCT FOUND!\n" << endl;
			cout << "\tNAME\t\t" << products[i].getName() << endl;
			cout << "\tID\t\t" << products[i].getId() << endl;
			cout << "\tQTY\t\t" << products[i].getQty() << endl;
			cout << "\tFULL PRICE\t" << products[i].getFullPrice() << endl;

			cout << "\n\tDo you want to edit?\n\t[1]Yes\n\t[2]No\n\tEnter choice: ";
			cin >> choice;
			if (choice == "1") {
				cout << "\n\tEnter NAME: ";
				cin >> name;
				cout << "\n\tEnter ID: ";
				cin >> id;
				cout << "\n\tEnter QTY: ";
				cin >> qty;
				cout << "\n\tEnter SALE PRICE: ";
				cin >> fullPrice;

				products[i].setName(name);
				products[i].setId(id);
				products[i].setQty(qty);
				products[i].setFullPrice(fullPrice);

				cout << "\n\tPRODUCT EDITED SUCCESSFULLY!\n\tPress any key to continue . . .";
				_getch();
				main();
			}
			else {
				main();
			}
		}
	}
	cout << "\n\tPRODUCT NOT FOUND!\n\tPress any key to continue . . .";
	_getch();
	main();
}

void viewAllProducts(int counter) {
	cout << "\tVIEW ALL PRODUCTS DETAILS\n\n";
	for (int i = 0; i < counter; i++) {
		cout << "\tNAME\t\t " << products[i].getName() << endl;
		cout << "\tID\t\t " << products[i].getId() << endl;
		cout << "\tQTY\t\t " << products[i].getQty() << endl;
		cout << "\tFULL PRICE\t " << products[i].getFullPrice() << endl << endl;
	}
	cout << "\n\tPress any key to continue . . .";
	_getch();
	main();
}

void quit() {
	_exit(1);
}

