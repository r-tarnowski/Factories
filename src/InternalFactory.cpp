#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "Factories, Internal Factory                      "<< endl;
   cout << "================================================" << endl;
   cout << endl;
}


class Point {

private:
   float x;
   float y;

   Point(float x, float y)
         : x { x }, y { y } {
      std::cout << "Constructor Point( " << x << ", " << y << ") called." << std::endl;
   }

public:

   class PointFactory {
   public:
      static Point newCartesianPoint( const float x, const float y ) {
         return Point{ x, y };
      }

      static Point newPolarPoint( const float radius, const float theta ) {
         return Point{ radius * cos(theta), radius * sin( theta ) };
      }
   };

   friend std::ostream& operator<<(std::ostream& os, const Point & point) {
      return os << "P(" << point.x << ", " << point.y << ")";
   }

};


int main(int argc, char *argv[]) {
   printHeader();

   Point cartesianPoint = Point::PointFactory::newCartesianPoint( 1.0, 2.0 );
   std::cout << "cartesianPoint: " << cartesianPoint << std::endl;

   Point polarPoint = Point::PointFactory::newPolarPoint( 1.0, M_PI_4f);
   std::cout << "polarPoint: " << polarPoint << std::endl;

   cout << endl;
   return 0;
}