
#include <iostream>
using namespace std;

class Array {
private:
	int size;
	int length;
	int* items;
public:
	Array(int arrsize) {
		size = arrsize;
		length = 0;
		items = new int[arrsize];
	}
	void Fill() {

		int numberofitems;
		cout << "How many items you want to fill ? " << endl;
		cin >> numberofitems;
		if (numberofitems > 100) {
			cout << "Invalid" << endl;
		}
		else {
			for (int i = 0; i < numberofitems; i++) {
				cout << "enter the item number " << i << endl;
				cin >> items[i];
				length++;
			}

		}
	}
	void Display() {
		cout << "Display array content." << endl;
		for (int i = 0; i < length; i++) {
			cout << items[i] << "	";
		}
		cout << endl;

	}
	int GetSize() {
		return size;
	}
	int GetLength() {
		return length;
	}
	int Search(int key) {
		int index = -1;
		for (int i = 0; i < length; i++) {
			if (items[i] == key){
				index = i;
			break;
			}
		}
		return index;
	}
	void Append(int newitem) {
		if (length < size) {
			items[length] = newitem;
			length++;

		}
		else {
			cout << "Array is full.";

		}

	}
    void Insert (int index,int newitem){
    if (index >=0 && index<size ){
        for (int i=length;i>index;i--){
            items[i]=items [i-1];
        }
        items[index]=newitem;
        length++;
    }
    else {
        cout <<"Error - index out of range"<<endl;
    }
    }
    void Delete (int index){
    if (index >=0 && index < size){
        for (int i=index ; i<length-1;i++){
            items[i]=items[i+1];
            length--;
            }
        }
        else {
            cout << "Error- index out of range" << endl;
            }
    }
    void Enlarge (int newsize){
    if (newsize > size){
            size= newsize;
    int *old=items;
    items = new int [newsize];

        for (int i=0; i<length;i++){
                items[i]= old[i];

        }
        delete[]old;
    }
    else {
        cout<<"new size should be larger than the original size."<<endl;

    }

    }
    void Merge (Array other){
    int newsize = size+ other.GetSize();
    size = newsize;
    int *old = items;
    items = new int [newsize];
    int i;
    for (i=0;i<length;i++){
        items[i]=old[i];

    }
    delete[]old;
    int j=i;
    for (int i=0;i<other.GetLength();i++){
        items[j++]=other.items[i];
        length++;
    }
    }
};




int main()
{
	cout << "Hello" << endl;


        int arraysize;
        cout << "Enter the size of array" << endl;
        cin >> arraysize;
        Array myarray(arraysize);
        myarray.Fill();


        cout << "Array size = " << myarray.GetSize() << "	" << "array length = " << myarray.GetLength()<<endl;
        myarray.Display();


        cout << "enter the value to search" << endl;
        int key;
        cin >> key;
        int index = myarray.Search(key);
        if (index == -1)
            cout << "Item Not Found" << endl;
        else {
            cout << "Item Found" << endl;
	}

        int newitem;
        cout << "enter new item to add in array" << endl;
        cin >> newitem;
        myarray.Append(newitem);
        myarray.Display();
        cout << "enter index and items."<<endl;
        cin >> index >> newitem;
        myarray.Insert(index,newitem);
        myarray.Display();
     	cout << "Array size = " << myarray.GetSize() << "	" << "array length = " << myarray.GetLength()<<endl;
        cout << "enter index you want to delete"<<endl;
        cin >> index;
        myarray.Delete(index);
        myarray.Display();
     	cout << "Array size = " << myarray.GetSize() << "	" << "array length = " << myarray.GetLength()<<endl;

     	int newsize;
     	cout << "enter new size."<<endl;

        cin >> newsize;
        myarray.Enlarge(newsize);
        cout << "Array size = " << myarray.GetSize() << "	" << "array length = " << myarray.GetLength()<<endl;
        myarray.Display();

        Array other(3);
        other.Fill();
        myarray.Merge(other);
        cout << "Array size = " << myarray.GetSize() << "	" << "array length = " << myarray.GetLength()<<endl;
        myarray.Display();


}


