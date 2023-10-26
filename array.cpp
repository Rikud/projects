#include <iostream>
using namespace std;


void linear_search(int* array, int& len_arr) {
    int key;

    cout << "������� ������� �������, ������� ���������� �����: ";
    cin >> key;

    for (int i = 0; i < len_arr; i++) {
        if (array[i] == key) {
            cout << "������ �������� ��������: " << i << endl;
        }
    }
}

//void add_element(int* array, int& len_arr) {}

bool delete_element(int* array, int& len_arr) {
    int n;

    cout << "������� ����� �������� �������, ������� ���������� �������: ";
    cin >> n;

    if (n > len_arr || n < 1)
    {
        cout << "������ ��������" << endl;
        return false;
    }

    for (int i = n - 1; i < len_arr - 1; i++)
    {
        array[i] = array[i + 1];

    }
    len_arr--;
    return true;
}


int main()
{
    setlocale(LC_ALL, "rus");

    int length;
    cout << "������� ���������� ��������� �������: ";
    cin >> length;

    int* array_ptr = new int[length];

    for (int i = 0; i < length; i++) {
        array_ptr[i] = rand() % 100;
        cout << array_ptr[i] << " ";
    }
    cout << endl;

    linear_search(array_ptr, length);

    //add_element(array_ptr, length);

    delete_element(array_ptr, length);

    for (int i = 0; i < length; i++) {
        array_ptr[i] = rand() % 100;
        cout << array_ptr[i] << " ";
    }

    delete[] array_ptr;
}