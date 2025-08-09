#include <iostream>
using namespace std;

/*
    Illustration d'arbre binaire (simple).
    2020 Newen
    2025 Newen
*/

struct Node
{
    int data;
    struct std::unique_ptr<Node> left;
    struct std::unique_ptr<Node> right;

    /*
        Une structure peut également intégrer un ou plusieurs constructeurs.
        Les nodes à gauche et à droite doivent être initialisés à NULL.

        Dans ce cas ci, le constructeur prend un entier en paramètre et initialise un premier noeud avec cette valeur.
    */

    Node(int val) : data(val), left(nullptr), right(nullptr)
    {

    }
};

void add(std::unique_ptr<Node>& node, int val)
{

    if (node == nullptr)
    {
        node = std::make_unique<Node>(val);
        return;
	}

    if (val < node->data) add(node->left, val);
    else add(node->right, val);
}

/*
* Ce parcours affiche les valeurs triées par ordre croissant.
*/
void browseInorder(std::unique_ptr<Node>& node)
{
    if (node == nullptr) return;

    browseInorder(node->left);

    cout << node->data << " ";

    browseInorder(node->right);
}

/*
* Ce parcours affiche les valeurs dans l'ordre de leur insertion.
*/
void browsePreorder(std::unique_ptr<Node>& node)
{
    if (node == nullptr) return;

    cout << node->data << " ";

    browsePreorder(node->left);
    browsePreorder(node->right);
}

/*
* Ce parcours affiche les valeurs dans l'ordre inverse de leur insertion.
* Très utile pour nettoyer les feuilles d'un arbre et donc libérer de la mémoire.
*/
void browsePostorder(std::unique_ptr<Node>& node)
{
    if (node == nullptr) return;

    browsePostorder(node->left);
    browsePostorder(node->right);

    cout << node->data << " ";
}

int main()
{
    cout << "Initialisation des donnees post-vectorielles patientez un instant..." << endl;

    struct std::unique_ptr<Node> root = std::make_unique<Node>(1);
    /*
        Arbre :
        1
       / \
      N   N
    */

	root->left = std::make_unique<Node>(2);
    root->right = std::make_unique<Node>(7);

    /*
        Arbre :
            1
           / \
          2   7
         / \ / \
        N  N N  N
    */

    root->left->left = std::make_unique<Node>(9);

    /*
        Suffisamment explicite désormais n'est ce pas ?
        Le Noeud (9) occupera le noeud gauche du Noeud (2).
    */

    // Traversée Infixe.
    browseInorder(root);

    cout << endl;

    // Traversée Prefixe.
    browsePreorder(root);

    cout << endl;

    // Traversée Postfixe.
    browsePostorder(root);

    cout << endl;

    add(root, 42);

    /*
        Désormais...
        Attention 7 et 42 disposent eux aussi de leur noeud de gauche et de droite initialisés à null (non représenté ci-dessous).
            1
           / \
          2   7
         / \
        9   42
       / \
      N   N
    */

    browsePreorder(root);

    return 0;
}