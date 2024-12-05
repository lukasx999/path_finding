#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "./path_finding.h"




static EdgeList edgelist_new(void) {
    EdgeList new = {
        .size     = 0,
        .capacity = 5,
        .items    = NULL,
    };
    new.items = malloc(new.capacity * sizeof(Edge));
    return new;

}


static void edgelist_append(EdgeList *el, Edge new_) {

    if (el->size == el->capacity) {
        el->capacity *= 2;
        el->items = realloc(el->items, el->capacity * sizeof(Edge));
    }

    el->items[el->size++] = new_;
}

static void edgelist_destroy(EdgeList *el) {
    free(el->items);
    el->items = NULL;
}



static Edge edge_new(uint32_t dist, Vertex *other) {

    Edge new = {
        .distance = dist,
        .other    = other,
    };

    return new;
}

Vertex vertex_new(uint32_t id) {

    Vertex new = {
        .id    = id,
        .edges = edgelist_new(),
    };

    return new;
}

void vertex_connect(Vertex *first, Vertex *second, uint32_t distance) {

    Edge e1 = edge_new(distance, second);
    edgelist_append(&first->edges, e1);

    Edge e2 = edge_new(distance, first);
    edgelist_append(&second->edges, e2);

}

void vertex_destroy(Vertex *v) {
    edgelist_destroy(&v->edges);
}


static void _rec_graph_print_from(Vertex *current, IdList *visited) {

    for (size_t i=0; i < visited->size; ++i) {
        if (visited->items[i] == current->id) {
            return;
        }
    }

    idlist_append(visited, current->id);
    printf("(%d)\n", current->id);

    for (size_t i=0; i < current->edges.size; ++i) {
        Vertex *other = current->edges.items[i].other;
        _rec_graph_print_from(other, visited);
    }

}

void graph_print_from(Vertex *start) {
    IdList visited = idlist_new();
    _rec_graph_print_from(start, &visited);
}



IdList idlist_new(void) {

    IdList new = {
        .size     = 0,
        .capacity = 5,
        .items    = NULL,
    };

    new.items = malloc(new.capacity * sizeof(uint32_t));
    return new;

}

void idlist_append(IdList *l, uint32_t new_id) {

    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->items = realloc(l->items, l->capacity * sizeof(uint32_t));
    }

    l->items[l->size++] = new_id;
}

void idlist_destroy(IdList *l) {
    free(l->items);
    l->items = NULL;
}
