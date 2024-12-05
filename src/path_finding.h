#ifndef _PATH_FINDING_H
#define _PATH_FINDING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>




typedef struct Vertex Vertex;


typedef struct {
    uint32_t distance;
    Vertex *other;
} Edge;


typedef struct {
    size_t size;
    size_t capacity;
    Edge *items;
} EdgeList;

struct Vertex {
    uint32_t id;
    EdgeList edges;
};

extern Vertex vertex_new(uint32_t id);
extern void vertex_connect(Vertex *self, Vertex *other, uint32_t distance);
extern void vertex_destroy(Vertex *v);



extern void graph_print_from(Vertex *start);


typedef struct {
    size_t capacity;
    size_t size;
    uint32_t *items;
} IdList;

extern IdList idlist_new(void);
extern void idlist_append(IdList *l, uint32_t new_id);
extern void idlist_destroy(IdList *l);


#endif // _PATH_FINDING_H
