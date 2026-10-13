
class Angle {
private:
    int degrees_;
    int minutes_;
    float tg;

    void normalize();

public:

    Angle(int degrees = 0, int minutes = 0 );
    Angle(float tg, int minutes);
    
    int getDegrees() const;
    int getMinutes() const;
    int toTotalMinutes() const;

    double toRadians() const;
    float getSin() const;
    float getCos() const;

    bool operator==(const Angle& other) const;
    bool operator!=(const Angle& other) const;
    bool operator<(const Angle& other) const;
    bool operator>(const Angle& other) const;
    bool operator<=(const Angle& other) const;
    bool operator>=(const Angle& other) const;

    Angle& operator+=(const Angle& other);
    Angle& operator-=(const Angle& other);
    Angle operator+(const Angle& other);
    Angle operator*(double number) const;
    Angle operator/(double number) const;

    void printAngle() const;
    void createAngle();
    void setDegrees(int degres);
    void setMinutes(int minutes);
    
};