//
//  main.cpp
//  lexico
//
//  Created by Clément on 24/12/13.
//  Copyright (c) 2013 Clément. All rights reserved.
//

#include <iostream>
#include "apc.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    //Test manuel:
    /*
    string test = "test";
    string test2 = "tete";
    
    arbre monArbre;
    noeud *noeudAffichage = monArbre.getRacine();
    

    monArbre.remplirA(test);
    monArbre.remplirA(test2);
    
    monArbre.parcourLargeur(noeudAffichage);
    */
    arbre monArbre;
    
    cout<<"Debut de l'importation du dictionaire dans l'arbre lexicographique:"<<endl;
    
    monArbre.importerDico();
    
    cout<<"Le chargement s'effectue en:"<<monArbre.getTempD()<<" secondes"<<endl;
    
    
    
    return 0;
}

