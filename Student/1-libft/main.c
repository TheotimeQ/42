
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "libft.h"
#include "bonus/libft.h"

//--------------- ANNEXES ---------------

// void print_tab(char **tab)
// {
//     int index;

//     index = 0;
//     while(tab[index] != NULL)
//     {
//         printf("|%s|\n",tab[index]);
//         index++;
//     }
// }

// void free_tab_2(char **tab)
// {
//     int index;

//     index = 0;
//     while(tab[index] != NULL)
//     {
//         free(tab[index]);
//         index++;
//     }
//     free(tab);
// }

// char    on_char1(unsigned int nb, char c)
// {
//     return (c + nb); 
// }

// void    on_char2(unsigned int nb, char *s)
// {
//     s[nb] = s[nb] + nb; 
// }

//--------------- Partie 1 ---------------

// isalpha
// int main()
// {  
// 	int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';

//     printf ("%d\n", isalpha(a));
//     printf ("%d\n", isalpha(b));
//     printf ("%d\n", isalpha(c));
//     printf ("%d\n", isalpha(d));
//     printf ("%d\n\n", isalpha(e));

//     printf ("%d\n", ft_isalpha(a));
//     printf ("%d\n", ft_isalpha(b));
//     printf ("%d\n", ft_isalpha(c));
//     printf ("%d\n", ft_isalpha(d));
//     printf ("%d\n", ft_isalpha(e));

//     return (1);
// }

// isdigit
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';
//     printf ("%d\n", isdigit (a));
//     printf ("%d\n", isdigit (b));
//     printf ("%d\n", isdigit (c));
//     printf ("%d\n", isdigit (d));
//     printf ("%d\n\n", isdigit (e));

//     printf ("%d\n", ft_isdigit (a));
//     printf ("%d\n", ft_isdigit (b));
//     printf ("%d\n", ft_isdigit (c));
//     printf ("%d\n", ft_isdigit (d));
//     printf ("%d\n", ft_isdigit (e));
//     return (0);
// }

// isalnum
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';

//     printf ("%d\n", isalnum (a));
//     printf ("%d\n", isalnum (b));
//     printf ("%d\n", isalnum (c));
//     printf ("%d\n", isalnum (d));
//     printf ("%d\n\n", isalnum (e));

//     printf ("%d\n", ft_isalnum (a));
//     printf ("%d\n", ft_isalnum (b));
//     printf ("%d\n", ft_isalnum (c));
//     printf ("%d\n", ft_isalnum (d));
//     printf ("%d\n", ft_isalnum (e));
//     return (0);
// }

// isascii
// int    main ()
// {
//     int a = 5;
//     int b = 127;
//     int c = 543;
//     int d = '-';
//     printf("%d\n", isascii(a));
//     printf("%d\n", isascii(b));
//     printf("%d\n", isascii(c));
//     printf("%d\n\n", isascii(d));

//     printf("%d\n", ft_isascii(a));
//     printf("%d\n", ft_isascii(b));
//     printf("%d\n", ft_isascii(c));
//     printf("%d\n", ft_isascii(d));
// }

// isprint
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 2;
//     int e = 127;
//     printf ("%d\n", isprint (a));
//     printf ("%d\n", isprint (b));
//     printf ("%d\n", isprint (c));
//     printf ("%d\n", isprint (d));
//     printf ("%d\n\n", isprint (e));

//     printf ("%d\n", ft_isprint (a));
//     printf ("%d\n", ft_isprint (b));
//     printf ("%d\n", ft_isprint (c));
//     printf ("%d\n", ft_isprint (d));
//     printf ("%d\n", ft_isprint (e));
//     return (0);
// }

// ft_strlen
// int main()
// {   
//     char src[50] = "0123456";

//     printf("%ld",ft_strlen(src));
//     return (1);
// }

// memset
// int main () {
//    char str[50];
//    char str2[50];

//    strcpy(str,"This is string.h library function");
//    puts(str);

//    memset(str,'$',15);
//    puts(str);

//    strcpy(str2,"This is string.h library function");
//    ft_memset(str2, '$', 15);
//    puts(str2);

//    return(0);
// }

// bzero
// int main () {
//    char str[50];
//    char str2[50];

//    strcpy(str,"This is string.h library function");
//    printf("Base : %s\n", str);

//    bzero(str, 1);
//    printf("Built-in : %s\n", str);

