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
    virtual void print() = 0; // виртуал функц
    
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
        Vertices();
        Area();
        Perimeter();
    }

    void Vertices() {
        float h = (sqrt(3) / 2) * r; // r-г эх клаассаас шууд ашиглаж болно
        x2 = x1 - (r / 2);
        y2 = y1 - h;
        x3 = x1 + (r / 2);
        y3 = y1 - h;
    }

    void Area() {
        area = (sqrt(3) / 4) * pow(r, 2);
    }

    void Perimeter() {
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
class Square: public TwoDShape {
private: 
    float x1;
    float y1;
public:
    Square(float x, float y, float side, string n="Square"): 
    TwoDShape(n, side){
        x1=x;
        y1=y;
        calcArea();
        calcPerimeter();
}
    void calcArea(){
        area= r * r;
    }
    void calcPerimeter(){
        perimeter= 4 * r;
    }
    void print(){
        cout<<"Shape: "<<name<<endl;
        cout<<"Top-left corner: ("<<x1<<", "<<y1<<")"<<endl;
        cout<<"Area: "<<area<<", Perimeter: "<<perimeter<<endl;
    }
};


//square shagai

int main(){
    Triangle* t1= new Triangle(0, 0, 4);
    circle* c1= new circle(1, 1, 3);
    Square* s1= new Square(-1, 1, 2);  
    Triangle* t2= new Triangle(2, 2, 5, "MyTriangle");
    circle* c2= new circle(0, 0, 1, "MyCircle");
    Square* s2= new Square(3, 3, 4, "MySquare");
    TwoDShape* shapes[6]={t1, c1, s1, t2, c2, s2};
    auto swap=[](TwoDShape*& a, TwoDShape*& b){
        TwoDShape* temp=a;
        a=b;
        b=temp; 
    };
    for(int i=0; i<6-1; i++){
        for(int j=0; j<6-i-1; j++){
            if(shapes[j]->getArea() > shapes[j+1]->getArea()){
                swap(shapes[j], shapes[j+1]);
            }
        }
    }
    for(int i=0; i<6; i++){
        shapes[i]->print();
        cout<<endl;
    }
    for(int i=0; i<6; i++){
        delete shapes[i];
            return 0;
    }
    
  

}


