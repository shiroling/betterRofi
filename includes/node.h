typedef struct node {
    int seekCfg, seekChoices;

} node;
node isCorrect(int seek, FILE *fic, const char name[32]);
node getParam(int seek,FILE *fic,char name[32]);
node getChoices( int seek, FILE fic);