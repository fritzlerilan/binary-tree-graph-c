#ifndef CONSOLECOLOR
#define CONSOLECOLOR


#include <stdlib.h>
#include <windows.h>

#define BLANCO_F 240
#define NEGRO 0
#define AZULINO_F 150
#define ROJO_F 192

#define AZUL_L 11
#define VERDE_L 2
#define CELESTE_L 3
#define ROJO_L 4
#define VIOLETA_L 5
#define MOSTAZA_L 6
#define GRIS_L 8
#define AZULINO_L 9
#define VERDE_FLUO_L 10
#define ROSA_L 12
#define CELESTE_CLARO_L 11
#define FUCSIA_L 13
#define AMARILLOC_L 14
#define BLANCO_L 15

#define COLOR_RESET color(NEGRO, BLANCO_L);
#define C_ERROR color(ROJO_F, BLANCO_L);
#define C_OK color(AZULINO_F, BLANCO_L);
#define C_SHINE color(BLANCO_F, NEGRO);

void colorFondo(int tono);
void colorLetras(int tono);
void color(int fondo, int letras);
#endif