//    strcpy(str2,"This is string.h library function");
//    ft_bzero(str2, 1);
//    printf("Ma fonction : %s", str);
//    puts(str2);

//    return(0);
// }

// memcpy
// int main()
// {
// 	const char src[50] = "Ceci est un test";
// 	char dest[50];
// 	strcpy(dest,"Fck Jocelyn le clown");
// 	printf("BUILT-IN : Before memcpy dest   %s\n", dest);
// 	printf("return                          %s \n",memcpy(dest, src, 5));
// 	printf("After memcpy dest               %s\n", dest);
// 	printf("After memcpy src                %s\n", src);

// 	const char src2[50] = "Ceci est un test";
// 	char dest2[50];
// 	strcpy(dest2,"Fck Jocelyn le clown");
// 	printf("Before memcpy dest              %s\n", dest2);
// 	printf("Return                          %s \n",ft_memcpy(dest2, src2, 5));
// 	printf("After memcpy dest               %s\n", dest2);
// 	printf("After memcpy src                %s\n", src2);

//    return(0);
// }

// memmove
// int main()
// {
//     char str1[50] = "I am going from Delhi to Gorakhpur";
//     char str2[50] = "I am going from Delhi to Gorakhpur";
// 	char str3[50] = "I am going from Delhi to Gorakhpur";
// 	char str4[50] = "I am going from Delhi to Gorakhpur";
//     //Use of memmove
//     printf( "Function:	t_memmove with overlap 1\n" );
//     printf( "Orignal :	%s\n",str1);
//     printf( "Source:		     %s\n", str1 + 5 );
//     printf( "Destination:	           %s\n", str1 + 11 );
//     memmove( str1 + 11, str1 + 5, 29 );
//     printf( "Result:		%s\n", str1 );
//     printf( "Length:		%lu characters\n\n", strlen( str1 ) );

//     //Use of ft_memmove
//     printf( "Function:	t_memmove with overlap 1\n" );
//     printf( "Orignal :	%s\n",str2);
//     printf( "Source:		     %s\n", str2 + 5 );
//     printf( "Destination:	           %s\n", str2 + 11 );
//     ft_memmove( str2 + 11, str2 + 5, 29 );
//     printf( "Result:		%s\n", str2 );
//     printf( "Length:		%lu characters\n\n\n", strlen( str2 ) );

// 	//Use of memmove
//     printf( "Function:	t_memmove with overlap 2\n" );
//     printf( "Orignal :	%s\n",str3);
//     printf( "Source:		           %s\n", str3 + 11 );
//     printf( "Destination:	     %s\n", str3 + 5 );
//     memmove( str3 + 5, str3 + 11, 29 );
//     printf( "Result:		%s\n", str3 );
//     printf( "Length:		%lu characters\n\n", strlen( str3 ) );

// 	//Use of ft_memmove
//     printf( "Function:	t_memmove with overlap 2\n" );
//     printf( "Orignal :	%s\n",str4);
//     printf( "Source:		           %s\n", str4 + 11 );
//     printf( "Destination:	     %s\n", str4 + 5 );
//     ft_memmove( str4 + 5, str4 + 11, 29 );
//     printf( "Result:		%s\n", str4 );
//     printf( "Length:		%lu characters\n\n\n", strlen( str4 ) );
//     return 0;
// }

// strlcpy
// int main()
// {
//     char src[50] = "la chaine source";
//     char dest[25];
//     printf("%lu", strlcpy(dest, src, 5));
//     printf("\n%s", dest);

//     char src2[50] = "la chaine source";
//     char dest2[25];
//     printf("\n\n%lu", ft_strlcpy(dest2, src2, 5));
//     printf("\n%s", dest2);
// }

// strlcat		NUL
// int    main(void)
// {
//     char s1a[10] = "Test1";
//     char s2a[] = "OK";

// 	printf("%s\n", strlcat(s1a, s2a, 6));
//     printf("%s\n", ft_strlcat(s1a, s2a, 6));
//     return (0);
// }

// toupper
// int main()
// {
//     printf("%c\n", ft_toupper('a'));
//     printf("%c\n", ft_toupper('z'));
//     printf("%c\n", ft_toupper('A'));
//     printf("%c\n", ft_toupper('Z'));
//     printf("%c\n", ft_toupper('1'));
//     printf("%c\n", ft_toupper('7'));
// }

