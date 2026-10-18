  #ifndef MATRIXBASE_H
  #define MATRIXBASE_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MatrixBase {
public :
    MatrixBase();
    MatrixBase(size_t, size_t);

    T getElement(size_t, size_t) const;
    void addElement(size_t, size_t, T);

    size_t getRows() const;
    size_t getCols() const;

    void Display() const;
protected :
    vector< vector<T> > data;
    size_t rows, cols;
};

template <class T>
MatrixBase<T>::MatrixBase():rows(0), cols(0){}

template <class T>
MatrixBase<T>::MatrixBase(size_t r, size_t c):data(r, vector<T>(c)), rows(r), cols(c){}

template <class T>
void MatrixBase<T>::addElement(size_t i, size_t j, T valeur){
    if (i >= rows || j >= cols){
        throw "indice invalide";
    }
    data[i][j] = valeur;
}

template <class T>
T MatrixBase<T>::getElement(size_t i, size_t j) const{
    if (i >= rows || j >= cols){
        throw "indice invalide";
    }
    return data[i][j];
}

template <class T>
size_t MatrixBase<T>::getRows() const{
    return rows;
}

template <class T>
size_t MatrixBase<T>::getCols() const{
    return cols;
}

template <class T>
void MatrixBase<T>::Display() const{
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

template <class T>
class MatrixNumerical : public MatrixBase<T>{
public:
    MatrixNumerical();
    MatrixNumerical(size_t, size_t);
    T getDeterminant() const;

    MatrixNumerical<T> operator + (const MatrixNumerical<T>&) const;
    MatrixNumerical<T> operator - (const MatrixNumerical<T>&) const;
    MatrixNumerical<T> operator * (const MatrixNumerical<T>&) const;
    MatrixNumerical<T> getInverse() const;
    MatrixNumerical<T> operator / (const MatrixNumerical<T>&) const;
    static MatrixNumerical<T> getIdentity(int);
};


template <class T>
T MatrixNumerical<T>::getDeterminant() const{
    if (this->rows != this->cols)
        throw "matrice non carree";
    if (this->rows == 1)
        return this->data[0][0];
    T det = 0;
    int signe = 1;
    for (size_t j = 0; j < this->cols; j++){
        MatrixNumerical<T> sous = getCoFactor(*this, 0, j);
        det = det + signe * this->data[0][j] * sous.getDeterminant();
        signe = -signe;
    }
    return det;
}


template <class T>
MatrixNumerical<T>::MatrixNumerical():MatrixBase<T>(){}

template <class T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c):MatrixBase<T>(r, c){}


template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator + (const MatrixNumerical<T>& m) const{
    if (this->rows != m.rows || this->cols != m.cols)
        throw "tailles differentes";

    MatrixNumerical<T> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++)
        for (size_t j = 0; j < this->cols; j++)
            res.data[i][j] = this->data[i][j] + m.data[i][j];
    return res;
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator - (const MatrixNumerical<T>& m) const{
    if (this->rows != m.rows || this->cols != m.cols)
        throw "tailles differentes";
    MatrixNumerical<T> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++)
        for (size_t j = 0; j < this->cols; j++)
            res.data[i][j] = this->data[i][j] - m.data[i][j];
    return res;
}



template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator * (const MatrixNumerical<T>& m) const{
    if (this->cols != m.rows)
        throw "produit impossible";
    MatrixNumerical<T> res(this->rows, m.cols);
    for (size_t i = 0; i < this->rows; i++)
        for (size_t j = 0; j < m.cols; j++)
            for (size_t k = 0; k < this->cols; k++)
                res.data[i][j] = res.data[i][j] + this->data[i][k] * m.data[k][j];
    return res;
}


// Q10

template <class T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m, size_t lig, size_t col){
    size_t n = m.getRows();
    MatrixNumerical<T> res(n - 1, n - 1);
    size_t a = 0;
    for (size_t i = 0; i < n; i++){
        if (i == lig)
            continue;
        size_t b = 0;
        for (size_t j = 0; j < n; j++){
            if (j == col)
                continue;
            res.addElement(a, b, m.getElement(i, j));
            b++;
        }
        a++;
    }
    return res;
}
template <class T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const{
    T det = getDeterminant();
    if (det == 0)
        throw "matrice non inv";
    size_t n = this->rows;
    MatrixNumerical<T> res(n, n);
    if (n == 1){
        res.data[0][0] = 1 / det;
        return res;
    }
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            T cofacteur = getCoFactor(*this, i, j).getDeterminant();
            if ((i + j) % 2 == 1)
                cofacteur = -cofacteur;
            res.data[j][i] = cofacteur / det;
            if (res.data[j][i] == 0)
                res.data[j][i] = 0;
        }
    }
    return res;
}


template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator / (const MatrixNumerical<T>& m) const{
    MatrixNumerical<T> inverse = m.getInverse();
    return (*this) * inverse;
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int n){
    MatrixNumerical<T> res(n, n);
    for (int i = 0; i < n; i++)
        res.data[i][i] = 1;
    return res;
}

#endif