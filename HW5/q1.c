#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign, sawsign;

    while (isspace(c = getch()))   
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);    
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (sawsign = (c == '+' || c == '-'))
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);
        if (sawsign)
            ungetch((sign == -1) ? '-' : '+');
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}