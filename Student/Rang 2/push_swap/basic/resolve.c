/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/27 17:16:07 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_push_swap(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return ;	

	//tester avec differemt nombre de chunk
	//on stock les resultats

	//On coupe en plusieur chunk 
	cut_chunck(data);

	repeat while a no vide

		//On scan
		scan_from_bot(data, a); //Return 0 si on trouve rien dans la stack qui appartient au chuck
		scam_from_top(data, a); //Return 0 si on trouve rien dans la stack qui appartient au chuck

		//Si un des deux retour 0 
			//on change de chuck ( nb_chunk++ ) 

		//Sinon
			//On bouge en a
			moov_chossen_one(data, a, b);
			//On bouge sur b
			comp_to_b_and_push(data, a, b);
			//Sort b
			//On mets l'element ajouté a la bonne place
			sort_b(data, b);

	// quand a est vide on push b dedans
	
	//On compare les resultats des test 

	//On refait le test avec la bonne valeur 



	// print_list(a, b);
	// while (!is_sorted(-1, a) && a->index > 0)
	// {
	// 	if (a->data[a->index - 1] > b->data[b->index - 1]
	// 		&& a->index > 0 && b->index > 0 && is_sorted(-1, a))
	// 		break ;
	// 	get_min(a, data);
	// 	get_rot_dir(a, data);
	// 	rot_min_to_top(a, data);
	// 	pb(a, b);
	// }
	// push_all_b(a, b);
	// print_list(a, b);
	// free(data);
}

//SOLUTION :

// On decoupe la range en chunk :

// Chunk 1 is MIN–(MAX - MIN / X * 1)

// Chunk 2 is (MAX - MIN / X * 1)–(MAX - MIN / X * 2)

// Chunk 3 is (MAX - MIN / X * 2)–(MAX - MIN / X * 3)

// Chunk 4 is (MAX - MIN / X * 3)–(MAX - MIN / X * 4)

// Chunk 5 is (MAX - MIN / X * 4)–MAX

// Step 1: Scan Stack A from the top to confirm if one of the numbers from Chunk 1 exist inside of it. 
// Let's call that number hold_first.

// Step 2: Scan Stack A again from the bottom and see if a different number from Chunk 1 exists in that list. 
// I’ll call that number hold_second.

// Step 3: Compare how many moves it would take to get hold_first and hold_second to the top

// Step 4: So the correct number is now on to top of Stack A. 
// But there are two things we need to check for before we push the number over to Stack B. 
// You have to check if the number you’re pushing is either bigger or smaller than all the other numbers in Stack B. 
// Since we’re not just pushing the smallest number one at a time. 

// Step 5: Repeat steps 1–4 until all the numbers in Chunk 1 no longer in Stack A.

// Step 6: Repeat steps 1–4 for the rest of the chunks so they are 
// handled in the same way and all of Stack A is inside of Stack B.

//Quand a est vide , push b dedans