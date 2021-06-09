// la structure de données Lc qui définit l'entité ligne de commande
typedef struct {
    Produit *produit;
    int quantite;
    double total;
} Lc;

// la structure de données ElementLc pour gérer la liste chainée des lignes de commandes
typedef struct elementLc {
    Lc *lc;
    struct elementLc *next;
} ElementLc;

// cette fonction va crée et initialiser un élément de la liste chainé des lignes de commandes
ElementLc *createNewElementLc(Lc *lc) {
    ElementLc *element = (ElementLc *) malloc(sizeof(ElementLc));
    element->lc = lc;
    element->next = NULL;
    return element;
}

int isElementLcEmpty(ElementLc **element) {
    return *element == NULL;
}

//cette fonction pour retourner le dernier élément d'une liste chainée des lignes de commandes
ElementLc *lastAdressLc(ElementLc *L) {
    ElementLc *elemLc;
    if (L == NULL) return NULL;
    for (elemLc = L; elemLc->next != NULL; elemLc = elemLc->next);
    return elemLc;
}

// la fonction qui permet d'ajouter une ligne de commande à la liste chainée
void addLc(Lc *lc, ElementLc **element) {
    ElementLc *elementLc = createNewElementLc(lc);
    if (isElementLcEmpty(element)) {
        /* Si la liste est vide on ajoute le client à la liste simplement*/
        *element = elementLc;
    } else {
        /* Sinon, on récupée le dernier élément de la liste est on le relié au nouvel produit */
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
