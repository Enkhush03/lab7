#include <iostream>
using namespace std;
class Shape{
    protected:
    string name;
    public:
     Shape(string n = "Shape") {
        name = n;
    }
    void setName(string n) { name = n; }
    string getName() { return name; }
};
class TwoDShape : public Shape {
protected:
    float area;
    float perimeter;
public:
    TwoDShape(string n = "2D Shape") : Shape(n) {}
    float getArea() { return area; }
    float getPerimeter() { return perimeter; }
};
//triangle enkhush
//circle nomio
//square shagai

int main(){

}
