#include<string.h>
#include <stdio.h>
#include "expo_rap.h"
uint64_t add293(uint64_t a, uint64_t b)
{
return ((a + b) % 536870909);
}

uint64_t mul293(uint64_t a, uint64_t b)
{
return ((a * b) % 536870909);
}

uint64_t slow_exp(uint64_t a, uint64_t n){
    uint64_t resulta=1;
    if(n==0){
        return 1;
    }
    for(uint64_t i=1;i<n;i++){
        resulta=mul293(a,resulta);
    }
    return resulta;
}
uint64_t fast_exp_rec(uint64_t a, uint64_t n)
{
    if (n == 0) {
        return 1;
    }

    uint64_t moitie = fast_exp_rec(a, n / 2);
    uint64_t resultat = mul293(moitie, moitie);

    if (n % 2 != 0) {
        resultat = mul293(resultat, a);
    }

    return resultat;
}


/* a^n=(produit de i allant  de 0 a 63)de a^(ni*2^(i)) ce qui correspond a une mise au carree sucessif des a  avec n63,...,n0 ∈{0,1}leschiffres
 de n en base2 (n=somme de i allant de 0 a 63 de ni*2^i)
donc a^n peut s ecrire comme produit des terme carree(exponentiation rapide)
principe: dans le produit a^(ni*2^i) est pris si ni=1 or ni est la valeur du bit de n a la position i qu on peut recuper en faissant n>>i(n/2^i) ce
            qui deplacera le bit i en position 0  puis on regarde si n est divisible par 2 si oui le bit de point faible faut 0 sinon 1

            -donc pour obtenir a^n on multipliera par les caree succesif (a^2*(a^2)^2..) en prenant les puissance si ni=1

*/

/*
a^n peut etre calcule en utilisant l'ecriture binaire de n.

On ecrit :

n = somme de i allant de 0 a 63 de ni * 2^i

avec ni = 0 ou 1.

Donc :

a^n = produit de i allant de 0 a 63 de a^(ni * 2^i)

Chaque ni correspond au bit de n a la position i.

Si ni = 1, on prend la puissance correspondante.
Si ni = 0, on ne la prend pas.

Les puissances correspondantes sont obtenues par mises au carre successives :

a
a^2
a^4
a^8
a^16
...

Pour connaitre ni, on peut decaler n de i positions vers la droite avec n >> i.
Le bit i se retrouve alors en position 0.

Si le nombre obtenu est impair, le bit vaut 1.
S'il est pair, le bit vaut 0.

Principe :
on parcourt les bits de n et on multiplie le resultat par la puissance
courante seulement lorsque le bit correspondant vaut 1.
A chaque etape, la puissance courante est mise au carre.
*/
uint64_t fast_exp_iter(uint64_t a, uint64_t n){
    
    uint64_t puissance=a;
    uint64_t res=1;
    if(n==0){
        return 1;
    }
    while (n!=0){
        if(n%2!=0){
            res=mul293(res,puissance);           
        }   
        puissance=mul293(puissance,puissance);
        n=n>>1;
    }    
    return res;
}

uint64_t inv293(uint64_t a){
    return fast_exp_iter(a,536870909-2);
}

/*Q4)M<2^32
*/
/* an{ n=0..1 a=0..1  m-1}
*/
