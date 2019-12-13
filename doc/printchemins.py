nb=0 #variable globale

def genereMatrice(n): #On cree la matrice d'adjacence du graphe complet
    mat=[[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if i!=j:
                mat[i][j]=1
    return mat

def recursiveRechercheComplexe(depart,arrivee,matriceAdjacence,taille,l):
    global nb # Utilisation de la variable globale
    for i in range(taille):
        if(matriceAdjacence[depart][i]==1): # Si jamais l'arete existe...
            l.append(i)
            matriceAdjacence[depart][i]=0
            if(i==arrivee): # si jamais valable
                nb+=1
                print(l)
            recursiveRechercheComplexe(i,arrivee,matriceAdjacence,taille,l)
            l.pop()
            matriceAdjacence[depart][i]=1 # reprendre depuis le dernier appel

def nbchemins(depart, arrivee, taille):
    matriceAdjacence=genereMatrice(taille)
    l=[depart]
    recursiveRechercheComplexe(depart,arrivee,matriceAdjacence,taille,l)
    print(nb)
