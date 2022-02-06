#include <iostream>

using namespace std;

#define ROW_MODE 1
#define COL_MODE 2

class LowerTriangleMatrix
{
private:
    int *A;
    int n;

public:
    LowerTriangleMatrix(int len);
    void matrix_set(int i, int j, int key, int mode);
    int matrix_get(int i, int j, int mode);
    void matrix_display(int mode);
    ~LowerTriangleMatrix();
};

LowerTriangleMatrix::LowerTriangleMatrix(int len)
{
    this->n = len;
    int size = (n * (n + 1)) / 2;
    A = new int[size];
}

LowerTriangleMatrix::~LowerTriangleMatrix()
{
    delete[] A;
}

void LowerTriangleMatrix::matrix_set(int i, int j, int key, int mode)
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

int LowerTriangleMatrix::matrix_get(int i, int j, int mode)
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
        return A[index];
    }
    return 0;
}

void LowerTriangleMatrix::matrix_display(int mode)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
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
                cout << A[index] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
        ;
    }
}

int main()
{
    int n;
    cout << "Enter dimension: ";
    cin >> n;
    LowerTriangleMatrix matrix(n);
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