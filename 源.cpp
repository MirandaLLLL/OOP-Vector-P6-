#include"template.h"
#include<vector>

int main() {
	cout << "Please Create the undesigned Vector" << endl;
	Vector<string> V;
	int i;
	string value;
	cin >> value;
	for (i = 0; value != "."; i++) {
		V.push_back(value);      //push the value into V; test the "push_back(x)" function;
		cin >> value;
	}
	cout << "the size of V is " << V.size() << endl;
	cout << endl;

	Vector<string> V1(V);      //test the function of "copy ctor ";
	cout << "After V1 copying V, ";
	cout << "the size of V1 is " << V1.size() << endl; //test the function of "size()";
	for (i = 0; i < V1.size(); i++) {
		cout << V1.operator[](i) << " ";  //test the function of "operator[]";
	}
	cout << endl;
	V1.clear(); //test the function of "clear";
	cout << "After clear the contents of the V1 , judge whether the container is empty " << V1.empty() << endl;
	cout << "output the first element of V1" << endl;
	cout << V1.at(0) << endl; //test the function of "at()";
	cout << endl;

	V.~Vector();               //test the function of "destruct the Vector";
	V1.~Vector();               //test the function of "destruct the Vector";
	cout << "Please input the capacity of next container " << endl;
	int sum;
	cin >> sum;

	Vector<string> V2(sum);    //test the function of "construct the Vector(size)";
	cin >> value;
	for (i = 0; value != "."; i++) {
		V2.push_back(value);      //push the value into V; test the "push_back(x)" function;
		cin >> value;
	}
	cout << "The size of V2 is " << V2.size() << endl;
	cout << "Output V2 " << endl;
	for (i = 0; i < V2.size(); i++) {
		cout << V2.operator[](i) << " ";
	}

	V2.~Vector();
	system("pause");
	return 0;
}