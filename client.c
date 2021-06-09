//1__________________________Définir les éléments nécessaires pour la gestion des clients______________________________________________

// la structure de données Client qui définit l'entité client
typedef struct {
    int numero;
    char *nom;
    char *prenom;
} Client;

// la structure de donnés ElementClient pour gérer la liste chainée des clients
typedef struct elementClient {
    Client *client;
    struct elementClient *next;
} ElementClient;

//cette fonction permet de créer et initialiser un client
Client *createNewClient(int numero, char *nom, char *prenom) {
    Client *element = (Client *) malloc(sizeof(Client));
    element->numero = numero;
    element->nom = nom;
    element->prenom = prenom;
    return element;
}

// cette fonction va crée et initialiser un élément de la liste chainée des clients
ElementClient *createNewElementClient(Client *client) {
    ElementClient *element = (ElementClient *) malloc(sizeof(ElementClient));
    element->client = client;
    element->next = NULL;
    return element;
}

int isElementClientEmpty(ElementClient **element) {
    return *element == NULL;
}

//cette fonction pour retourner le dernier élément d'une liste chainée des clients
ElementClient *lastAdressClt(ElementClient *L) {
    ElementClient *elemClt;
    if (L == NULL)
        return NULL;
    for (elemClt = L; elemClt->next != NULL; elemClt = elemClt->next);
    return elemClt;
}

//la fonction void qui permet d'ajouter un client à la liste chainée
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
    //Tant que on n'est pas à la fin de la liste
    while (temp != NULL) {
        if (temp->client->numero == num) {
            //Si le client a le numéro recherché, on renvoie son adresse
            return temp->client;
        }
        temp = temp->next;
    }
    //s'il n'y a aucun client avec ce numéro recherché on renvoie NULL
    return NULL;
}
