#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hashmap.h>

#define BUFFER_SIZE 4096 // Taille du tampon pour la lecture

// Fonction de hachage djb2
uint64_t hash_djb2(const char str[static 1])
{
    uint32_t hash = 5381;
    for (size_t i = 0; str[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + str[i]; // hash * 33 + str[i]
    }

    return hash;
}

bool print(const size_t idx, const char key[], const void* value)
{
    printf("%s %u\n", key, *((uint32_t*)(value)));
    return true;
}

void* alloc_uint32()
{
    return calloc(1, sizeof(uint32_t));
}
void add_word(const char word[static 1], HashMap* map)
{
    uint32_t* nb = hm_getOrPutIfAbsent(map, word, &alloc_uint32);
    (*nb) += 1;
}
void read_file_and_process_words(const char* filename, HashMap* map)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Impossible d'ouvrir le fichier");
        return;
    }

    char buffer[BUFFER_SIZE + 1] = { '\0' };
    size_t nread = 0;
    size_t start = 0;
    int word_start = -1;

    // Lire le fichier par blocs
    while ((nread = fread(buffer + start, 1, BUFFER_SIZE - start, file)) > 0) {
        size_t word_length = 0;
        size_t end = start + nread;
        // Parcours des caractères dans le tampon
        for (size_t j = 0; j < end; j++) {
            char c = buffer[j];

            if (!ispunct(c) && !isspace(c)) { // pourrait mieux faire
                // Si c'est une lettre ou un chiffre, commencer ou continuer un mot
                if (word_start == -1) {
                    word_start = j;
                }
                buffer[j] = tolower(buffer[j]);
                word_length++;
            } else {
                // Si un mot est terminé, traiter le mot
                if (word_start != -1) {

                    // on met un \0 pour indiquer une fin de chaîne
                    buffer[j] = '\0';
                    add_word(buffer + word_start, map);

                    word_start = -1; // Réinitialiser le début du mot
                    word_length = 0;
                }
            }
        }

        // Si un mot était encore en cours à la fin du tampon,
        // on le remet au debut, en suposant que la mémoire ne se chevauche pas...
        // si c'est le cas memmove aurait été mieux
        if (word_start != -1) {
            memmove(buffer, buffer + word_start, word_length);
            start = word_length;
        } else {
            start = 0;
        }
    }
    if (word_start != -1) {
        buffer[start + nread] = '\0';
        add_word(buffer + word_start, map);
    }

    fclose(file);
}

bool clear_values(const size_t idx, const char key[], void* value)
{
    free(value);
}

int main(int argc, char* argv[argc + 1])
{

    HashMap* hm = hm_create(10, &hash_djb2);

    read_file_and_process_words("lerougeetlenoir.txt", hm);

    hm_visit(hm, &print);

    hm_visit(hm, NULL, &clear_values);

    hm_destroy(hm);
}
