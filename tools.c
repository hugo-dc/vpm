/*
 * tools.c
 * 
 * Copyright 2012 Miguel Angel Reynoso <miguel@vacteria.org>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include "tools.h"

bool test(unsigned short int mode, char* target)
{
	/*
	 * Modes :
	 * 1 = TRUE if exist, have access R permissions and is a regular file
	 * 2 = TRUE if exist, have access R permissions and is a directory
	 */
	
	
	/*
	* Firs get a full path of target. If file does not exist
	* or have not permission for read them, then return error
	*/
	char fullpath[PATH_MAX+1];
	realpath(target,fullpath);
	if (fullpath == NULL)
	{
		perror(target);
		return(false);
	}
	
	/* Now, run stat() over full path file */
	struct stat buf;
	int ret = stat(fullpath,&buf);
	if ( ret == -1 )
	{
		perror(target);
		return(false);
	}
	
	/* Evalue macros depending off mode */
	switch(mode)
	{
		case 1 :
			if (!S_ISREG(buf.st_mode))
			return(false);
			break;
		case 2 :
			if (!S_ISDIR(buf.st_mode))
			return(false);
			break;
	}
	
	return(true);
}
