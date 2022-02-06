#include <iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int value;
};

class SparseMatrix
{
private:
    int m;
    int n;
    int num;
    Element *elements;
public:
    SparseMatrix(int x, int y, int non_zero)
    {
        m = x;
        n = y;
        num = non_zero;
        elements = new Element[num];
    };
    void read();
    void display();
    SparseMatrix add(SparseMatrix &B);
    ~SparseMatrix()
    {
        delete [] elements;
    };
};


void SparseMatrix::read()
{

    cout << "Enter all elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> elements[i].i >> elements[i].j >> elements[i].value;
    }
}

void SparseMatrix::display()
{
    cout << endl;
    int k = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i == elements[k].i) && (j == elements[k].j))
            {
                cout << elements[k].value << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

SparseMatrix SparseMatrix::add(SparseMatrix &B)
{
    if ((this->m != B.m) || (this->n != B.n))
    {
        return SparseMatrix(0, 0, 0);
    }

    SparseMatrix *sum = new SparseMatrix(m, n, num + B.num);
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < this->num && j < B.num)
    {
        if (this->elements[i].i < B.elements[j].i)
        {
            sum->elements[k++] = this->elements[i++];
        }
        else if (this->elements[i].i > B.elements[j].i)
        {
            sum->elements[k++] = B.elements[j++];
        }
        else
        {
            if (this->elements[i].j < B.elements[j].j)
            {
                sum->elements[k++] = this->elements[i++];
            }
            else if (this->elements[i].j > B.elements[j].j)
            {
                sum->elements[k++] = B.elements[j++];
            }
            else
            {
                sum->elements[k].i = this->elements[i].i;
                sum->elements[k].j = this->elements[i].j;
                sum->elements[k].value = this->elements[i].value + B.elements[j].value;
                k++;
                i++;
                j++;
            }
        }
    }
    while (i < this->num)
    {
        sum->elements[k++] = this->elements[i++];
    }
    while (j < B.num)
    {
        sum->elements[k++] = B.elements[j++];
    }
    sum->num = k;

    return *sum;
}

int main()
{
    SparseMatrix A(5, 5, 5);
    A.read();
    A.display();
    SparseMatrix B(5, 5, 5);
    B.read();
    B.display();

    SparseMatrix sum = A.add(B);
    sum.display();
    return 0;
}
