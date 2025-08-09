#pragma once

#include <iosfwd> 

class Time
{
public:

    Time();
    Time(int seconds);
    Time(int hours, int minutes, int seconds);

    /*
        Explication de friend avec des op�rateurs de surcharge.
        M�thode aux privil�ges sp�ciaux permettant l'acc�s aux membres priv�s d'une m�me classe ami.
		Ceci est utile pour les op�rateurs de comparaison et d'addition, car ils doivent acc�der aux membres priv�s de la classe Time.

        TODO : Constructeurs par d�faut avec `default`.
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