// tolower
// int main()
// {
//     printf("%c\n", ft_tolower('a'));
//     printf("%c\n", ft_tolower('z'));
//     printf("%c\n", ft_tolower('A'));
//     printf("%c\n", ft_tolower('Z'));
//     printf("%c\n", ft_tolower('1'));
//     printf("%c\n", ft_tolower('7'));
// }

// strchr
// int main()
// {
//     printf("%s", strchr("salut les meufs", 'm'));
//     printf("\n");
//     printf("%s", strchr("salut les meufs", 's'));
//     printf("\n");
//     printf("%s", strchr("salut les meufs", 'x'));
//     printf("\n");
//     printf("%s", strchr("salut les meufs", 'S'));
//     printf("\n");
// }

// strrchr
// int main()
// {
//     printf("%s", ft_strrchr("salut les meufs", 'm'));
//     printf("\n");
//     printf("%s", ft_strrchr("salut les meufs", 's'));
//     printf("\n");
//     printf("%s", ft_strrchr("salut les meufs", 'x'));
//     printf("\n");
//     printf("%s", ft_strrchr("salut les meufs", 'S'));
//     printf("\n");
// }

// strncmp
// int main()
// {
//     printf("%d \n",ft_strncmp("abc","abdwgwgwe",7));
//     printf("%d \n",strncmp("abc","abdwgwgwe",7));
// }

// memchr
// int main()
// {
//     printf("%s", ft_memchr("Salut les meufs", ' ', 16));
//     printf("\n");
//     printf("%s", memchr("Salut les meufs", ' ', 16));
//     printf("\n");
//     printf("\n");
//     printf("%s", ft_memchr("Salut les meufs", 'S', 16));
//     printf("\n");
//     printf("%s", memchr("Salut les meufs", 'S', 16));
//     printf("\n");
//     printf("\n");
//     printf("%s", ft_memchr("Salut les meufs", 'z', 16));
//     printf("\n");
//     printf("%s", memchr("Salut les meufs", 'z', 16));
// }

// memcmp
// int main()
// {
//     printf("%d",ft_memcmp("Si tu lis t'es gay", "Si tu lis t'es gay", 19));
//     printf("\n");
//     printf("%d",memcmp("Si tu lis t'es gay", "Si tu lis t'es gay", 19));
//     printf("\n");
//     printf("\n");
//     printf("%d",ft_memcmp("Si tu lis t'es gay", "Si tu lis t'es", 19));
//     printf("\n");
//     printf("%d",memcmp("Si tu lis t'es gay", "Si tu lis t'es", 19));
//     printf("\n");
//     printf("\n");
//     printf("%d",ft_memcmp("Si tu lis t'es gay", "Si tu lis t'es homo", 19));
//     printf("\n");
//     printf("%d",memcmp("Si tu lis t'es gay", "Si tu lis t'es homo", 19));
//     printf("\n");
//     printf("\n");
//     printf("%d",ft_memcmp("Si tu liS t'es gay", "Si tu lis t'es gay", 19));
//     printf("\n");
//     printf("%d",memcmp("Si tu liS t'es gay", "Si tu lis t'es gay", 19));
// }

// strnstr
// int main()
// {
//     printf("%s", ft_strnstr("Foo Bar Baz", "Bar", 4));
//     printf("\n");
//     printf("%s", strnstr("Foo Bar Baz", "Bar", 4));
//     printf("\n");
//     printf("\n");
//     printf("%s", ft_strnstr("Foo Bar Baz", "Bar", 12));
//     printf("\n");
//     printf("%s", strnstr("Foo Bar Baz", "Bar", 12));
//     printf("\n");
//     printf("\n");
//     printf("%s", ft_strnstr("Foo Bar Baz", "Bar", 20));
//     printf("\n");
//     printf("%s", strnstr("Foo Bar Baz", "Bar", 20));
//     printf("\n");
//     printf("\n");
//     printf("%s", ft_strnstr("Foo Bar Baz", "Bard", 12));
//     printf("\n");
//     printf("%s", strnstr("Foo Bar Baz", "Bard", 12));
//     printf("\n");
//     printf("\n");
// }

// atoi
// int main()
// {
//     printf("%d", ft_atoi("-45"));
//     printf(" %d", atoi("-45"));
//     printf("\n");
//     printf("%d", ft_atoi("0"));
//     printf(" %d", atoi("0"));
//     printf("\n");
//     printf("%d", ft_atoi("45"));
//     printf(" %d", atoi("45"));
//     printf("\n");
//     printf("%d", ft_atoi("-2147483648"));
//     printf(" %d", atoi("-2147483648"));
// 	printf("\n");
//     printf("%d", ft_atoi("  --2147483648"));
//     printf(" %d", atoi("  --2147483648"));
// }

