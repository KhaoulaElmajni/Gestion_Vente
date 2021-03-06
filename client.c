//1__________________________D?finir les ?l?ments n?cessaires pour la gestion des clients______________________________________________

// la structure de donn?es Client qui d?finit l'entit? client
typedef struct {
    int numero;
    char *nom;
    char *prenom;
} Client;

// la structure de donn?s ElementClient pour g?rer la liste chain?e des clients
typedef struct elementClient {
    Client *client;
    struct elementClient *next;
} ElementClient;

//cette fonction permet de cr?er et initialiser un client
Client *createNewClient(int numero, char *nom, char *prenom) {
    Client *element = (Client *) malloc(sizeof(Client));
    element->numero = numero;
    element->nom = nom;
    element->prenom = prenom;
    return element;
}

// cette fonction va cr?e et initialiser un ?l?ment de la liste chain?e des clients
ElementClient *createNewElementClient(Client *client) {
    ElementClient *element = (ElementClient *) malloc(sizeof(ElementClient));
    element->client = client;
    element->next = NULL;
    return element;
}

int isElementClientEmpty(ElementClient **element) {
    return *element == NULL;
}

//cette fonction pour retourner le dernier ?l?ment d'une liste chain?e des clients
ElementClient *lastAdressClt(ElementClient *L) {
    ElementClient *elemClt;
    if (L == NULL)
        return NULL;
    for (elemClt = L; elemClt->next != NULL; elemClt = elemClt->next);
    return elemClt;
}

//la fonction void qui permet d'ajouter un client ? la liste chain?e
void addClient(Client *c, ElementClient **element) {
    ElementClient *elementClient = createNewElementClient(c);
    if (isElementClientEmpty(element)) {
        *element = elementClient;
    } else {
        lastAdressClt(*element)->next = elementClient;
    }
}

// la fonction qui permet d'afficher un client
void displayClient(Client *c) {
    printf("\n\t%d \t%s \t%s \n", c->numero, c->nom, c->prenom);
}

// la fonction qui permet d'afficher la liste des clients
void displayClients(ElementClient *L) {
    printf("\n______________AFFICHAGE DE LA LISTE DES CLIENTS______________\n");
    printf("_______________________________________________\n");
    printf(" Numero    |      Nom         |   Prenom       |\n");
    printf("___________|__________________|________________|\n");
    while (L != NULL) {
        displayClient(L->client);
        L = L->next;
    }
}

Client *getClient(int num, ElementClient *element) {
    ElementClient *temp = element;
    //Tant que on n'est pas ? la fin de la liste
    while (temp != NULL) {
        if (temp->client->numero == num) {
            //Si le client a le num?ro recherch?, on renvoie son adresse
            return temp->client;
        }
        temp = temp->next;
    }
    //s'il n'y a aucun client avec ce num?ro recherch? on renvoie NULL
    return NULL;
}
