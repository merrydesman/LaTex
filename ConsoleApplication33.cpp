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
	long double c;
	long int R = 6371302;
	double speed[1000];
	double direction[1000];

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


	double calcDistaneX(double x, double y, int i, double alpha, double s, double d) {
		if (i == 1) {
			speed[0] = 0.0;
			direction[0] = 0.0;
		}
		
		speed[i] = alpha * speed[i - 1] + (1 - alpha) * s + sqrt((1 - pow(alpha, 2)) * speed[i - 1]);
		direction[i] = alpha * direction[i - 1] + (1 - alpha) * d + sqrt((1 - pow(alpha, 2)) * direction[i - 1]);
		double mx = x + speed[i - 1] * cos(direction[i - 1]);
		
		return mx;

	}

	double calcDistaneY(double x, double y, int i, double alpha, double s, double d) {
		if (i == 1) {
			speed[0] = 0.0;
			direction[0] = 0.0;
		}

		speed[i] = alpha * speed[i - 1] + (1 - alpha) * s + sqrt((1 - pow(alpha, 2)) * speed[i - 1]);
		direction[i] = alpha * direction[i - 1] + (1 - alpha) * d + sqrt((1 - pow(alpha, 2)) * direction[i - 1]);
		double my = y + speed[i - 1] * sin(direction[i - 1]);
		
		return my;
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
		c = (bigRound * R) / 1000;
	}

	float getWay() {
		return c;
	}
	
};




int main() {
	Human adam;
	Position x, y, nx, ny, c, dlx, dly;
	double xi, yi, nxi, nyi;
	double a;
	double b;
	int steps;
	int age;

	cout << "Enter your age: ";
	cin >> age;
	adam.setAge(age);

	cout << "Where are you now? " << "\n";

	cout << "x: ";
	cin >> a;

	cout << "y: ";
	cin >> b;

	x.setPosX(a);
	y.setPosY(b);

	cout << "How long do you want to go? (Enter the number of steps)" << "\n";
	cin >> steps;
	
	for (int i = 1; i < steps + 1; i++) {

		double alpha = rand() % 2;
		double s = rand() % 12 + 4;
		double d = rand() % 360;
		xi = x.getPosX();
		yi = y.getPosY();
		nxi = dlx.calcDistaneX(xi, yi, i, alpha, s, d);
		nyi = dly.calcDistaneY(xi, yi, i, alpha, s, d);
			
		c.makeWay(xi, yi, nxi, nyi);

		x.setPosX(nxi);
		y.setPosY(nyi);
		
		cout << "Your position x: " << x.getPosX() << " y: " << y.getPosY() << "\n";
		cout << "You walked " << c.getWay() << " kilometers" << "\n";
	}
	
	return 0;
}