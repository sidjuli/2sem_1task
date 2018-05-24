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

    Matrix2D add (Matrix2D m){
    Matrix2D v;
        v.a = this->a + m.a;
        v.b = this->b + m.b;
        v.c = this->c + m.c;
        v.d = this->d + m.d;
        return v;
    }

    Matrix2D subtract (Matrix2D m){
        Matrix2D v;
        v.a = this->a - m.a;
        v.b = this->b - m.b;
        v.c = this->c - m.c;
        v.d = this->d - m.d;
        return v;
    }

    Matrix2D multiply (float n){
        Matrix2D v;
        v.a = this->a * n;
        v.b = this->b * n;
        v.c = this->c * n;
        v.d = this->d * n;
        return v;
    }

    Matrix2D matrix_multiply (Matrix2D m){
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

    float determinant ();
    void print (Matrix2D m);
};
void Matrix2D::print(Matrix2D v)
{
    cout << "||" << v.a << " " << v.b << "||" << endl << "||" << v.c << " " << v.d << "||";
}

float Matrix2D::determinant()
{
    return this->a * this -> d - this->b * this->c;
}
