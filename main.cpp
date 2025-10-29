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
class Circle: public TwoDShape {
private:
float x_center;
float y_center;
public:
Circle(float x, float y, float radius, string n="Circle"): TwoDShape(n, radius){
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
 
    TwoDShape *p[10];
    p[0] = new Circle(0,0,3,"Circle1");
    p[1] = new Triangle(1,1,4,"Triangle1");
    p[2] = new Square(2,2,2,"Square1");
    p[3] = new Circle(1,2,5,"Circle2");
    p[4] = new Triangle(0,0,3,"Triangle2");
    p[5] = new Square(-1,1,4,"Square2");
    p[6] = new Circle(1,3,4, "Circle3");
    p[7] = new Triangle(1,4,5,"Triangle3");
    p[8] = new Square(1,0,1, "Square3");
    int n=9;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j]->getArea()>p[j+1]->getArea()){
                TwoDShape *t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;

            }
        }
    }
    for(int i=0; i<n; i++){
        p[i]->print();
        cout<<endl;
    }
    for(int i=0; i<n; i++)
 delete p[i];  

}


