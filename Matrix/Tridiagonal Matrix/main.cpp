#include <iostream>

using namespace std;

class TridiagonalMatrix
{
private:
    int *A;
    int n;
public:
    TridiagonalMatrix(int len);
    void matrix_set(int i, int j, int key);
    int matrix_get(int i, int j);
    void matrix_display();
    ~TridiagonalMatrix();
};

TridiagonalMatrix::TridiagonalMatrix(int len)
{
    this->n = len;
    int size = 3 * n - 2;
    A = new int[size];
}

TridiagonalMatrix::~TridiagonalMatrix()
{
    delete []A;
}

void TridiagonalMatrix::matrix_set(int i, int j, int key)
{
    if ((i - j) == 1)
    {
        int index = i - 2;
        A[index] = key;
    }
    else if ((i - j) == 0)
    {
        int index = ((n)-1) + (i - 1);
        A[index] = key;
    }
    else if ((i - j) == -1)
    {
        int index = ((2 * n) - 1) + (i - 1);
        A[index] = key;
    }
}

int TridiagonalMatrix::matrix_get(int i, int j)
{
    if ((i - j) == 1)
    {
        int index = i - 2;
        return A[index];
    }
    else if ((i - j) == 0)
    {
        int index = ((n)-1) + (i - 1);
        return A[index];
    }
    else if ((i - j) == -1)
    {
        int index = ((2 * n) - 1) + (i - 1);
        return A[index];
    }
    return 0;
}

void TridiagonalMatrix::matrix_display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i - j) == 1)
            {
                int index = i - 2;
                int value = A[index];
                cout << value << " ";
            }
            else if ((i - j) == 0)
            {
                int index = ((n)-1) + (i - 1);
                int value = A[index];
                cout << value << " ";
            }
            else if ((i - j) == -1)
            {
                int index = ((2 * n) - 1) + (i - 1);
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
    TridiagonalMatrix m(n);
 
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

    cout << endl << endl;
    m.matrix_display();
    return 0;
}