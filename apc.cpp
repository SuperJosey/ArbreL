//
//  apc.cpp
//  lexico
//
//  Created by Clément on 24/12/13.
//  Copyright (c) 2013 Clément. All rights reserved.
//

#include "apc.h"
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

arbre::arbre(){
    
    root = creerNoeud('!');
    tempChargementDico=0;
}

arbre::~arbre(){
    
}

noeud *arbre::creerNoeud(char leCar){
 
    noeud *tmp = new noeud;
    
    tmp->caractere=leCar;
    tmp->fg=NULL;
    tmp->fd=NULL;
    
    return tmp;
}


void arbre::remplirA(string leMot){

    noeud *current = root;
    for (int i=0; i<leMot.size(); i++)
    {

        if(current->fg == NULL)
        {
            current->fg=creerNoeud(leMot[i]);
            current=current->fg;
        }
        else
        {

            if(rechercheN(leMot[i], current) != NULL)
            {         
                noeud *tmp = rechercheN(leMot[i], current);
                current = tmp;
                
            }
            else{
                current->fd=creerNoeud(leMot[i]);
                current=current->fd;
        
            }
            
        }
        
    }
    if(current->fg == NULL)
        current->fg = creerNoeud('\0');
    else
    {
        noeud *tmp = creerNoeud('\0');
        tmp->fd = current->fg;
        current->fg = tmp;
    }

    
}


bool arbre::recherche(char car, noeud *niveau){
    
    noeud *current= niveau->fg;
    
    while (current->fd != NULL)
    {
        if(current->caractere == car)
        {
            return true;
        }
        
        current = current->fd;
    }
    
    return false;
    

    
}

noeud *arbre::rechercheN(char car, noeud *niveau){
    
    noeud* tmp = niveau->fg;
    if( tmp->fg != NULL )
    {
        if( tmp->caractere == car )
            return tmp;
        else
        {

            while(tmp->fd != NULL)
            {
                if(tmp->fd->caractere == car )
                    return tmp->fd;
                tmp = tmp->fd;
            }
        }
    }
    return NULL;
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

void arbre::importerDico(){
    
    clock_t debut=clock();
    
    ifstream dico("Gros.txt", ios::in); //ouverture du fichier en lecture
    string ligne;
    
    if(dico){
        
        while(getline(dico,ligne))
        {
            remplirA(ligne);
        }
        
        dico.close();
    }
    else{
        cerr<<"Impossible d'ouvrir le fichier"<<endl;
    }
    
    clock_t fin=clock();
    double temp=(double)(debut-fin)/CLOCKS_PER_SEC * 1000.0;
    setTempD(temp);
}

void arbre::setTempD(double x)
{
    tempChargementDico = x;
}

double arbre::getTempD()
{
    return tempChargementDico;
}
