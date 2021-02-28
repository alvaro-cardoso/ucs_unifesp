#include "globals.h"
#include "util.h"
#include "parse.h"
#include "analyze.h"

extern FILE *yyin;
int Error = FALSE;
FILE *source;

int numlinha = 1;
int iniciolinha = 1;

TokenType getToken();
void Scanner();

int main()
{
    FILE *f_out = fopen("outParser.output", "w+");

    TreeNode *syntaxTree;

    source = fopen("entrada.txt", "r");

    yyin = source;

    printf("\nCriando Arquivo de Saida do Scanner ...\n");
    Scanner();

    rewind(yyin);
    rewind(source);
    numlinha = 1;
    iniciolinha = 1;

    if (!Error)
    {
        printf("\nGerando Arvore Sintatico...\n");
        syntaxTree = parse();
        printTree(syntaxTree, f_out);

        if (!Error)
        printf("\nConstruindo Tabela de Simbolos...\n");
        buildSymtab(syntaxTree);
        printf("\nChecando tipos...\n");
        typeCheck(syntaxTree);
    }

    fclose(source);
    fclose(f_out);

    return 0;
}