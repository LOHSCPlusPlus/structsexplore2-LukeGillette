
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
struct Line {
    Point start;
    Point end;
    Line(Point s, Point e);
};
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

Line::Line(Point s, Point e) {
    start = s;
    end = e;
}

void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y;
}


void PrintLine(Line l) {
    cout << "  Start";
    PrintPoint(l.start);
    cout << "   End";
    PrintPoint(l.end); 
    cout << endl;
}

// This is new
Point FindMidPoint(Line l) {
    Point mid;
    mid.x = (l.start.x + l.end.x)/2.0;
    mid.y = (l.start.y + l.end.y)/2.0;
    return mid;
}
Point FindLowestPoint(Line l) {
  Point low;
  if (l.start.y > l.end.y) {
    return l.end;
  }
  else {
    return l.start;
  }
}

int main() {
    Line a(Point(3,9), Point(12,22));
    Line b(Point(7,-9), Point(8,-15));
    cout << "Line a";
    PrintLine(a);
    cout << "Line a's midpoint";
    // This is new
    Point midPoint = FindMidPoint(a);
    PrintPoint(midPoint);
    cout << endl;
    cout << "Line a's lowpoint";
    Point lowPoint = FindLowestPoint(a);
    PrintPoint(lowPoint);
    cout << endl;
    cout << "Line b's lowpoint";
    Point lowestPoint = FindLowestPoint(b);
    PrintPoint(lowestPoint);
    cout << endl;
    return 0;
}


