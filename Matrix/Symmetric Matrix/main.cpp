#include <iostream>

using namespace std;

#define ROW_MODE 1
#define COL_MODE 2

class SymmetricMatrix
{
private:
    int *A;
    int n;

public:
    SymmetricMatrix(int len);
    void matrix_set(int i, int j, int key, int mode);
    int matrix_get(int i, int j, int mode);
    void matrix_display(int mode);
    ~SymmetricMatrix();
};

SymmetricMatrix::SymmetricMatrix(int len)
{
    this->n = len;
    int size = (n * (n + 1)) / 2;
    A = new int[size];
}

SymmetricMatrix::~SymmetricMatrix()
{
    delete[] A;
}

void SymmetricMatrix::matrix_set(int i, int j, int key, int mode)
{
    if ((i >= j) && (i <= n) && (j <= n))
    {
        int index = 0;
        switch (mode)
        {
        case ROW_MODE:
            index = ((i * (i - 1)) / 2) + (j - 1);
            break;
        case COL_MODE:
            index = n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j;
            break;
        default:
            break;
        }
        A[index] = key;
    }
}

int SymmetricMatrix::matrix_get(int i, int j, int mode)
{
    if ((i < j) && (i <= n) && (j <= n))
    {
        int temp = i;
        i = j;
        j = temp;
    }
    int index = 0;
    switch (mode)
    {
    case ROW_MODE:
        index = ((i * (i - 1)) / 2) + (j - 1);
        break;
    case COL_MODE:
        index = n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j;
        break;
    default:
        break;
    }
    return A[index];
}

void SymmetricMatrix::matrix_display(int mode)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = i;
            int y = j;
            if (x < y)
            {
                int temp = x;
                x = y;
                y = temp;
            }

            int index = 0;
            switch (mode)
            {
            case ROW_MODE:
                index = ((x * (x - 1)) / 2) + (y - 1);
                break;
            case COL_MODE:
                index = n * (y - 1) + (y - 2) * (y - 1) / 2 + x - y;
                break;
            default:
                break;
            }

            cout << A[index] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter dimension: ";
    cin >> n;
    SymmetricMatrix matrix(n);
    cout << "Enter all elements: ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            cin >> value;
            matrix.matrix_set(i, j, value, COL_MODE);
        }
    }

    cout << endl
         << endl;
    matrix.matrix_display(COL_MODE);

    return 0;
}