//
//  apc.cpp
//  lexico
//
//  Created by Clément on 24/12/13.
//  Copyright (c) 2013 Clément. All rights reserved.
//

#include "apc.h"
#include <queue>

using namespace std;

arbre::arbre(){
    
    root = creerNoeud('!');

}

arbre::~arbre(){
    //detruire si dynamique
}

noeud *arbre::creerNoeud(char leCar){
 
    noeud *tmp = new noeud;
    
    tmp->caractere=leCar;
    tmp->fg=NULL;
    tmp->fd=NULL;
    
    return tmp;
}

void arbre::remplirArbre(string leMot){
    
    if(root->fg == NULL){
        
        root->fg = parseur(leMot);//On insere le premier noeud (1er carac du mot)
    }
    //Sinon on parcour l'arbre pour verifier si le noeud n'existe pas au meme niveau (largeur)
        //si le caractere nexiste pas on creer un nouveau noeud (avec edition des lien fg fd)
        //sinon on passe au caractere suivant et on descend de un niveau pour parcourir l'arbe en largeur
}

void arbre::parcourLargeur(noeud *a){
    
    queue <noeud*> file;
    noeud *tmp = new noeud;
    
    file.push(a);
    
    while (!file.empty()) {
        
        tmp=file.front();
        file.pop();
        afficherNoeud(tmp); //ou tout autre action
            if(tmp->fd != NULL)
            {
                file.push(tmp->fd);
            }
            if(tmp->fg != NULL)
            {
                file.push(tmp->fg);
            }
    }
}

noeud *arbre::parseur(string leMot){
    
    noeud *tmp = new noeud;
    
    for(int i=0; i<leMot.size(); i++)
    {
        return tmp=creerNoeud(leMot.at(i));
    }
    
    return NULL;
}

noeud *arbre::getRacine(){
    
    return root;
}

void arbre::afficherNoeud(noeud *a){
    
    cout<<"Le caractere est :"<< a->caractere << endl;
    
}

void arbre::afficherRacine(noeud *a){
    
    queue <noeud*> q;
    q.push(a);
    
    noeud *tmp = new noeud;
    
    tmp=q.front();
    
    cout<<"afficher premier element:"<< tmp->caractere <<endl;
    
    delete tmp;
}

