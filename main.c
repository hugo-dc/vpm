/*
 * sin título.c
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
#include <getopt.h>
#include "main.h"
#include "messages.h"
#include "list.h"
#include "tools.h"

// Control variables
char*  root    = "/";
unsigned short int verbose = 0;
unsigned short int silent  = 0;
unsigned short int rundeps = 1;
unsigned short int stop    = 1;

int main(int argc, char **argv)
{
	progname = argv[0];
	
	unsigned short int action = 0;
	short int next_opt;
	char* short_opts = "mhvs";
	const struct option long_opts[] =
	{
		{"mkpkg",      0, NULL, 'm'},
		{"help",       0, NULL, 'h'},
		{"verbose",    0, NULL, 'v'},
		{"silent",     0, NULL, 's'},
		{"nostop",     0, NULL,  0 },
		{NULL,		   0, NULL,  0 }
	};
	
	while(1)
	{
		next_opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
		if(next_opt == -1)
			break;
	
		switch(next_opt)
		{
			case 'h' :
				action = 1;
				break;
			case 'm' :
				action = 2;
				break;
			case 'v' :
				verbose = 1;
				silent = 0;
				break;
			case 's' :
				verbose = 0;
				silent = 1;
				break;
			case 0 :
				stop = 0;
				break;
			case '?' :
				exit(EXIT_FAILURE);
		}
	}
	
	if (action == 0)
	{
		printf(_("No main options was selected\n"));
		exit(EXIT_FAILURE);
	} else {
		if (action == 1)
		{
			msg_help();
			exit(EXIT_SUCCESS);			
		} else {
			int i=0;
			int c=1;
			char* pkg = NULL;
			
			list_t* pkgv = new_list(c);
			if (optind < argc && optind > 1)
			{	
				for (i=optind; i<argc; i++)
				{
					resize_list(pkgv,c);
					add_list(pkgv,c-1,argv[i]);
					c++;
				}
			}
			size_t pkgc = size_list(pkgv);
			
			switch(action)
			{
				case 2 :
					for (i=0; i<pkgc; i++)
					{
						pkg=(char*)get_list(pkgv,i);
						printf("%d\n",stop);
						
						if(test(1,pkg))
						{
							printf("%s : True\n",pkg);
						} else {
							printf("%s : False\n",pkg);
						}
					}
			}
		}
	}
	
	return(0);
}

