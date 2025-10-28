#include <iostream>
#include <cmath>
using namespace std;
class Shape{
    protected:
    string name;
    float r; //taliin urt, radius buguud busad dursed udamshina
    public:
     Shape(string n = "Shape", float rr=0) {
        name = n;
        r=rr;
    }
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setR(float rr){ r=rr;}
    float getR(){ return r;}
};
class TwoDShape : public Shape {
protected:
    float area;
    float perimeter;
public:
    TwoDShape(string n = "2D Shape", float rr = 0)
        : Shape(n, rr) {}  // эх классын байгуулагч рүү параметр дамжуулж байна
    float getArea() { return area; }
    float getPerimeter() { return perimeter; }
};
//triangle enkhush
class Triangle : public TwoDShape {
private:
    float x1, y1;
    float x2, y2;
    float x3, y3;

public:
    Triangle(float x, float y, float side, string n = "Triangle")
        : TwoDShape(n, side) // эх классын Shape рүү side дамжуулж байна
    {
        x1 = x;
        y1 = y;
        calcVertices();
        calcArea();
        calcPerimeter();
    }

    void calcVertices() {
        float h = (sqrt(3) / 2) * r; // r-г эх клаассаас шууд ашиглаж болно
        x2 = x1 - (r / 2);
        y2 = y1 - h;
        x3 = x1 + (r / 2);
        y3 = y1 - h;
    }

    void calcArea() {
        area = (sqrt(3) / 4) * pow(r, 2);
    }

    void calcPerimeter() {
        perimeter = 3 * r;
    }

    void print() {
        cout << "Shape: " << name << endl;
        cout << "Vertices: " << endl;
        cout << "  A(" << x1 << ", " << y1 << ")\n";
        cout << "  B(" << x2 << ", " << y2 << ")\n";
        cout << "  C(" << x3 << ", " << y3 << ")\n";
        cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
    }
};
class circle: public TwoDShape {
private:
float x_center;
float y_center;
public:
circle(float x, float y, float radius, string n="Circle"): TwoDShape(n, radius){
    x_center=x;
    y_center=y;
    calcArea();
    calcPerimeter();
}
void calcArea(){
    area= M_PI * r * r;
}
void calcPerimeter(){
    perimeter= 2 * M_PI * r;
}
void print(){
    cout<<"Shape: "<<name<<endl;
    cout<<"Center: ("<<x_center<<", "<<y_center<<")"<<endl;
    cout<<"Area: "<<area<<", Perimeter: "<<perimeter<<endl;
}

};




//square shagai

int main(){
Triangle t1(0, 0, 6, "Equilateral Triangle");
    t1.print();
    circle c1(0, 0, 5, "Circle");
    c1.print();
}