// calloc
// #define INT_NUMBER 10
// int main() {

//     int i;
//     int *pointer = (int *) calloc( INT_NUMBER, sizeof(int) );
//     assert( pointer != NULL ); //Test calloc
//     for ( i=0; i<INT_NUMBER; i++ )
//         pointer[i] = i;
//     for (i=0; i<INT_NUMBER; i++ )
//         printf( "%d ", pointer[i] );
//     printf( "\n" );
//     free( pointer );

//     int j;
//     int *pointerT = (int *) ft_calloc( INT_NUMBER, sizeof(int) );
//     assert( pointerT != NULL ); //Test calloc
//     for ( j=0; j<INT_NUMBER; j++ )
//         pointerT[j] = j;
//     for (j=0; j<INT_NUMBER; j++ )
//         printf( "%d ", pointerT[j] );
//     printf( "\n" );
//     free( pointerT );

//     return 0;
// }

// strdup
// int main()
// {
//     char    *dest = ft_strdup("J'aime les nouilles");
//     printf("%s", dest);
//     return (0);
// }

//--------------- Partie 2 ---------------

// ft_substr
// int main()
// {   
//     char src[50] = "J'aime les nouilles et les poneys";
//     char *out = ft_substr(src, 10, 50);

//     printf("%s",out);
//     free(out);

//     return (1);
// }

// ft_strjoin
// int main()
// {   
//     char pre[50] = "J'aime les nouilles ";
//     char suf[50] = "et les poneys";
//     char *out = ft_strjoin(pre, suf);

//     printf("%s",out);
//     free(out);

//     return (1);
// }

//ft_strtrim
int main()
{   
    char s1[] = "etetlorem ipsum dolor sit amet";
    char *out = ft_strtrim(s1, "te");

    printf("%s\n",out);

    char s2[] = "     ";
	out = ft_strtrim(s2, "  ");
    printf("%s\n",out);

    free(out);
    return (1);
}

// ft_split
// int main()
// {   
//     char **out = ft_split("          ", ' ');
//     print_tab(out);
//     free_tab_2(out);
//     return (1);
// }

//ft_itoa
// int main()
// {
//     printf("%s", ft_itoa(-45));
//     printf("\n");
//     printf("%s", ft_itoa(0));
//     printf("\n");
//     printf("%s", ft_itoa(45));
//     printf("\n");
//     printf("%s", ft_itoa(-2147483647));
//     printf("\n");
//     printf("%s", ft_itoa(2147483647));
// }

//ft_strmapi
// int main()
// {
//     char    str[50] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//     printf("%s",ft_strmapi(str, &on_char1));
// }

//ft_striteri
// int main()
// {
//     char    str[50] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
// 	printf("%s \n",str);
// 	ft_striteri(str, &on_char2);
//     printf("%s \n",str);
// }

//ft_putchar_fd
// int main()
// {	
// 	char c;

// 	c = 'q';
//     ft_putchar_fd(c,1);
// }

//ft_putstr_fd
// int main()
// {	
// 	char str[50] = "Les petits poneys sont tres mignons";
//     ft_putstr_fd(str,1);
// }

//ft_putendl_fd
// int main()
// {	
// 	char str[50] = "Les petits poneys sont tres mignons";
//     ft_putendl_fd(str,1);
// }

//ft_putnbr_fd
// int main()
// {	
//     ft_putnbr_fd(-2147483647,1);
//     printf("\n");
//     ft_putnbr_fd(2147483647,1);
//     printf("\n");
//     ft_putnbr_fd(5,1);
//     printf("\n");
// }

//--------------- BONUS ---------------

// void print_list(t_list *list)
// {   
//     int index;

//     index = 0;
//     while (list != NULL)
//     {
//         printf("%d : %s , %p\n",index++,(char *)list->content,list->next);
//         list = list->next;
//     }
// }

// ft_lstnew
// int main()
// {	
//     char *content = "J'aime les chatons malades";

//     t_list 	*list = ft_lstnew((void *)content);
//     print_list(list);
//     free(list);
// }

// ft_lstadd_front
// int main()
// {	
//     char *content1 = "J'aime les chatons malades";
//     char *content2 = "Non je ne metterai pas les include Valentin <3";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_front(&list1, list2);
//     print_list(list2);
//     free(list2);
//     free(list1);
// }

