#include <stdio.h>
#include <stdlib.h>

#include "file.h"

void saveFile(char* file, GLfloat vdata[][3], int numVertices)
{
    FILE *fp;
    int i;

    if ((fp = fopen(file, "wt")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", file);
        exit(1);
    }

    fprintf(stderr, "Writing file %s\n", file);

    fprintf(fp, "%d\n", numVertices);

    for (i = 0; i < numVertices; i++) {

        if (vdata[i][0] != 0.0f)
            fprintf(fp, "%f %f %f %f %f %f %f %f %f %f\n",
                vdata[i][0], vdata[i][1], vdata[i][2],
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 1.0f);
        else
            fprintf(fp, "%f %f %f %f %f %f %f %f %f %f\n",
                vdata[i][0], vdata[i][1], vdata[i][2],
                0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 1.0f);
    }

    fclose(fp);
    fprintf(stderr, "File written.\n");
}
