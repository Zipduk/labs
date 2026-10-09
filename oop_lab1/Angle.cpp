#include <iostream>

#include "Angle.h"
#include <cmath>

const int MINUTES_PER_DEGREE = 60;
const int MINUTES_PER_CIRCLE = 360 * MINUTES_PER_DEGREE;
const double PI = 3.14159265358979323846;

int Angle::toTotalMinutes() const {
	return degrees_ * 60 + minutes_;
}

bool Angle::operator==(const Angle& other) const {
	return toTotalMinutes() == other.toTotalMinutes();
}

bool Angle::operator!=(const Angle& other) const {
	return !(*this == other);
}

bool Angle::operator<(const Angle& other) const {
	return toTotalMinutes() < other.toTotalMinutes();
}

bool Angle::operator>(const Angle& other) const {
	return toTotalMinutes() > other.toTotalMinutes();
}

bool Angle::operator<=(const Angle& other) const {
	return !(*this > other);
}

bool Angle::operator>=(const Angle& other) const {
	return !(*this < other);
}

Angle& Angle::operator+=(const Angle& other) {
	degrees_ += other.degrees_;
	minutes_ += other.minutes_;
	normalize();

	return *this;
}

Angle Angle::operator+(const Angle& other) {
	Angle result = *this; 
	result += other;
	normalize();
	return result;        
}

Angle Angle::operator/(double number) const {
	int newTotalMinutes = std::round(toTotalMinutes() / number);

	return Angle(0, static_cast<int>(newTotalMinutes));
}

Angle Angle::operator*(double number) const {
	int newTotalMinutes = std::round(toTotalMinutes() * number);

	return Angle(0, static_cast<int>(newTotalMinutes));
}

Angle& Angle::operator-=(const Angle& other) {
	degrees_ -= other.degrees_;
	minutes_ -= other.minutes_;
	normalize();

	return *this;
}

void Angle::normalize() {
	int totalMinutes = degrees_ * MINUTES_PER_DEGREE + minutes_;

	totalMinutes = (totalMinutes % MINUTES_PER_CIRCLE + MINUTES_PER_CIRCLE) % MINUTES_PER_CIRCLE;

	degrees_ = totalMinutes / MINUTES_PER_DEGREE;
	minutes_ = totalMinutes % MINUTES_PER_DEGREE;
}

Angle::Angle(int degrees, int minutes) : degrees_(degrees), minutes_(minutes) {
	normalize();
}

double Angle::toRadians() const {
	double totalDegrees = degrees_ + (static_cast<double>(minutes_) / 60.0);

	return totalDegrees * (PI/180.0);
}

float Angle::getCos() const{
	return std::cos(toRadians());
}

float Angle::getSin() const {
	return std::sin(toRadians());
}

int Angle::getDegrees() const {
	return degrees_;
}

int Angle::getMinutes() const {
	return minutes_;
}

void Angle::setDegrees(int degrees) {
	degrees_ = degrees;
	normalize(); 
}

void Angle::setMinutes(int minutes) {
	minutes_ = minutes;
	normalize();
}

Angle Angle::createAngle() {
	int degrees, minutes;
	std::cout << "enter degrees angle: ";
	std::cin >> degrees;
	std::cout << "enter minutess angle: ";
	std::cin >> minutes;

	return Angle(degrees, minutes);
}

void Angle::printAngle() const{
	std::cout << "degrees: " << degrees_ << " minutes: " << minutes_;
}