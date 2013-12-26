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
    
    /*string test = "essai";
    
    for(int i=0; i<test.size(); i++)
    {
        cout << "caractere num" << i << ":" << test.at(i) << endl;
        cout << "\n";
    }*/
    
    
    string test = "essai";
    arbre monArbre;
    noeud *noeudAffichage = monArbre.getRacine();
    
    monArbre.remplirArbre(test);
    
    monArbre.parcourLargeur(noeudAffichage);
    
    return 0;
}

