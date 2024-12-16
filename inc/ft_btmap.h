#ifndef BTMAP_H
#define BTMAP_H

#include <stdlib.h>
#include <string.h> //debug



#define ft_strcmp strcmp //debug
#define ft_strdup strdup //debug

//BinaryTreeMap
typedef struct s_btmap
{
    char *key;
    char *val;
    struct s_btmap *left;
    struct s_btmap *right;
} t_btmap;


/**** funcs ****/

//t_btmap *btmap_new();
void btmap_clear(t_btmap *btmap);
//keyから値を取得、なかったらNULL
char *btmap_get(t_btmap *btmap, char *key);
//key,entityを追加
char *btmap_export(t_btmap *btmap, char *key, char *val);
//keyを削除
char *btmap_unset(t_btmap *btmap, char *key);

#endif