#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    int age;

public:
    Personne(string n, int a) : nom(n), age(a) {}

    void afficher() {
        cout << "Nom : " << nom << ", Âge : " << age << " ans" << endl;
    }
};

class Etudiant : public Personne {
private:
    string niveau;

public:
    Etudiant(string n, int a, string niv) : Personne(n, a), niveau(niv) {}

    void afficher() {
        cout << "Nom : " << nom 
             << ", Âge : " << age << " ans"
             << ", Niveau : " << niveau << endl;
    }
};

int main() {
    Etudiant e1("Hamza Idhssaine", 20, "2ème année Informatique");
    e1.afficher();

    return 0;
}
