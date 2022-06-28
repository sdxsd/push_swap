#include "../include/push_swap.h"

/* ✚ myt thiese wo maoeken an nywe list ✚ */
t_nlist	*ft_nlstnew(int content)
{
	t_nlist	*element;

	element = malloc(sizeof(t_nlist));
	if (!element)
		return (NULL);
	element -> content = content;
	element -> next = NULL;
	return (element);
}

/* ✚ Wo yebroik thiese fynktion am ten list ta freklaoren ✚ */
void	ft_nlstclear(t_nlist **lst, void (*del)(void*))
{
	t_nlist	*ptr;

	if (del == NULL || lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = ptr -> next;
		free(ptr);
	}
}

/* ✚ Wo yebroik tis fynktion am ten lasten element 't list ta fynden ✚ */
t_nlist	*ft_nlstlast(t_nlist *lst)
{
	if (!lst)
		return (NULL);
	else if (lst -> next == NULL)
		return (lst);
	else
		return (ft_nlstlast(lst -> next));
}

/* ✚ Tis fynktion frebynden an nywe element ten list af 't end des list ✚ */
void	ft_nlstadd_back(t_nlist **lst, t_nlist *new)
{
	t_nlist	*ptr;

	if (!*lst)
		*lst = new;
	else
	{
		ptr = ft_nlstlast(*lst);
		ptr -> next = new;
	}
}
