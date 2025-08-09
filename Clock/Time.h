#pragma once

#include <iosfwd> 

class Time
{
public:

    Time();
    Time(int seconds);
    Time(int hours, int minutes, int seconds);

    /*
        Explication de friend avec des opérateurs de surcharge.
        Méthode aux privilèges spéciaux permettant l'accès aux membres privés d'une même classe ami.
		Ceci est utile pour les opérateurs de comparaison et d'addition, car ils doivent accéder aux membres privés de la classe Time.

        TODO : Constructeurs par défaut avec `default`.
    */

    friend bool operator==(Time const& a, Time const& b);
    friend bool operator!=(Time const& a, Time const& b);
    friend bool operator<(Time const& a, Time const& b);

    friend Time operator+(Time const& a, Time const& b);
    friend Time operator+(Time const& a, int seconds);

    Time& operator+=(const Time& a);
    Time& operator+=(int seconds);

    friend std::ostream& operator<<(std::ostream& stream, Time const& a);

    Time add(Time time) const;
    void show() const;
    void show(std::ostream& stream) const;

private:

    int m_iHours;
    int m_iMinutes;
    int m_iSeconds;
};