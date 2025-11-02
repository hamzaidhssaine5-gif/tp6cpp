#include <iostream>
using namespace std;

class Compte {
protected:
    int numero;
    double solde;

public:
    Compte(int n, double s) : numero(n), solde(s) {}

    void deposer(double montant) {
        solde += montant;
    }

    void retirer(double montant) {
        if (montant <= solde)
            solde -= montant;
        else
            cout << "Solde insuffisant." << endl;
    }

    void afficher() {
        cout << "Compte N°" << numero << " | Solde : " << solde << " DH" << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(int n, double s, double taux) : Compte(n, s), tauxInteret(taux) {}

    void calculerInteret() {
        double interet = solde * tauxInteret / 100;
        solde += interet;
    }

    void afficher() {
        cout << "Compte Épargne N°" << numero 
             << " | Solde : " << solde 
             << " DH | Taux : " << tauxInteret << "%" << endl;
    }
};

int main() {
    CompteEpargne c1(12345, 1000.0, 3.5);
    c1.deposer(500);
    c1.retirer(200);
    c1.calculerInteret();
    c1.afficher();

    return 0;
}
