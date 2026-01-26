#ifndef __file_h_
#define __file_h_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void saveFile(char* file, GLfloat vdata[][3], int numVertices);

#ifdef __cplusplus
}
#endif

#endif
