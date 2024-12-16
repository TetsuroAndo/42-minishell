#ifndef FT_LST_H
# define FT_LST_H

# include <stddef.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif /*FT_LST_H */


#ifndef FT_ENV_H
#define FT_ENV_H

#include <stdlib.h>
#define MAX_WORD_LEN 2048
#include <stdlib.h>





/**** funcs ****/

//keyから値を取得、なかったらNULL
char *env_get(t_list *env, char *key);
//entityを追加
char *env_export(t_list *env, char *ent);
//keyを削除
char *env_unset(t_list *env, char *key);

#endif