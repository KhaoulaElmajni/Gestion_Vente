// la structure de données Produit qui définit l'entité produit
typedef struct {
    int code;
    char *designation;
    double prix;
} Produit;

// la structure de données Produit qui définit l'entité produit
typedef struct elementProduit {
    Produit *produit;
    struct elementProduit *next;
} ElementProduit;

// cette fonction va créer et initialiser un élément de la liste chainée des produits
ElementProduit *createNewElementProduit(Produit *produit) {
    ElementProduit *element = (ElementProduit *) malloc(sizeof(ElementProduit));
    element->produit = produit;
    element->next = NULL;
    return element;
}

//cette fonction permet de créer et initialiser un produit
Produit *createNewProduit(int code, char *designation, double prix) {
    Produit *element = (Produit *) malloc(sizeof(Produit));
    element->code = code;
    element->designation = designation;
    element->prix = prix;
    return element;
}


int isElementProduitEmpty(ElementProduit **element) {
    return *element == NULL;
}

//cette fonction pour retourner le dernier élément d'une liste chainée des produits
ElementProduit *lastAdressProd(ElementProduit *L) {
    ElementProduit *elemp;
    if (L == NULL)
        return NULL;
    for (elemp = L; elemp->next != NULL; elemp = elemp->next);
    return elemp;
}

// la fonction void qui permet d'ajouter un produit à la liste chainée
void addProduit(Produit *p, ElementProduit **element) {
    ElementProduit *elementProduit = createNewElementProduit(p);
    if (isElementProduitEmpty(element)) {
        /* Si la liste est vide on ajoute le produit à la liste tt simplement*/
        *element = elementProduit;
    } else {
        /* Sinon, on récupére le dernier élément de la liste est on le relié au nouvel produit */
        lastAdressProd(*element)->next = elementProduit;
    }
}

// la fonction qui permet d'afficher un produit
void displayProduit(Produit *p) {
    printf("\n  %s\t%d\t    %.2f   ", p->designation, p->code, p->prix);
}

// la fonction qui permet d'afficher la liste des produits
void displayProduits(ElementProduit *element) {
    printf("\n______________AFFICHAGE DE LA LISTE DES PRODUITS______________\n");
    printf("_________________________________________\n");
    printf(" Produit    |   Code      |   Prix       |\n");
    printf("____________|_____________|______________|\n");

    while (element != NULL) {
        displayProduit(element->produit);
        printf("\n");
        element = element->next;
    }
}

// la fonction qui permet de rechercher (par code) et retourner un produit s'il existe
Produit *getProduit(int code, ElementProduit *element) {
    ElementProduit *temp = element;
    //Tant que on n'est pas au bout de la liste
    while (temp != NULL) {
        if (temp->produit->code == code) {
            //Si le produit a la valeur recherchée, on renvoie son adresse
            return temp->produit;
        }
        temp = temp->next;
    }
    //s'il n'y a aucun produit avec ce code recherché on renvoie NULL
    return NULL;
}
