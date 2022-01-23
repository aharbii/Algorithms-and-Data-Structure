#include <iostream>

using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int key);
    int get(int i, int j);
    void display();
    ~Diagonal()
    {
        delete[] A;
    }
};

void Diagonal::set(int i, int j, int key)
{
    if (i == j)
    {
        A[i - 1] = key;
    }
}

int Diagonal::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    return 0;
}

void Diagonal::display()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Diagonal matrix(4);
    matrix.set(1, 1, 5);
    matrix.set(2, 2, 8);
    matrix.set(3, 3, 9);
    matrix.set(4, 4, 12);
 
    cout << matrix.get(2, 2) << endl;
    matrix.display();

    return 0;
}
