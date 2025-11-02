#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(const string& n, int i, float salaire)
        : nom(n), id(i), salaireDeBase(salaire) {}

    virtual void afficherInfos() const {
        cout << "Employé ID: " << id << ", Nom: " << nom
             << ", Salaire de base: " << salaireDeBase << " EUR" << endl;
    }

    virtual ~Employe() {
        cout << "Destruction de l'employé " << nom << endl;
    }
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(const string& n, int i, float salaire, float prime)
        : Employe(n, i, salaire), primeAnnuelle(prime) {}

    void afficherInfos() const override {
        Employe::afficherInfos();
        cout << "Prime annuelle : " << primeAnnuelle << " EUR" << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(const string& n, int i, float salaire, int duree, float taux)
        : Employe(n, i, salaire), dureeContrat(duree), tauxHoraire(taux) {}

    float calculerSalaireMensuel(int heures) const {
        return tauxHoraire * heures;
    }

    void afficherInfos() const override {
        Employe::afficherInfos();
        cout << "Durée contrat : " << dureeContrat << " mois"
             << ", Taux horaire : " << tauxHoraire << " EUR" << endl;
    }
};

int main() {
    Employe* equipe[3];

    equipe[0] = new Permanent("Alice", 101, 3000.0f, 1500.0f);
    equipe[1] = new Contractuel("Bob", 102, 0.0f, 6, 20.0f);
    equipe[2] = new Permanent("Charlie", 103, 3200.0f, 1200.0f);

    for (int i = 0; i < 3; i++) {
        equipe[i]->afficherInfos();
        if (Contractuel* c = dynamic_cast<Contractuel*>(equipe[i])) {
            cout << "Salaire mensuel pour 160h: "
                 << c->calculerSalaireMensuel(160) << " EUR" << endl;
        }
        cout << "-----------------------" << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete equipe[i];
    }

    return 0;
}