//ft_lstsize
// int main()
// {	
//     char *content1 = "J'aime les chatons malades";
//     char *content2 = "Non je ne metterai pas les include Valentin <3";
//     char *content3 = "Les segfault c'est pour les zozos";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_front(&list1, list2);
//     ft_lstadd_front(&list2, list3);
//     printf("List size : %d\n",ft_lstsize(list3));
//     free(list3);
//     free(list2);
//     free(list1);
// }


//ft_lstlast
// int main()
// {	
//     char *content1 = "J'aime les chatons malades";
//     char *content2 = "Non je ne metterai pas les include Valentin <3";
//     char *content3 = "Les segfault c'est pour les zozos";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_front(&list1, list2);
//     ft_lstadd_front(&list2, list3);
//     printf("ALL LIST : \n");
//     print_list(list3);
//     printf("LAST ELEM : \n");
//     print_list(ft_lstlast(list3));
//     free(list3);
//     free(list2);
//     free(list1);
// }

// ft_lstadd_back
// int main()
// {	
//     char *content1 = "J'aime les chatons malades";
//     char *content2 = "Non je ne metterai pas les include Valentin <3";
//     char *content3 = "Les segfault c'est pour les zozos";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_back(&list1, list2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_back(&list1, list3);
//     print_list(list1);
//     free(list3);
//     free(list2);
//     free(list1);
// }

// void del_function(void *content)
// {   
//     printf("DELETE CONTENT : %s\n",(char *)content);
// }

// void del_function2(void *content)
// {   
//     return ;
// }

// void function(void *content)
// {   
//     printf("FUNCTION : %s\n",(char *)content);
// }

// void *function2(void *content)
// {   
//     char *test = "Ceci est un test";
//     return (test);
// }

// // ft_lstdelone
// int main()
// {	
//     char *content = "Non je ne metterai pas les include Valentin <3";
//     t_list 	*list = ft_lstnew((void *)content);

//     ft_lstdelone(list, &del_function);
// }

// ft_lstclear
// int main()
// {	
//     char *content1 = "Non je ne metterai pas les include Valentin <3";
//     char *content2 = "Mes main sont vraiment genial";
//     char *content3 = "Pourquoi je suis tout seul en coa air? ";
//     char *content4 = "Eh heu booouhhh , la terre c'est trop un truc de worms ca";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_back(&list1, list2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_back(&list1, list3);
//     t_list 	*list4 = ft_lstnew((void *)content4);
//     ft_lstadd_back(&list1, list4);

//     printf("BEFORE CLEAR : \n");
//     print_list(list1);
//     ft_lstclear(&list3, &del_function);
//     printf("PTR NULL : %p \n",list3);
//     free(list1);
//     free(list2);
// }

//ft_lstiter
// int main()
// {	
//     char *content1 = "Non je ne metterai pas les include Valentin <3";
//     char *content2 = "Mes main sont vraiment genial";
//     char *content3 = "Pourquoi je suis tout seul en coa air? ";
//     char *content4 = "Eh heu booouhhh , la terre c'est trop un truc de worms ca";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_back(&list1, list2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_back(&list1, list3);
//     t_list 	*list4 = ft_lstnew((void *)content4);
//     ft_lstadd_back(&list1, list4);

//     ft_lstiter(list1, &function);
//     free(list1);
//     free(list2);
//     free(list3);
//     free(list4);
// }

//ft_lstmap
// int main()
// {	
//     char *content1 = "Non je ne metterai pas les include Valentin <3";
//     char *content2 = "Mes main sont vraiment genial";
//     char *content3 = "Pourquoi je suis tout seul en coa air? ";
//     char *content4 = "Eh heu booouhhh , la terre c'est trop un truc de worms ca";

//     t_list 	*new_list;
//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_back(&list1, list2);
//     t_list 	*list3 = ft_lstnew((void *)content3);
//     ft_lstadd_back(&list1, list3);
//     t_list 	*list4 = ft_lstnew((void *)content4);
//     ft_lstadd_back(&list1, list4);

//     new_list = ft_lstmap(list1,&function2, &del_function);
//     printf("OLD LIST\n");
//     print_list(list1);
//     printf("NEW LIST\n");
//     print_list(new_list);
//     ft_lstclear(&list1, *del_function2);
//     ft_lstclear(&new_list, *del_function2);
// }