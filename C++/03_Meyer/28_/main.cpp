
#include <iostream>
#include <memory>


class Point{

public:
  Point(int x, int y):x(x),y(y) {}
  Point(const Point &a){x=a.x; y=a.y;}
  void setX(int newX){x = newX;}
  void setY(int newY){y = newY;}

  int getX(){return x;}
  int getY(){return y;}

private:
int x, y;
};


struct RecData{
  Point ulhc, lrhc;
  RecData(Point c1, Point c2):ulhc(c1),lrhc(c2){}
};

class Rectangle{
public:
  Rectangle (Point c1, Point c2):pData(new RecData(c1, c2)) {}

  //Point &upperLeft() const {return pData->ulhc;}
  //Point &lowerRight() const {return pData->lrhc;}
  
  const Point &upperLeft() const {return pData->ulhc;}
  const Point &lowerRight() const {return pData->lrhc;}

private:
  std::shared_ptr<RecData> pData;
};


int main(){
std::cout << " starts ...\n";

Point coord1(0,0);
Point coord2(100,100);

const Rectangle rec(coord1, coord2);

rec.upperLeft().setX(50);

std::cout << rec.upperLeft().getX() << " "<< rec.upperLeft().getY() << "\n";
std::cout << rec.lowerRight().getX() << " "<< rec.lowerRight().getY() << "\n";

std::cout << "\n ends \n";
return 1;
}
