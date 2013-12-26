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

using namespace std;

struct noeud {
  
    char caractere;
    noeud *fg;
    noeud *fd;
    
};


class arbre {
  
    
private:
    noeud *root;

    
public:
    arbre();
    ~arbre();
    noeud *creerNoeud(char leCar);
    void remplirArbre(string leMot);
    void afficherRacine(noeud *a); //Methode d'affichage de la racine
    void parcourLargeur(noeud *a);
    void afficherNoeud(noeud *a);
    noeud *parseur(string leMot); //Transforme une chaine en plusieur noeud
    noeud *getRacine(); //Acesseur sur racine 
};





#endif /* defined(__lexico__apc__) */
