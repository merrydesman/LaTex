#include <iostream>
#include <string> 
#include "math.h"
using namespace std;

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
	int xPos;
	int yPos;
	int nx;
	int ny;
	float c = 0;

public:
	void setPosX(int x) {
		xPos = x;
	}

	void setPosY(int y) {
		yPos = y;
	}

	int getPosX() {
		return xPos;
	}

	int getPosY() {
		return yPos;
	}

	void changePosX(int x) {
		nx = x;
	}

	void changePosY(int y) {
		ny = y;
	}

	int getNX() {
		return nx;
	}

	int getNY() {
		return ny;
	}

	void makeWay(int x, int y, int nx, int ny) {

		c += sqrt(pow((nx - x), 2) + pow((ny - y), 2));
	}

	float getWay() {
		return c;
	}
	
};




int main() {
	Human adam;
	Position x, y, nx, ny, c;
	int xi, yi, nxi, nyi;
	int a;
	int b;
	int steps;
	int age;

	cout << "Enter your age" << "\n";
	cin >> age;
	adam.setAge(age);
	
	x.setPosX(0);
	y.setPosY(0);

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