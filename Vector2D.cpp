#include <iostream>
using namespace std;

class Vector2D
{

public:
    Vector2D(){
        float x, y;
    }
	Vector2D(float x, float y){
		x_x=x;
		y_y=y;
		}
	float getX(){
		return x_x;
	}
	float getY(){
		return y_y;
	}
	void setX(float x){
	    this->x_x = x;
	}
    void setY(float y){
        this->y_y = y;
    }

//сумма двух векторов
	Vector2D operator+ (const Vector2D& v2){
	    float a, b;
      a = this->getX() + v2.x_x;
	    b = this->getY() + v2.y_y;
	    return Vector2D(a, b);
	}
  
//разница двух векторов
  Vector2D operator- (const Vector2D& v2){
	    float a, b;
      a = this->getX() - v2.x_x;
	    b = this->getY() - v2.y_y;
	    return Vector2D(a, b);
	}
  
  //умножение на константу vector*a
	Vector2D operator* (const int a){
	    float x = (this->getX()) * a;
	    float y = (this->getY()) * a;
	    return Vector2D(x, y);
	}

//произведение векторов
  Vector2D operator* (const Vector2D& v2){
	    float x = (this->getX()) * v2.x_x;
	    float y = (this->getY()) * v2.y_y;
	    return Vector2D(x, y);
	}
	friend ostream& operator<<(ostream& os, Vector2D& v);

private:
	float x_x, y_y;


};
//вывод вектора в формате (1;1)
ostream& operator<<(ostream& os, Vector2D& v){
	os<<"(" << v.getX() <<"; "<< v.getY()<<")";
	return os;
}

//чтение вектора
istream& operator>>(istream &is, Vector2D &v){
    int a, b;
    is>> a >> b;
    v.setX(a);
    v.setY(b);
    return is;
}

//умножение на константу a*vector
Vector2D operator* (int a, Vector2D& v){
    float x = a * v.getX();
    float y = a * v.getY();
    return Vector2D(x, y);
}
