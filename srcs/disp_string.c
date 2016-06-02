/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:06:39 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 15:07:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void disp_string(float x, float y, char *str)
{
    int i;

    i = 0;
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2d(x, y);
    while (str[i])
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , str[i++]);
}
