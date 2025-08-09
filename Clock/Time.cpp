#include "Time.h"
#include <iostream>
#include <tuple>

using namespace std;

Time::Time() : m_iHours(0), m_iMinutes(0), m_iSeconds(0)
{

}

Time::Time(int seconds) : m_iSeconds(seconds)
{
    /*
        Le nombre d'heures est �gal au total de minutes (seconds / 60) / 60.
        Le nombre de minutes est le reste de la division euclidienne du total de minutes (seconds / 60) / 60.
        Le nombre de secondes est le reste de la division euclidienne du total de secondes / 60.
    */

    m_iHours = (seconds / 60) / 60;
    m_iMinutes = (seconds / 60) % 60;
    m_iSeconds = seconds % 60;
}

Time::Time(int hours, int minutes, int seconds) : m_iHours(hours), m_iMinutes(minutes), m_iSeconds(seconds)
{

}

bool operator==(Time const& a, Time const& b)
{
    return a.m_iHours == b.m_iHours && a.m_iMinutes == b.m_iMinutes && a.m_iSeconds == b.m_iSeconds;
}

bool operator!=(Time const& a, Time const& b)
{
    // On a pr�c�demment d�fini notre surcharge d'op�rateur.

    return !(a == b);
}

bool operator<(Time const& a, Time const& b)
{
    // Je vais me servir de la magie du tuple (C++ 14) afin d'ex�cuter la comparaison.
    // https://en.cppreference.com/w/cpp/utility/tuple/tie

    return tie(a.m_iHours, a.m_iMinutes, a.m_iSeconds) < tie(b.m_iHours, b.m_iMinutes, b.m_iSeconds);
}

Time operator+(Time const& a, Time const& b)
{
    /*
        Sur cette surcharge d'op�rateur je vais cr�er une copie (un dummy) d'une dur�e o� le r�sultat sera l'addition de A et B (m�thode add) sans avoir � modifier notre instance.
		Autrement, si on modifiait l'instance, on aurait un probl�me de const-correctness.
    */

    Time copy;
    copy = a.add(b);

    return copy;
}

Time operator+(Time const& a, int seconds)
{
    Time copy(a);
    copy += seconds;

    return copy;
}

Time& Time::operator+=(const Time& a)
{
    /*
        Renvoie une r�f�rence sur un Time (Dur�e).
    */

    int seconds = (a.m_iHours * 3600) + (a.m_iMinutes * 60) + a.m_iSeconds;
    seconds += (m_iHours * 3600) + (m_iMinutes * 60) + m_iSeconds;

    m_iHours = (seconds / 60) / 60;
    m_iMinutes = (seconds / 60) % 60;
    m_iSeconds = seconds % 60;

	// On renvoie une r�f�rence sur l'instance courante.
    return *this;
}

Time& Time::operator+=(int seconds)
{
    /*
        Renvoie une r�f�rence sur une Dur�e apr�s avoir ajout� les secondes.
    */

    seconds += (m_iHours * 3600) + (m_iMinutes * 60) + m_iSeconds;

    m_iHours = (seconds / 60) / 60;
    m_iMinutes = (seconds / 60) % 60;
    m_iSeconds = seconds % 60;

    return *this;
}

ostream& operator<<(ostream& stream, Time const& duration)
{
    duration.show(stream);
    return stream;
}

Time Time::add(Time time) const
{
    /*
        Additionne deux temps et le renvoie.
    */

    int seconds = (time.m_iHours * 3600) + (time.m_iMinutes * 60) + time.m_iSeconds;
    seconds += (m_iHours * 3600) + (m_iMinutes * 60) + m_iSeconds;

    time.m_iHours = (seconds / 60) / 60;
    time.m_iMinutes = (seconds / 60) % 60;
    time.m_iSeconds = seconds % 60;

    return time;
}

void Time::show() const
{
    cout << "Hours : " << m_iHours << endl;
    cout << "Minutes : " << m_iMinutes << endl;
    cout << "Seconds : " << m_iSeconds << endl;
}

void Time::show(ostream& stream) const
{
    /*
        Permet de passer directement par le flux.
    */

    stream << m_iHours << ':' << m_iMinutes << ':' << m_iSeconds << endl;
}