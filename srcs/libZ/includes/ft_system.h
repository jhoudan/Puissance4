/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:25:08 by mressier          #+#    #+#             */
/*   Updated: 2016/02/23 19:25:16 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSTEM_H
# define FT_SYSTEM_H

# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <time.h>

#include "libft.h"

enum e_file_mode
{
	FIFO = 0,
	SPE_CHAR,
	SPE_BLK,
	DIRECTORY,
	SYM_LINK,
	SOCK_LINK,
	REG_FILE,
	UNKNOW
};

typedef struct 		s_maj_min_dev
{
	int		major_dev;
	int		minor_dev;
}						t_maj_min_dev;

/*
**  	------------------------------------------------------
**  	|					Get file info        	         |
**  	------------------------------------------------------
*/

enum e_file_mode		ft_get_mode_file(mode_t file_mode);

char					*ft_get_owner_name(uid_t uid);
char					*ft_get_group_name(gid_t grp_id);
char					*ft_get_file_right(mode_t file_mode);
enum e_file_mode		ft_get_file_mode(mode_t file_mode);
t_maj_min_dev			ft_get_maj_and_min_dev(dev_t dev_id);

/*
**  	------------------------------------------------------
**  	|						Date 		       	         |
**  	------------------------------------------------------
*/

char					*ft_interpret_time(time_t value_time);
char					*ft_get_part_of_date(time_t t);

#endif
