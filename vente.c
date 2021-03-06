
// la structure de donn?es Vente qui d?finit l'entit? vente
typedef struct {
    int numero;
    char *date;
    Client *client;
    ElementLc *elementLc;
    double total;
} Vente;

//la structure de donn?es elementVente qui d?finit la liste chain?e des ventes
typedef struct elementVente {
    Vente *vente;
    struct elementVente *next;
} ElementVente;

Vente *createVente(Vente *vente, ElementClient *element) {
    int codeClt;
    if (vente == NULL) {
        vente = (Vente *) malloc(sizeof(Vente));
        vente->total = 0;
        vente->date = malloc(sizeof(char) * 20);
        vente->elementLc = NULL;
    }

    printf("\n\nVeuillez saisir le numero de la vente:");
    scanf("%d", &(vente->numero));
    printf("\n\nVeuillez saisir la date de la vente comme suit (dd/MM/yyyy): ");
    scanf("%s", vente->date);
    printf("\n\nVeuillez saisir le code de client: ");
    scanf("%d", &codeClt);
    Client *client = getClient(codeClt, element);
    if (client != NULL) {
        vente->client = client;
        return vente;
    } else {
        printf("Le numero du client que vous avez entre n\'existe pas!!!");
        exit(1);
    }
}

//cette fonction va cr?e et initialiser un ?l?ment de la liste chain??e des ventes
ElementVente *createNewElementVente(Vente *vente) {
    ElementVente *element = (ElementVente *) malloc(sizeof(ElementVente));
    element->vente = vente;
    element->next = NULL;
    return element;
}

//cette fonction pour retourner le dernier ?l?ment d'une liste chain?e des ventes
ElementVente *lastAdressVente(ElementVente *LCVente) {
    ElementVente *elemLcVente;
    if (LCVente == NULL) return NULL;
    elemLcVente = LCVente;
    for (; elemLcVente->next != NULL; elemLcVente = elemLcVente->next);
    return elemLcVente;
}

// la fonction qui permet de cr?er une ligne de commande et l'ajouter ?
//liste des lignes de commande de la vente
Vente *addLcToVente(Vente *vente, Produit *p, int qte) {
    if (p != NULL) {
        Lc *ligne = (Lc *) malloc(sizeof(Lc));
        ligne->produit = p;
        ligne->quantite = qte;
        ligne->total = qte * p->prix;
        addLc(ligne, &(vente->elementLc));
        return vente;
    } else {
        printf("Le numero du produit vez entre n\'existe pas !!!\n");
        exit(1);
    }
}

int isElementVenteEmpty(ElementVente **element) {
    return *element == NULL;
}

//la fonction void qui permet d'ajouter un ?l?ment du vente ? la liste chain?e
void addVente(Vente *vente, ElementVente **element) {
    ElementVente *elementVente = createNewElementVente(vente);
    if (isElementVenteEmpty(element)) {
        /* Si la liste est vide on ajoute le client ? la liste simplement*/
        *element = elementVente;
    } else {
        /* Sinon, on r?cup?re le dernier ?l?ment de la liste est on le reli? au nouvel produit */
        lastAdressVente(*element)->next = elementVente;
    }
}

/*
 *D?finir la fonction qui permet d'afficher les d?tails d'une vente
 */
void displayVente(Vente *vente) {
    printf("\n\n___________________Les details de la vente sont :____________________\n\n");

    printf("La vente {\n\tNumero : %d;\n\tDate : %s;\n\tLe client :  ", vente->numero, vente->date);
    displayClient(vente->client);
    //printf("\nICIIIII\n");
    printf("\n\tLes lignes de commandes : {\n\t");
    displayLcs(vente->elementLc);
    printf("\n\t}\n\n\tTOTAL : %.3f;\n\t\t\t}", vente->total);

}

void displayVentes(ElementVente *element) {
    int i;
    printf("\n______________AFFICHAGE DE LA LISTE DES VENTES______________\n");
    printf("_______________________________________________\n");

    while (element != NULL) {
        printf("\n\n_________________________Les details du %d vente comme suit :____________________________\n\n", i);
        displayVente(element->vente);
        i++;
        element = element->next;
    }
}
