#include <stdio.h>
#include <string.h>
#include "produit.c"
#include "client.c"
#include "lc.c"
#include "vente.c"


int main() {
	
	
    ElementProduit *elementProduit = NULL;
    ElementClient *elementClient = NULL;
    ElementVente *elementVente = NULL;

	//manipulation des produits
    Produit *produit1 = createNewProduit(1, "Laptop", 5000);
    Produit *produit2 = createNewProduit(2, "iPhone11", 15000);
    Produit *produit3 = createNewProduit(3, "playStation", 7000.55);
    Produit *produit4 = createNewProduit(4, "Casque", 600);
    Produit *produit5 = createNewProduit(5, "Tablette", 1890.12);
    Produit *produit6 = createNewProduit(6, "Souris", 80);
    Produit *produit7 = createNewProduit(7, "Classeur", 150);
    Produit *produit8 = createNewProduit(8, "CarteMere", 1140.5);

    addProduit(produit1, &elementProduit);
    addProduit(produit2, &elementProduit);
    addProduit(produit3, &elementProduit);
    addProduit(produit4, &elementProduit);
    addProduit(produit5, &elementProduit);
    addProduit(produit6, &elementProduit);

    displayProduits(elementProduit);
    printf("\n");

    Client *client1 = createNewClient(1, "Elmajni", "Khaoula");
    Client *client2 = createNewClient(2, "Choukairi", "Ahmed");
    Client *client3 = createNewClient(3, "Lmarnissi", "Naima");
    Client *client4 = createNewClient(4, "Saadidi", "Nadia");
    Client *client5 = createNewClient(5, "Elarabi", "Ziad");
    Client *client6 = createNewClient(6, "Noeman", "Samidi");


    //manipulation des clients
	addClient(client1, &elementClient);
    addClient(client2, &elementClient);
    addClient(client3, &elementClient);
    addClient(client4, &elementClient);
    addClient(client5, &elementClient);
    addClient(client6, &elementClient);

    displayClients(elementClient);


	//manipulation des ventes    Vente *vente1 = NULL, *vente2 = NULL, *vente3 = NULL
    Vente *vente1 = NULL, *vente2 = NULL, *vente3 = NULL;
    vente1 = createVente(vente1, elementClient);
    vente2 = createVente(vente2, elementClient);
    vente3 = createVente(vente3, elementClient);

    addVente(vente1, &elementVente);
    addVente(vente2, &elementVente);
    addVente(vente3, &elementVente);

    //manipulation des lignes de commandes et l'ajout aux ventes
	vente1 = addLcToVente(vente1, getProduit(1, elementProduit), 2);
    vente1 = addLcToVente(vente1, getProduit(2, elementProduit), 3);
    vente2 = addLcToVente(vente2, getProduit(3, elementProduit), 4);
    vente2 = addLcToVente(vente2, getProduit(4, elementProduit), 5);
    vente3 = addLcToVente(vente3, getProduit(5, elementProduit), 6);
    vente3 = addLcToVente(vente3, getProduit(6, elementProduit), 7);

    //le calcul du total de la vente entiere
    ElementLc *temp;
    
    for (temp = vente1->elementLc; temp != NULL; temp = temp->next) {
        vente1->total += temp->lc->total;
    }
    for (temp = vente2->elementLc; temp != NULL; temp = temp->next) {
        vente2->total += temp->lc->total;
    }
    for (temp = vente3->elementLc; temp != NULL; temp = temp->next) {
        vente3->total += temp->lc->total;
    }

    displayVentes(elementVente);

    return 0;
}
