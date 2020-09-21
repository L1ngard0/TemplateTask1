// TemplateTask1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template<typename T>
class Turn
{
public:
    int n = 0;
    T* value;
    int N;
    Turn(int N)
    {
        value = new T[N];
        this->N = N;
    }
   
    void push(T importance)
    {
        if (n == N)
        {
            cout << "Переполнение очереди" << endl;
        }
        else
        {
            value[n] = importance;
            n++;
        }
    }
   
    void pop()
    {
        for (int i = 0; i < n; i++)
        {
            value[i] = value[i + 1];
        }
        n--;
    }
   
    void Show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << value[i] << " ";
        }
        cout << endl;
    }
   
    void Union(Turn op)
    {
        T* arr = new T[N];
        for (int i = 0; i < n; i++)
        {
            arr[i] = value[i];
        }
        int y = n;
        n = n + op.n;
        N = N + op.N;
        value = new T[N];
        int j = 0;
        for (int i = y; i < n; i++)
        {
            value[i] = op.value[j];
            j++;
        }
        for (int i = 0; i < y; i++)
        {
            value[i] = arr[i];
        }
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    Turn<int> arr(4);
    arr.push(10);
    arr.push(30);
    
    arr.Show();
    arr.pop();
    arr.Show();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
