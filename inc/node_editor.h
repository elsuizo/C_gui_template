/* -------------------------------------------------------------------------
@file node_editor.h

@date 07/14/17 01:42:49
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#ifndef NODE_EDITOR_H
#define NODE_EDITOR_H


#include "../inc/main.h"

struct node {
    int ID;
    char name[32];
    struct nk_rect bounds;
    float value;
    struct nk_color color;
    int input_count;
    int output_count;
    struct node *next;
    struct node *prev;
};

struct node_link {
    int input_id;
    int input_slot;
    int output_id;
    int output_slot;
    struct nk_vec2 in;
    struct nk_vec2 out;
};

struct node_linking {
    int active;
    struct node *node;
    int input_id;
    int input_slot;
};

struct node_editor {
    int initialized;
    struct node node_buf[32];
    struct node_link links[64];
    struct node *begin;
    struct node *end;
    int node_count;
    int link_count;
    struct nk_rect bounds;
    struct node *selected;
    int show_grid;
    struct nk_vec2 scrolling;
    struct node_linking linking;
};

#define LEN(a) (sizeof(a)/sizeof(a)[0])

void
node_editor_push(struct node_editor *editor, struct node *node);

void
node_editor_pop(struct node_editor *editor, struct node *node);

struct node*
node_editor_find(struct node_editor *editor, int ID);

void
node_editor_add(struct node_editor *editor, const char *name, struct nk_rect bounds,
    struct nk_color col, int in_count, int out_count);

void
node_editor_link(struct node_editor *editor, int in_id, int in_slot,
    int out_id, int out_slot);

void
node_editor_init(struct node_editor *editor);

int
node_editor(struct nk_context *ctx);

#endif
