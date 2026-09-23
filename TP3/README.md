#k corp cad tout element non nul est inversible 
#k anneau il exite des element non inversible
Exercice 1 : Exponentiation rapide

Le but de cet exercice est d’implémenter deux algorithmes d’exponentiation rapide dans le corps K := Z/536870909Z des entiers modulo le nombre premier 536870909 = 2^29 − 3.

Pour tout l’exercice, il est conseillé de compiler votre programme avec l’option d’optimisation -O2 ou -O3.

On fournit les fonctions suivantes permettant de calculer la somme et le produit de deux nombres dans K :

// In: 0 <= a,b < 536870909
// Out: 0 <= x < 536870909 t.q. x ~ a + b [536870909]
uint64_t add293(uint64_t a, uint64_t b)
{
    return ((a + b) % 536870909);
}


// In: 0 <= a,b < 536870909
// Out: 0 <= x < 536870909 t.q. x ~ a * b [536870909]
uint64_t mul293(uint64_t a, uint64_t b)
{
    return ((a * b) % 536870909);
}


Q.1 :

1. Expliquez pourquoi remplacer 536870909 ci-dessus par 1099511627689 = 2^40 − 87 permet de correctement calculer l’addition dans K’ := Z/1099511627689Z, mais ne permet pas de calculer correctement le produit.

2. Donnez un critère nécessaire et suffisant sur la valeur du module pour que les deux fonctions ci-dessus soient correctes.


RESOLUTION1
    - on a pour  K := Z/536870909Z => 0<=a,b<536870909=2^29-3 (#) et pour K’ := Z/1099511627689Z  0<=a,b<=1099511627689Z=2^40-87 (*)
poson m=40  et n=29
pour (*) on aura a peu pres pour  :
    -l addition a+b<=2**m=2**41
    -la multiplication a.b<2**2m=2^80 qui est superieur au uinint64=2^64

RESOLUTION2:
# Q.1.2

## Question

Donnez un critere necessaire et suffisant sur la valeur du module pour que les deux fonctions soient correctes.

On note le module m.

On a :

0 <= a,b < m

On utilise le type uint64_t, qui peut stocker au maximum :

2^64 - 1

## 1. Pour l'addition

La plus grande valeur possible de a + b est :

(m - 1) + (m - 1) = 2m - 2

Pour eviter un overflow, il faut :

2m - 2 <= 2^64 - 1

Donc :

m <= 2^63

La condition pour l'addition est donc :

m <= 2^63

## 2. Pour la multiplication

La plus grande valeur possible de a * b est :

(m - 1) * (m - 1) = (m - 1)^2

Pour eviter un overflow, il faut :

(m - 1)^2 <= 2^64 - 1

On sait que :

2^32 * 2^32 = 2^64

Donc il faut :

m <= 2^32

La condition pour la multiplication est donc :

m <= 2^32

## 3. Condition pour les deux fonctions

Il faut que les deux conditions soient respectees :

m <= 2^63

et

m <= 2^32

La condition la plus restrictive est :

m <= 2^32

## Reponse

Le critere necessaire et suffisant pour que les deux fonctions soient correctes avec des uint64_t est :

m <= 2^32

Le produit est l'operation la plus contraignante, car a * b peut devenir beaucoup plus grand que a + b et provoquer un overflow.  
   