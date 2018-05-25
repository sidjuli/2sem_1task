#include <iostream>
#include "Vector2D.cpp"
using namespace std;

class Matrix2D
{
public:
    float a, b, c, d;
    Matrix2D(){}

	Matrix2D(float A, float B, float C, float D){
        a = A;
        b = B;
        c = C;
        d = D;
    }

	float getA(){
	    return this->a;
	}

	float getB(){
	    return this->b;
	}

	float getC(){
	    return this->c;
	}

	float getD(){
	    return this->d;
	}

	void setA(float A){
	    this->a = A;
	}

    void setB(float B){
        this->b = B;
    }

    void setC(float C){
        this->c = C;
    }

    void setD(float D){
        this->d = D;
    }

    Matrix2D operator+ (Matrix2D m){
    Matrix2D v;
        v.a = this->a + m.a;
        v.b = this->b + m.b;
        v.c = this->c + m.c;
        v.d = this->d + m.d;
        return v;
    }

    Matrix2D operator- (Matrix2D m){
        Matrix2D v;
        v.a = this->a - m.a;
        v.b = this->b - m.b;
        v.c = this->c - m.c;
        v.d = this->d - m.d;
        return v;
    }

    Matrix2D operator* (float n){
        Matrix2D v;
        v.a = this->a * n;
        v.b = this->b * n;
        v.c = this->c * n;
        v.d = this->d * n;
        return v;
    }

    Matrix2D operator*(Matrix2D m){
        Matrix2D v;
        v.a = this->a * m.a + this->b * m.c;
        v.b = this->a * m.b + this->b * m.d;
        v.c = this->c * m.a + this->d * m.c;
        v.d = this->c * m.b + this->d * m.d;
        return v;
    }
    Vector2D operator* (const Vector2D v)
    {
        double a = this->a * v.getX() + this->b * v.getY();
        double b = this->c * v.getX() + this->d * v.getY();
        return Vector2D (a, b);
    }

    float determinant ()
    {
        return this->a * this -> d - this->b * this->c;
    }
    friend ostream& operator<< (ostream &os, Matrix2D m)
    {
        os << "|" << m.getA() << " " << m.getB() << "|" << endl << "|" << m.getC() << " " << m.getD() << "|" <<endl;
        return os;
    }
    friend Matrix2D operator* (int n, Matrix2D& m){
        m.a = m.a * n;
        m.b = m.b * n;
        m.c = m.c * n;
        m.d = m.d * n;
        return m;
}
};
