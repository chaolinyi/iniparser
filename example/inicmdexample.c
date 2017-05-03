#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

void create_example_ini_file(void);
int  parse_ini_file(char * ini_name);

int main(int argc, char * argv[])
{
    int     status ;

    if (argc<2) {
        status = parse_ini_file("cmd1.ini");
    } else {
        status = parse_ini_file(argv[1]);
    }
    return status ;
}


int parse_ini_file(char * ini_name)
{
    dictionary  *   ini ;

    /* Some temporary variables to hold query results */
    int             b ;
    int             i ;
    double          d ;
    const char  *   s ;

    ini = iniparser_load(ini_name);
    if (ini==NULL) {
        fprintf(stderr, "cannot parse file: %s\n", ini_name);
        return -1 ;
    }
    iniparser_dump(ini, stderr);

    /* Get pizza attributes */
    printf("Summary Info:\n");

    b = iniparser_getint(ini, "summaryinfo:commandid", -1);
    printf("commandid:       [%d]\n", b);

    iniparser_freedict(ini);
    return 0 ;
}


