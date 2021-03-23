#include <iostream>
#include <ctime>

using namespace std;

//create class 1;
class Point1 {
protected:
    int x;
    int distance;

public:
    explicit Point1(int numberX) {
        x = numberX;
        distance = numberX * numberX;
    }

    Point1() {
        x = 0;
        distance = 0;
    }

    void setX(int numberX) {
        x = numberX;
        distance = numberX * numberX;
    }

    virtual void info() {
        cout << x << endl;
    }

    virtual int getDistance() { return distance; }
};

//create class 2;
class Point2 : public Point1 {
protected:
    int y;

public:
    Point2(int numberX, int numberY) : Point1(numberX) {
        y = numberY;
        distance = distance + numberY * numberY;
    }

    Point2() : Point1() {
        y = 0;
        distance = 0;
    }

    void info() override {
        cout << x << " " << y << endl;
    }

    int getDistance() override { return distance; }
};

//create class 3;

class Point3 : public Point2 {
    int z;

public:
    Point3(int numberX, int numberY, int numberZ) : Point2(numberX, numberY) {
        z = numberZ;
        distance = distance + numberZ * numberZ;
    }

    Point3() : Point2() {
        z = 0;
    }

    void info() override {
        cout << x << " " << y << " " << z << endl;
    }

    int getDistance() override { return distance; }
};

int main() {
    srand(time(nullptr));
    const int N = 10;
    Point3 pointer3[N];
    Point2 pointer2[N];
    Point1 pointer1[N];
    int x, y, z;
    for (auto &i : pointer3) {
        x = rand() % 10;
        y = rand() % 10;
        z = rand() % 10;
        i = Point3(x, y, z);
    }
    for (auto &i : pointer2) {
        x = rand() % 10;
        y = rand() % 10;
        i = Point2(x, y);
    }
    for (auto &i : pointer1) {
        x = rand() % 10;
        i = Point1(x);
    }
    cout << "unsorted array of points in space" << endl;
    for (auto &i : pointer3) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
    cout << "unsorted array of points on a plane" << endl;
    for (auto &i : pointer2) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
    cout << "unsorted array of points on a line" << endl;
    for (auto &i : pointer1) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++) {
            if (pointer3[j].getDistance() > pointer3[j + 1].getDistance()) {
                Point3 container3 = pointer3[j];
                pointer3[j] = pointer3[j + 1];
                pointer3[j + 1] = container3;
            }

            if (pointer2[j].getDistance() > pointer2[j + 1].getDistance()) {
                Point2 container2 = pointer2[j];
                pointer2[j] = pointer2[j + 1];
                pointer2[j + 1] = container2;
            }
            if (pointer1[j].getDistance() > pointer1[j + 1].getDistance()) {
                Point1 container1 = pointer1[j];
                pointer1[j] = pointer1[j + 1];
                pointer1[j + 1] = container1;
            }
        }
    cout << "---------------------------------"
         << "this is sorted array of points in space" << endl;
    for (auto &i : pointer3) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
    cout << "sorted array of points on a plane" << endl;
    for (auto &i : pointer2) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
    cout << "sorted array of points on a line" << endl;
    for (auto &i : pointer1) {
        i.info();
        cout << i.getDistance() << endl;
        cout << "==============================" << endl;
    }
}