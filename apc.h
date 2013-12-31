//
//  apc.h
//  lexico
//
//  Created by Clément on 24/12/13.
//  Copyright (c) 2013 Clément. All rights reserved.
//

#ifndef __lexico__apc__
#define __lexico__apc__

#include <iostream>
#include <queue>

using namespace std;

struct noeud {
  
    char caractere;
    noeud *fg;
    noeud *fd;
    
};


class arbre {
  
    
private:
    noeud *root;
    double tempChargementDico;
    
public:
    arbre();
    ~arbre();
    noeud *creerNoeud(char leCar); //Methode de creation de noeud global
    void afficherRacine(noeud *a);
    void parcourLargeur(noeud *a); 
    void afficherNoeud(noeud *a);
    noeud *getRacine();      //Accesseur sur racine
    double getTempD();       //Accesseur sur tempChargementDico
    void setTempD(double x); //Mutateur sur tempChargementDico
    void remplirA(string leMot); //Remplis l'arbre en fonction de la chaine fournis
    bool recherche(char car, noeud *niveau); //Renvoie true si matching
    noeud *rechercheN(char car, noeud *niveau); //Renvois le noeud si matching
    void importerDico(); 
    
};





#endif /* defined(__lexico__apc__) */
