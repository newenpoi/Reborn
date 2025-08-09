#include <iostream>
#include <vector>

using namespace std;

double average(vector<int>& scores)
{
    double moyenne(0);

    for (int i(0); i < scores.size(); ++i)
    {
        moyenne += scores[i];
    }

    moyenne /= scores.size();

    return moyenne;
}

int main()
{
    /*
        Instanciation d'un vecteur (qui est un modèle de classe) de taille 5 et pour données 0.
        La constante size contient la taille (fixe dans notre cas) de notre vecteur.
    */

    vector<int> scores(5, 0);
    int const size(scores.size());

    scores[0] = 125;
    scores[1] = 180;
    scores[2] = 650;
    scores[3] = 950;
    scores[4] = 150;

    cout << "The average score is : " << average(scores) << endl;

    return 0;
}