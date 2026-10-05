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

void Angle::normalize() {

	int totalMinutes = degrees_ * MINUTES_PER_DEGREE + minutes_;
	degrees_ = static_cast<int>(totalMinutes / MINUTES_PER_DEGREE);
	minutes_ = static_cast<int>(totalMinutes % MINUTES_PER_DEGREE);

	}

Angle::Angle(int degrees, int minutes) : degrees_(degrees), minutes_(minutes) {
	normalize();
}

double Angle::toRadians() const {
	double totalDegrees = degrees_ + (static_cast<double>(minutes_) / 60.0);

	return totalDegrees * (PI/180.0);
}

double Angle::getCos() const{
	return std::cos(toRadians());
}

double Angle::getSin() const {
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