// la structure de donn?es Lc qui d?finit l'entit? ligne de commande
typedef struct {
    Produit *produit;
    int quantite;
    double total;
} Lc;

// la structure de donn?es ElementLc pour g?rer la liste chain?e des lignes de commandes
typedef struct elementLc {
    Lc *lc;
    struct elementLc *next;
} ElementLc;

// cette fonction va cr?e et initialiser un ?l?ment de la liste chain? des lignes de commandes
ElementLc *createNewElementLc(Lc *lc) {
    ElementLc *element = (ElementLc *) malloc(sizeof(ElementLc));
    element->lc = lc;
    element->next = NULL;
    return element;
}

int isElementLcEmpty(ElementLc **element) {
    return *element == NULL;
}

//cette fonction pour retourner le dernier ?l?ment d'une liste chain?e des lignes de commandes
ElementLc *lastAdressLc(ElementLc *L) {
    ElementLc *elemLc;
    if (L == NULL) return NULL;
    for (elemLc = L; elemLc->next != NULL; elemLc = elemLc->next);
    return elemLc;
}

// la fonction qui permet d'ajouter une ligne de commande ? la liste chain?e
void addLc(Lc *lc, ElementLc **element) {
    ElementLc *elementLc = createNewElementLc(lc);
    if (isElementLcEmpty(element)) {
        /* Si la liste est vide on ajoute le client ? la liste simplement*/
        *element = elementLc;
    } else {
        /* Sinon, on r?cup?e le dernier ?l?ment de la liste est on le reli? au nouvel produit */
        lastAdressLc(*element)->next = elementLc;
    }
}


// la fonction qui permet d'afficher une ligne de commande
void displayLC(Lc *lc) {
    displayProduit(lc->produit);
    printf("\t %d\t\t %.2f", lc->quantite, lc->total);
}


// la fonction qui permet d'afficher la liste des lignes de commandes
void displayLcs(ElementLc *element) {
    printf("\n______________AFFICHAGE DE LA LISTE DES LIGNES DE COMMANDES______________\n");
    printf("_____________________________________________________________________\n");
    printf(" Produit    \t\t\t     |   Quantite   |   Total        |\n");
    printf("_____________________________________|______________|________________|\n");
    while (element != NULL) {
        displayLC(element->lc);
        element = element->next;
    }
}
