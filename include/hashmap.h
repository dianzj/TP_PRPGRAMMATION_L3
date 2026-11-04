#ifndef STDBOOL_H
#include <stdbool.h>
#define STDBOOL_H 1
#endif

/** @file
 *@brief Une table de hashage avec résolution des conflit par chaînage
 */

/**
 * Type abstrait (opaque) de représentation d'une HashMap
 * */
typedef struct HashMap HashMap;

/**
 * Fonction pour allouer et intialiser une HashMap.
 * Si l'allocation n'est pas possible (i.e. taille trop grande, pas assez de mémoire), alors la fonction doit retourner `NULL` et libérer la mémoire si besoin.
 * @param minCapacity la capacité intiale de la HashMap (i.e. le nombre de buckets)
 * @param hash_func la fonction de hashage utilisé pour calculer les emplacement des éléments
 * @return la HashMap crée ou `NULL` si la création est impossible
 */
HashMap* hm_create(size_t minCapacity, uint64_t (*hash_func)(const char[static 1]));

/**
 * Fonction pour désallouer une HashMap et ses constituants.
 * @param hm la HashMap à désallouer
 */
void hm_destroy(HashMap* restrict self);

/**
 * Fonction pour visiter tous les paires clé-valeur d'une HashMap.
 * la fonction @visit_func sera appelée pour chaque paire contenue dans la structure avec en paramètres
 * l'indice dans le tableau, la clé, le pointeur vers la valeur.
 * @param hm la HashMap à désallouer
 * @param visit_func la fonction à appeler pour chaque paire clé-valeur de la HashMap.
 */
void hm_visit(HashMap* restrict self, void (*visit_func)(const size_t, const char[], const void*));

/**
 * Permet de vider une HashMap (et désallouer la mémoire associée) sans la détuire (i.e. sans désallouer la structure principale).
 * Après cet appel, la fonction @hm_size appelée sur la HashMap doit retourner `0`.
 * @param hm la HashMap à vider
 * */
void hm_clear(HashMap* restrict self);

/**
 * Retoune le nombre de paires clé-valeur contenue dans la HashMap (attention c'est la taille courante pas la capacité).
 * @param hm une hashmap
 */
size_t hm_size(HashMap* restrict self);

/**
 * Retoune la capacité de la hashmap
 * @param hm une hashmap
 */
size_t hm_capacity(HashMap* restrict self);

/**
 * Ajoute la paire (@key,@value) dans la HashMap.
 * Si la clé est déja présente alors la valeur associée sera remplacée par @value.
 * La chaîne de caractères référencée par @key sera recopiée internalement par la structure.
 * La valeur pointée par @value sera juste référencée (et non recopiée).
 * Si l'ajout provoque un dépassement du facteur de charge alors la table sera internalement agrandie (capacité multipliée par deux) et les paires seront réorganisées.
 * @param hm la HashMap dans laquel va se faire l'ajout.
 * @param key la clé sous forme de chaîne de caractères (initialisées, on n'accepte pas les pointeurs `NULL`)
 * @param value un pointeur vers valeur associée (ici NULL est accepté)
 * @return un poiteur vers la valeur remplacée ou NULL si la clé n'était pas présente
 */
void* hm_put(HashMap* restrict self, const char key[static 1], void* value);

/**
 * Retourne la valeur associée à la clé.
 * Si la clé n'est pas présente alors la fonction generate_value sera appelée pour générer la valeur qui sera associée.
 * @param hm la HashMap dans laquel on recherche.
 * @param key la clé sous forme de chaîne de caractères (initialisées, on n'accepte pas les pointeurs `NULL`)
 * @param generate_value la fonction qui génère la valeur si la clé n'est pas présente
 * @return un pointeur vers valeur associée ou générée par generate_value
 */
void* hm_getOrPutIfAbsent(HashMap* restrict self, const char key[static 1], void* (*generate_value)(void));

/**
 * Retourne un pointeur vers la valeur associée à @key
 * @param hm une hashmap
 * @return un pointeur vers la valeur associée à @key ou `NULL` si @key n'est pas dans la table.
 */
void* hm_get(HashMap* restrict self, const char key[static 1]);

/**
 * Enlève la paire clé-valeur associée à @key
 * @param hm une hashmap
 * @return un pointeur vers la valeur qui était associée à @key ou `NULL` si @key n'est pas dans la table
 */
void* hm_delete(HashMap* restrict self, const char key[static 1]);
²
