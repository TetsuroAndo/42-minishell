#include "ft_btmap.h"
t_btmap *btmap_new()
{
  t_btmap *btmap;
  btmap = (t_btmap *)malloc(sizeof(t_btmap));
  if (!btmap)
    return NULL;
  btmap->left = NULL;
  btmap->right = NULL;
  btmap->key = NULL;
  btmap->val = NULL;
  return btmap;
}

void btmap_clear(t_btmap *btmap)
{
    if (!btmap)
        return;
    btmap_clear(btmap->left);
    btmap_clear(btmap->right);
    free(btmap->key);
    free(btmap->val);
    free(btmap);
}


//keyから値を取得、なかったらNULL
char *btmap_get(t_btmap *root, char *key)
{
  t_btmap *curr;
  curr = root;
  while (curr)
  {
    if (ft_strcmp(curr->key, key) == 0)
      return curr->val;
    else if (ft_strcmp(curr->key, key) < 0)
      curr = curr->right;
    else
      curr = curr->left;
  }
  return NULL;
}
/*
*key,valはstrdupするべきか
*key,valを追加 返り値はなんでも良いがstrcpyなどに合わせて変更してかつそれを返す 
*if it fails return NULL
*/
char *btmap_export(t_btmap *btmap, char *key, char *val)
{
  // t_btmap *new_node;
  // new_node = btmap_new();
  // if (!new_node)
  //   return NULL;
  // if (!btmap->key)//最初のnodeだったら
  // {
  //   btmap->key = key;
  //   btmap->val = val;
  //   return new_node->val;
  // }
  // if (ft_strcmp(key, btmap->key) < 0)
  // {
  //   new_node->left = btmap->left;
  //   btmap->left = new_node;
  // }
  // else
  // {
  //   new_node->right = btmap->right;
  //   btmap->right = new_node;
  // }
  // return new_node->val; // return new node's value

}
//keyを削除
char *btmap_unset(t_btmap *btmap, char *key);
