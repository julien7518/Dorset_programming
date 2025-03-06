#include <iostream>
using namespace std;

#define MAX_SIZE 10

void displayArray(int array[], int length){
    for (int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    for (int i = length; i < MAX_SIZE; i++){
        cout << "." << " ";
    }
    cout << endl;
    cout << endl;
}

int insertElement(int array[], int length, int index, int element){
    if (length + 1 <= MAX_SIZE){
        if (index <= length){
            for (int i = length; i > index; i--){
                array[i] = array[i-1];
            }
            array[index] = element;
            cout << element << " added at position " << index << endl;
            return length + 1;
        }
        else{
            cout << "Can't insert an element outside the array." << endl;
        }
    }
    else {
        cout << "Not enought space in the array." << endl;
    }
    cout << endl;
    return length;
}

int deleteElement(int array[], int length, int index){
    if (index <= length){
        for (int i = index+1; i < length; i++){
            array[i-1] = array[i];
        }
        return length - 1;
    }
    else{
        cout << "Can't delete an element outside the array." << endl;
    }
    return length;
}

void searchElement(int array[], int length, int element){
    for (int i = 0; i < length; i++){
        if (array[i] == element){
            cout << element << " found at " << i << endl;
        }
    }
}

void updateElement(int array[], int length, int index, int element){
    if (index <= length){
        cout << array[index] << " replaced by " << element << " at position " << index << endl;
        array[index] = element;
    }
    else{
        cout << "Can't update an element outside the array." << endl;
    }
}

int menu(){
    int choice;
    cout << "1 : Display the array.\n";
    cout << "2 : Insert an element.\n";
    cout << "3 : Delete an element.\n";
    cout << "4 : Search an element.\n";
    cout << "5 : Upadte an index.\n";
    cout << "6 : Exit.\n";
    do{
        cout << "\nChoose an action : ";
        cin >> choice;
    }
    while (choice > 6 && choice < 1);
    cout << endl;
    return choice;
}

int askIndex(){
    int index;
    cout << "Index : ";
    cin >> index;
    return index;
}

int askElement(){
    int element;
    cout << "Element : ";
    cin >> element;
    return element;
}

int main(){
    int array[10] = { 0, 1, 2, 3, 4, 0, 0, 0, 0, 0 };
    int length = 5;
    int choice;
    cout << "Array operations. (maximum size of the array : " << MAX_SIZE << ")" << endl;
    do{
        choice = menu();
        int element;
        int index;
        switch (choice)
        {
        case 1:
            displayArray(array, length);
            break;
        case 2:
            index = askIndex();
            element = askElement();
            length = insertElement(array, length, index, element);
            break;
        case 3:
            index = askIndex();
            length = deleteElement(array, length, index);
            break;
        case 4:
            element = askElement();
            searchElement(array, length, element);
            break;
        case 5:
            index = askIndex();
            element = askElement();
            updateElement(array, length, index, element);
        }
    }
    while (choice != 6);
    cout << "End of the program.";

    return 0;
}