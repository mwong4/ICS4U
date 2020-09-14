/*
Author: Max Wong
Date Created: September 14, 2020
Date Edited: sep 14, 2020
Purpose: Help mia study for french - present tense conjugasion
*/

#include <iostream>
#include <stdio.h>    //For NULL (srand)
#include <stdlib.h>   //For srand, rand
#include <time.h>     //For time

using namespace std;

int main()
{
    srand (time(NULL)); //Randomize seed according to time

    //Data
    string pronouns[6] = {"Je", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"};

    string verbs[19] = {"�crire", "Venir", "Faire", "R�soudre", "Dire", "Conna�tre", "Prendre", "Recevoir", "Envoyer", "Offrir", "Ouvrir", "Apprendre", "Tenir", "Jeter", "Appeler", "Acheter", "Valoir", "Vivre", "Courir"};

    string v1p[6] = {"�cris", "�cris", "�crit", "�crivons", "�crivez", "�crivent"};
    string v2p[6] = {"viens", "viens", "vient", "venons", "venez", "viennent"};
    string v3p[6] = {"fais", "fais", "fait", "faisons", "faites", "font"};
    string v4p[6] = {"r�sous", "r�sous", "r�sout", "r�solvons", "r�solvez", "r�solvent"};
    string v5p[6] = {"dis", "dis", "dit", "disons", "dites", "disent"};
    string v6p[6] = {"connais", "connais", "conna�t", "connaissons", "connaissez", "connaissent"};
    string v7p[6] = {"prends", "prends", "prend", "prenons", "prenez", "prennent"};
    string v8p[6] = {"re�ois", "re�ois", "re�oit", "recevons", "recevez", "re�oivent"};
    string v9p[6] = {"envoie", "envoies", "envoie", "envoyons", "envoyez", "envoient"};
    string v10p[6] = {"offre", "offres", "offre", "offrons", "offrez", "offrent"};
    string v11p[6] = {"ouvre", "ouvres", "ouvre", "ouvrons", "ouvrez", "ouvrent"};
    string v12p[6] = {"apprends", "apprends", "apprend", "apprenons", "apprenez", "apprennent"};
    string v13p[6] = {"tiens", "tiens", "tient", "tenons", "tenez", "tiennent"};
    string v14p[6] = {"jette", "jettes", "jette", "jetons", "jetez", "jettent"};
    string v15p[6] = {"appelle", "appelles", "appelle", "appelons", "appelez", "appellent"};
    string v16p[6] = {"ach�te", "ach�tes", "ach�te", "achetons", "achetez", "ach�tent"};
    string v17p[6] = {"vaux", "vaux", "vaut", "valons", "valez", "valent"};
    string v18p[6] = {"vis", "vis", "vit", "vivons", "vivez", "vivent"};
    string v19p[6] = {"cours", "cours", "court", "courons", "courez", "courent"};

    int randomPronoun = 0;
    int randomVerb = 0;

    string answers[15] = {};

    //generate questions and answers
    for(int i = 0; i < 15; i++)
    {
        randomPronoun = rand() % 6; //Randomize
        randomVerb = rand() % 19;

        cout << "  " << pronouns[randomPronoun] << " " << verbs[randomVerb] << endl;

        //Save answers
        if(randomVerb == 0)
        {
            answers[i] = v1p[randomPronoun];
        }
        else if(randomVerb == 1)
        {
            answers[i] = v2p[randomPronoun];
        }
        else if(randomVerb == 2)
        {
            answers[i] = v3p[randomPronoun];
        }
        else if(randomVerb == 3)
        {
            answers[i] = v4p[randomPronoun];
        }
        else if(randomVerb == 4)
        {
            answers[i] = v5p[randomPronoun];
        }
        else if(randomVerb == 5)
        {
            answers[i] = v6p[randomPronoun];
        }
        else if(randomVerb == 6)
        {
            answers[i] = v7p[randomPronoun];
        }
        else if(randomVerb == 7)
        {
            answers[i] = v8p[randomPronoun];
        }
        else if(randomVerb == 8)
        {
            answers[i] = v9p[randomPronoun];
        }
        else if(randomVerb == 9)
        {
            answers[i] = v10p[randomPronoun];
        }
        else if(randomVerb == 10)
        {
            answers[i] = v11p[randomPronoun];
        }
        else if(randomVerb == 11)
        {
            answers[i] = v12p[randomPronoun];
        }
        else if(randomVerb == 12)
        {
            answers[i] = v13p[randomPronoun];
        }
        else if(randomVerb == 13)
        {
            answers[i] = v14p[randomPronoun];
        }
        else if(randomVerb == 14)
        {
            answers[i] = v15p[randomPronoun];
        }
        else if(randomVerb == 15)
        {
            answers[i] = v16p[randomPronoun];
        }
        else if(randomVerb == 16)
        {
            answers[i] = v17p[randomPronoun];
        }
        else if(randomVerb == 17)
        {
            answers[i] = v18p[randomPronoun];
        }
        else if(randomVerb == 18)
        {
            answers[i] = v19p[randomPronoun];
        }
    }

    cout << endl << "Press any key twice to get answers" << endl;
    system("Pause");
    system("Pause");

    //Display answers
    cout << endl;
    for(int i = 0; i < 15; i++)
    {
        cout << "  " << answers[i] << endl;
    }

    return 0;
}
