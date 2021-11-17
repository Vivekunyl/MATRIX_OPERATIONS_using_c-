#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class Matrix{
    private:
        int rows;   //For rows
        int cols;   //For columns
        int **ptr; //pointer to pointer to point in the array 
    public:
    //Declaring Constructors and destructors
        Matrix(const Matrix &);
        Matrix(int, int);
        ~Matrix();
    //Declaring other functions
        friend istream& operator>>(istream &, Matrix &);
        friend ostream& operator<<(ostream &, Matrix &);
        Matrix operator +(const Matrix &);
        Matrix operator -(const Matrix &);
        Matrix operator *(const Matrix &);
        Matrix& operator =(const Matrix &);
        void transpose ( Matrix &);
    //End of class definition
};

//Defininng Copy constructor
Matrix::Matrix(const Matrix &m){
    rows = m.rows;
    cols = m.cols;
    ptr = new int* [rows];
    for(int i= 0;i<rows;i++){
        ptr[i]=new int [cols];
    }
    for(int i =0 ;i<rows;i++){
        for(int j=0;j<cols;j++){
    
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

//Defining parametrised constructor
Matrix::Matrix(int m, int n){
    rows = m;
    cols = n;
    ptr = new int* [m];
    for(int i =0;i<m;i++){
        ptr[i] = new int[n];
    }
}

//Defining oveloaded operator to take matrix as an input
istream & operator >>(istream &din , Matrix & m){
    for(int i =0;i<m.rows;i++){
        for(int j =0;j<m.cols;j++){
            din >> m.ptr[i][j];
        }
    }
    return din;
}

//Defining overoaded operator to display matrix 
ostream & operator << (ostream &dout, Matrix &m ){
    for(int i =0;i<m.rows;i++){
        for(int j = 0; j<m.cols;j++){
            dout<<setw(5)<< m.ptr[i][j];
        }
        dout<<endl;
    }
    return dout;
}

//Defining overloaded + opearator to add two matrices
Matrix Matrix::operator +(const Matrix &m){
    Matrix temp( rows, cols);
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            temp.ptr[i][j]= ptr[i][j] + m.ptr[i][j];
        }
    }
    return temp;
}

//Definig overloaded - operator to subtract two matrices
Matrix Matrix::operator -(const Matrix &m){
    Matrix temp(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            temp.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
        }
    }
    return temp;
}

//Defining overloaded *opeartor to perform matrix multiplication
Matrix Matrix::operator *(const Matrix &m){
    Matrix temp(rows,cols);
    int product_sum;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            product_sum =0;
            for(int k=0;k<rows;k++){
                product_sum += ptr[i][k] * m.ptr[k][j];
            }
            temp.ptr[i][j] = product_sum;
        }
    }
    return temp;
}

//Defining overloaded = operator to assingn matrix value into another matrix  
Matrix& Matrix::operator =(const Matrix & m){
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }
    return *this;
}
//Definig a function to perform transpose of a matrix
void Matrix::transpose( Matrix &m){
    for(int i=0;i< rows;i++){
        for(int j=0;j<cols;j++){
            ptr[j][i] = m.ptr[i][j];
        }
    }
}
//Definig Destructor
Matrix::~Matrix(){
    for(int i=0;i<rows;i++){
        delete[] ptr[i];
    }
    delete[] ptr;
}
//Main Function
int main(){
    cout<<"\n\t\t\t\tNOTE";
    cout<<"\n\tThis program is build to perform Operations on"; cout<<"\n\tmatrices,So user is adviced to input correct ";cout<<"\n\tvalues and must keep the understanding of";cout<<"\n\tmatrix properties (Matrix Addition,Matrix  "; cout<<"\n\tSubtraction ,Multiplication and Transpose). ";cout<<"\n\t\tTHANK YOU";
    cout<<endl;
    int row_1 ,row_2,col_1,col_2 ,chs;
    char choice;
    cout<<"\n\n\t\t\t\t\tCreate Matrix A";
    cout<<"\nEnter the number of rows for matrix : ";
    cin>>row_1;
    cout<<"\nEnter the number of columns for matrix : ";
    cin>>col_1;
    Matrix A(row_1,col_1);
    cout<<"\nEnter the elements of Matrix row wise : ";
    cin >> A;
    cout<<"\nEntered Matrix \n";
    cout << A;
    cout<<"\n\n\t\t\tCreate Matrix B";
    cout<<"\nEnter the number of rows for matrix : ";
    cin>>row_2;
    cout<<"\nEnter the number of columns for matrix : ";
    cin>>col_2;
    Matrix B(row_2,col_2);
    cout<<"\nEnter the elements of Matrix row wise : ";
    cin >> B;
    cout<<"\nEntered Matrix\n";
    cout << B;
    do{
        cout<<"\n\t\t\t\t\t1) Press 1 to add two matrices";
        cout<<"\n\t\t\t\t\t2) Press 2 to Subtract two matrices";
        cout<<"\n\t\t\t\t\t3) Press 3 to multiply two Matrices";
        cout<<"\n\t\t\t\t\t4) Press 4 to Find the transpose of the Matrices";
        cout<<"\nEnter your choice: ";
        cin>>chs;
        switch(chs){
            case 1:
                if((row_1==row_2) && (col_1==col_2)){
                    Matrix C(row_1, col_1); //initializing objects of Matrix class
                    C = A + B;
                    cout<<endl;
                    cout<<"Sum of Matrices A and B is: ";
                    cout<<endl;
                    cout << C;
                }
                else{
                    cout<<"\nAddition operation can not be performed ";
                    cout<<endl;

                }
                break;
            case 2:
                if((row_1==row_2) && (col_1==col_2)){
                    Matrix C(row_1, col_1);
                    C = A -B;
                    cout<<endl;
                    cout<<"Sutraction of Matrices A and B is:";
                    cout<<endl;
                    cout<< C;
                }
                else{
                    cout<<"\nSubtraction is not possible"<<endl;
                }
                break;
            case 3:
            {
                if(col_1 == row_2){
                    Matrix D(row_1,col_2);
                    D = A*B;
                    cout<<endl;
                    cout<<"Product of Matrices A and B is:";cout<<endl;
                    cout<< D;
                }
                else{
                    std::cout<<"\nMultiplication can not be performed \n";
                }
                break;
            }
            case 4:
            {
                Matrix C(col_1,row_1);
                Matrix D(col_2,row_2);
                C.transpose(A);
                cout<<endl;
                cout<<"Transpose of matrix A is: "<<endl;
                cout<<C;
                D.transpose(B);
                cout<<endl;
                cout<<"Transpose of Matrix B is: ";
                cout<<endl;
                cout<<D;
                break;
            }
            default:
                cout<<endl;
                cout<<" Wrong choice..Try again! ";
                break;
        }
        cout<<"\n\nDo you want to continue (y/n)\nEnter your choice: ";
        cin>>choice;

    }while((choice =='Y')||(choice == 'y'));


    return 0;
}