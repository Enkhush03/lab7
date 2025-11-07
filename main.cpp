#include <iostream>
#include <cmath>
using namespace std;
class Shape{
    protected:
    string name;
    static int number;
    float r; //taliin urt, radius buguud busad dursed udamshina
    public:
     Shape(string n = "Shape", float rr=0) {
        this->name = n;
        this->r=rr;
        number++;
    }
    void setName(string n) { this->name = n; }
    string getName() { return this->name; }
    void setR(float rr){ this->r=rr;}
    float getR(){ return this->r;}
    static int getnumber(){return number;}
    static int setnumber(int n){number =n;}
    ~Shape(){
        number--;
    }

};
int Shape::number=0;

class TwoDShape : public Shape {
public:
    virtual  float area()=0;
    virtual  float perimeter()=0;
    virtual void print() = 0; // виртуал функц
    TwoDShape(string n = "2D Shape", float rr = 0)
        : Shape(n, rr) {}  // эх классын байгуулагч рүү параметр дамжуулж байна
    // float getArea() { return area; }
    // float getPerimeter() { return perimeter; }
   
    
};
//triangle enkhush
class Triangle : public TwoDShape {
private:
    float x1, y1, x2, y2, x3, y3;
public:
    Triangle(float x, float y, float side, string n = "Triangle") 
        : TwoDShape(n, side) {
        this->x1 = x; this->y1 = y;
        Vertices();
    }

    void Vertices() {
        float h = (sqrt(3)/2) * this->r;
        this->x2 = this->x1 - this->r/2; this->y2 = this->y1 - h;
        this->x3 = this->x1 + this->r/2; this->y3 = this->y1 - h;
    }

    float area() override { return (sqrt(3)/4) * pow(this->r, 2); }
    float perimeter() override { return 3*this->r; }

    void print() override {
        cout << "Shape: " << this->name << endl;
        cout << "Vertices: A(" << this->x1 << "," << this->y1 << ") B(" << this->x2 << "," << this->y2 << ") C(" << this->x3 << "," << this->y3 << ")" << endl;
        cout << "Area: " << this->area() << ", Perimeter: " << this->perimeter() << endl;
    }
};

class Circle: public TwoDShape {
private:
    float x_center, y_center;
public:
    Circle(float x, float y, float radius, string n="Circle"): TwoDShape(n, radius) {
        this->x_center=x; this->y_center=y;
    }

    float area() override { return M_PI*this->r*this->r; }
    float perimeter() override { return 2*M_PI*this->r; }

    void print() override {
        cout<<"Shape: "<<this->name<<endl;
        cout<<"Center: ("<<this->x_center<<", "<<this->y_center<<")"<<endl;
        cout<<"Area: "<<this->area()<<", Perimeter: "<<this->perimeter()<<endl;
    }
};

//square shagai
class Square : public TwoDShape {
private:
    float x, y; // Зүүн дээд оройн координат
public:
    Square(float x0, float y0, float side, string n = "Square") : TwoDShape(n, side), this->x(x0), this->y(y0) {}

    float area() override { return this->r*this->r; }
    float perimeter() override { return 4*this->r; }

    void print() override {
        cout << "Shape: " << this->name << endl;
        cout << "Top-left corner: (" << this->x << "," << this->y << ")" << endl;
        cout << "Area: " << this->area() << ", Perimeter: " << this->perimeter() << endl;
    }
};

int main(){
 //нэгэн төрлийн классуудыг нэг эх класст объектод нь хийгээд дотор нь эрэмбэлсэн.
    Shape::setnumber(0);
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
    cout<<"Niit uussen object:"<<Shape::getnumber()<<endl;
    int n=9;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j]->area()>p[j+1]->area()){
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


