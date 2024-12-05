#include <stdio.h>
#include <stdlib.h>

#include "./path_finding.h"
#include "./renderer.h"




int main(void) {

    /*
    [1] <-5-> [2] <-3-> [3]
               |
              [4]
               |
    <----------1---------->
    */

    Vertex v1 = vertex_new(1);
    Vertex v2 = vertex_new(2);
    Vertex v3 = vertex_new(3);
    Vertex v4 = vertex_new(4);

    vertex_connect(&v1, &v2, 5);
    vertex_connect(&v2, &v3, 3);
    vertex_connect(&v3, &v1, 1);
    vertex_connect(&v2, &v4, 7);
    vertex_connect(&v1, &v4, 9);

    graph_print_from(&v1);

    size_t vs_size = 4;
    Vertex *vs = malloc(vs_size * sizeof(Vertex));
    render(vs, vs_size);



    return EXIT_SUCCESS;

}
