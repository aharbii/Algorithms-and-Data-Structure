#include <iostream>

using namespace std;

class ToeplitzMatrix
{
private:
    int *A;
    int n;

public:
    ToeplitzMatrix(int len);
    void matrix_set(int i, int j, int key);
    int matrix_get(int i, int j);
    void matrix_display();
    ~ToeplitzMatrix();
};

ToeplitzMatrix::ToeplitzMatrix(int len)
{
    this->n = len;
    int size = n + (n - 1);
    A = new int[size];
}

ToeplitzMatrix::~ToeplitzMatrix()
{
    delete[] A;
}

void ToeplitzMatrix::matrix_set(int i, int j, int key)
{
    if (i == 1)
    {
        int index = j - 1;
        A[index] = key;
    }
    else if (j == 1)
    {
        int index = n + (i - 2);
        A[index] = key;
    }
}

int ToeplitzMatrix::matrix_get(int i, int j)
{
    if (i <= j)
    {
        int index = j - i;
        return A[index];
    }
    else if (j == 1)
    {
        int index = n + (i - j - 1);
        return A[index];
    }
    return 0;
}

void ToeplitzMatrix::matrix_display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                int index = j - i;
                int value = A[index];
                cout << value << " ";
            }
            else if (i > j)
            {
                int index = n + (i - j - 1);
                int value = A[index];
                cout << value << " ";
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
    int n;
    cout << "Enter dimension: ";
    cin >> n;
    ToeplitzMatrix m(n);

    cout << "Enter all elements: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            cin >> value;
            m.matrix_set(i, j, value);
        }
    }

    cout << endl
         << endl;
    m.matrix_display();
    return 0;
}