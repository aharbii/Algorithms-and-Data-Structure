#include <iostream>

using namespace std;

#define ROW_MODE 1
#define COL_MODE 2

class UpperTriangleMatrix
{
private:
    int *A;
    int n;

public:
    UpperTriangleMatrix(int len);
    void matrix_set(int i, int j, int key, int mode);
    int matrix_get(int i, int j, int mode);
    void matrix_display(int mode);
    ~UpperTriangleMatrix();
};

UpperTriangleMatrix::UpperTriangleMatrix(int len)
{
    this->n = len;
    int size = (n * (n + 1)) / 2;
    A = new int[size];
}

UpperTriangleMatrix::~UpperTriangleMatrix()
{
    delete[] A;
}

void UpperTriangleMatrix::matrix_set(int i, int j, int key, int mode)
{
    if ((i <= j) && (i <= n) && (j <= n))
    {
        int index = 0;
        switch (mode)
        {
        case COL_MODE:
            index = ((j * (j - 1)) / 2) + (i - 1);
            break;
        case ROW_MODE:
            index = ((n * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
            break;
        default:
            break;
        }
        A[index] = key;
    }
}

int UpperTriangleMatrix::matrix_get(int i, int j, int mode)
{
    if ((i <= j) && (i <= n) && (j <= n))
    {
        int index = 0;
        switch (mode)
        {
        case COL_MODE:
            index = ((j * (j - 1)) / 2) + (i - 1);
            break;
        case ROW_MODE:
            index = ((n * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
            break;
        default:
            break;
        }
        return A[index];
    }
    return 0;
}

void UpperTriangleMatrix::matrix_display(int mode)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                int index = 0;
                switch (mode)
                {
                case COL_MODE:
                    index = ((j * (j - 1)) / 2) + (i - 1);
                    break;
                case ROW_MODE:
                    index = ((n * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
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
    UpperTriangleMatrix matrix(n);
    cout << "Enter all elements: ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            cin >> value;
            matrix.matrix_set(i, j, value, ROW_MODE);
        }
    }

    cout << endl
         << endl;
    matrix.matrix_display(ROW_MODE);

    return 0;
}