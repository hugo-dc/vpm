/*
 * common.c
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
#include <stdbool.h>
#include "common.h"
#include "tools.h"
#include "libarchive.h"

bool parse_package(char* pkg)
{		
	if(!test(1,pkg))
		return(false);

	tar_file_format(pkg);
	
	return(true);
}
