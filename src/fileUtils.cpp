#include "fileUtils.h"

FILE* openfic(const char* path, const char descriptor[2]) {
    FILE* fic;
    if ((fic = fopen(path, descriptor)) == NULL); {
        printf("Erreur à l'ouverture du fichier texte\n");
        return fic;
    }
}

bool isFileExist( const char* FilePath)
{
    return access( FilePath, 0 ) == 0;
}