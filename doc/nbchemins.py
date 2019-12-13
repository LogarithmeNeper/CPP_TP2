nb=0 #variable globale

def genereMatrice(n): #On cree la matrice d'adjacence du graphe complet
    mat=[[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if i!=j:
                mat[i][j]=1
    return mat

def recursiveRechercheComplexe(depart,arrivee,matriceAdjacence,taille):
    global nb # Utilisation de la variable globale
    for i in range(taille):
        if(matriceAdjacence[depart][i]==1): # Si jamais l'arete existe...
            matriceAdjacence[depart][i]=0
            if(i==arrivee): # si valable
                nb+=1
            recursiveRechercheComplexe(i,arrivee,matriceAdjacence,taille)
            matriceAdjacence[depart][i]=1 # reset

def nbchemins(depart, arrivee, taille):
    matriceAdjacence=genereMatrice(taille)
    recursiveRechercheComplexe(depart,arrivee,matriceAdjacence,taille)
    print(nb)
