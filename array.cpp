#include <iostream>
using namespace std;


void linear_search(int* array, int& len_arr) {
    /*
        TODO: хорошей практикой является проверка передаваемых значений в функцию
        по ошибки может попасться array = NULL или len_arr = 0. В таком случае
        надо выдать ошибку и завершить работу функции
    */

    /*
        TODO: очень полезная практика - задавать значение по-умлчанию. В данном случае 0
        сталкивался в своей практике, когда забывали инициализировать дефолтным значением
        переменную, компилятор выдавал под нее область памяти с мусором и в итоге получали
        проблемы
    */

    int key;

/*
    TODO
    выглядит так, что чтение пользовательского ввода стоит вынести в отдельную операцию
    с обработкой ошибок и сключений, например случай, когда пользователь
    вводит не число, а просто строку

    функцию чтения можно назвать, например, read_int_from_stdin(const char* text)
*/
    cout << "Укажите элемент массива, который необходимо найти: ";
    cin >> key;

    for (int i = 0; i < len_arr; i++) {
        if (array[i] == key) {
            cout << "Индекс искомого элемента: " << i << endl;

            /*
                TODO: кажется, что нет смысла крутить дальше цикл, если мы нашли нужный
                нам элемент и тратить ресурсы процессора. Стоит тут завершить работу функции
                и выйти из нее
            */
        }
    }

/* 
    TODO
    В случае если элемент не был найден, хорошим тоном будет дать об этом знать.
    Например, в случае cpp кода вызвать исключение 

    throw std::runtime_error("Element with id " + std::to_string(key) + " hasn't found");

    и обработать его в месте вызова с помощью конструкции try catch 

    catch (const std::runtime_error& e) {
        // Catch the exception and print the custom error message.
        std::cerr << "Error: " << e.what() << std::endl;
    }

    или же, если используется текстовое общение с оператором функции, выдать сообщение, что элемент не был найден
*/
}

/*
    TODO:ткак обсуждали ранее, в случае если элемент не помещается в размер массива - нужно
    делать реалоцирование памяти и копировать значения из старой области памяти в новую
    в таком случае нужно как то дать понять в место вызова, что мы возвращаем новое значение массива, например, 
    возвращать не void, а указатель на массив с новым значнием

    int* add_element(int* array, int& len_arr)
*/

//void add_element(int* array, int& len_arr) {}

/* 
    TODO: возможно, стоит переименовать в delete_element_by_index - так будет понятнее что функция по индекску
    а не по значению
*/

bool delete_element(int* array, int& len_arr) {
    int n;

    // TODO: тоже самое про ввод что и выше
    cout << "Укажите номер элемента массива, который необходимо удалить: ";
    cin >> n;

    if (n > len_arr || n < 1)
    {
        /*
            TODO: кажется, что очень асбтрактно, пользователь не поймет из сообщения что сделано не так
            я бы расписал что пошло не так и предложил пользователю возможность решения его проблемы
        */
        cout << "Ошибка удаления" << endl;
        return false;
    }

    for (int i = n - 1; i < len_arr - 1; i++)
    {
    /*
        TODO: тут все правильно, на встрече я ошибся, потому как когда у нас будет крайний i, это будет
        эллемент второй с конца массива (len_arr - 2) и он запишет значение последнего элемента массива
        (len_arr - 1)
    */ 
        array[i] = array[i + 1];

    }
    len_arr--;
    return true;
}


int main()
{
    setlocale(LC_ALL, "rus");

    int length;
    // TODO: тоже обработка ввода нужна
    cout << "Введите количество элементов массива: ";
    cin >> length;
    cout << "debug: " << length << endl;

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
