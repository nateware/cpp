#include <iostream>

#define SHOW_VALUE(p) ((p == NULL) ? "NULL" : p)

static void clearval (char **p)
{
    printf("ptr : %p\n", p);
    *p = 0;
}

static void nullptr (char *p)
{
    *p = 0;
}

int main (int argc, const char * argv[])
{
    char * name;
    char * twak;
    int name_len = 10;
    int twak_len = 2;

    char **p;

    name = (char *)malloc(name_len * sizeof(char));
    memset(name, 0, name_len * sizeof(char));
    p = &name;
    //why is *p = name not the same??

    twak = (char *)malloc(twak_len * sizeof(char));
    memset(name, 0, twak_len * sizeof(char));

    printf("=====\n");
    printf("name = '%s'\n", name);
    strncpy(name, "Hey dude fuck you I will punch your face", name_len);
    printf("name = '%s'\n", name);

    twak[0] = 'T';
    twak[1] = 'w';
    twak[2] = 'a';
    twak[3] = 'k';

    printf("=====\n");
    printf("twak = '%s'\n", twak);
    strncpy(twak, "I'm so high right now", twak_len);
    printf("twak = '%s'\n", twak);

    for (char *ptr = name; *ptr != '\0'; ptr++)
      printf("%c", *ptr);
    printf("\n");

    printf("----------\n");

    printf("ptr = %p (%s)\n", p, SHOW_VALUE(*p));
    printf("ptr = %p (%s)\n", &name, SHOW_VALUE(name));
    clearval(p);
    printf("ptr = %p (%s)\n", p, SHOW_VALUE(*p));
    printf("ptr = %p (%s)\n", &name, SHOW_VALUE(name));
    nullptr(&p);
    printf("ptr = %p (%s)\n", p, SHOW_VALUE(*p));
    printf("ptr = %p (%s)\n", &name, SHOW_VALUE(name));


}

