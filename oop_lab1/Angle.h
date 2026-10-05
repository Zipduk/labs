
class Angle {
private:
    int degrees_;
    int minutes_;

    void normalize();

public:

    Angle(int degrees = 0, int minutes = 0);

    int getDegrees() const;
    int getMinutes() const;
    int toTotalMinutes() const;

    double toRadians() const;
    double getSin() const;
    double getCos() const;

    bool operator==(const Angle& other) const;
    bool operator!=(const Angle& other) const;
    bool operator<(const Angle& other) const;
    bool operator>(const Angle& other) const;
    bool operator<=(const Angle& other) const;
    bool operator>=(const Angle& other) const;

    Angle& operator+=(const Angle& other);
    Angle& operator-=(const Angle& other);

    void setDegrees(int degres);
    void setMinutes(int minutes);
};