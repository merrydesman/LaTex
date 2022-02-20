#include <iostream>
#include <string> 
#include "math.h"
using namespace std;
#define M_PI 3.14159265358979323846


class Human {
private:
	int age_m;

public:
	void setAge(int age) {
		age_m = age;
	}

	int getAge() {
		return age_m;
	}
};

class Position {
private:
	double xPos;
	double yPos;
	double nx;
	double ny;
	double c;
	long int R = 6371302;

public:
	void setPosX(double x) {
		xPos = x;
	}

	void setPosY(double y) {
		yPos = y;
	}

	double getPosX() {
		return xPos;
	}

	double getPosY() {
		return yPos;
	}

	void changePosX(double x) {
		nx = x;
	}

	void changePosY(double y) {
		ny = y;
	}

	double getNX() {
		return nx;
	}

	double getNY() {
		return ny;
	}

	void makeWay(double x, double y, double nx, double ny) {
		double lat1 = x * M_PI / 180;
		double lat2 = nx * M_PI / 180;
		double long1 = y * M_PI / 180;
		double long2 = ny * M_PI / 180;

		double cl1 = cos(lat1);
		double cl2 = cos(lat2);
		double sl1 = sin(lat1);
		double sl2 = sin(lat2);
		double delta = long2 - long1;
		double cdelta = cos(delta);
		double sdelta = sin(delta);

		double yD = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
		double xD = sl1 * sl2 + cl1 * cl2 * cdelta;

		double bigRound = atan2(yD, xD);
		c = bigRound * R;
	}

	float getWay() {
		return c;
	}
	
};




int main() {
	Human adam;
	Position x, y, nx, ny, c;
	double xi, yi, nxi, nyi;
	double a;
	double b;
	int steps;
	int age;

	cout << "Enter your age" << "\n";
	cin >> age;
	adam.setAge(age);
	
	x.setPosX(59.8944);
	y.setPosY(30.26417);

	xi = x.getPosX();
	yi = y.getPosY();
	
	cout << "How long do you want to go? (Enter the number of steps)" << "\n";
	cin >> steps;
	

	for (int i = 1; i < steps+1; i++) {
		cout << "Now you are at " << "x: " << x.getPosX() << " y: " << y.getPosY() << "\n";
		cout << "Step " << i << "\n";
		cout << "Move by x: ";
		cin >> a;
		cout << "Move by y: ";
		cin >> b;

		nx.changePosX(a);
		ny.changePosY(b);
		nxi = nx.getNX();
		nyi = ny.getNY();
		c.makeWay(xi, yi, nxi, nyi);
		x.setPosX(a);
		y.setPosY(b);
	}


	cout << "Your age - " << adam.getAge() <<"\n";
	cout << "Your position x: " << x.getPosX() << " y: " << y.getPosY() << "\n";
	cout << "You walked " << c.getWay() << " meters" << "\n";

	return 0;
}