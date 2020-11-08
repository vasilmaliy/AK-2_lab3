#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){
	opterr=0;
	const char* short_options = "hcrsf:";
	
	
	int flag_h = 0;
    int flag_s = 0;
    int flag_r = 0;
    int flag_c = 0;
    int flag_f = 0;

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"size",optional_argument,NULL,'s'},
		{"reverse",no_argument,NULL,'r'},
		{"check",no_argument,NULL,'c'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){
			switch(rez){
			case 'h': {
				if (flag_h > 0) {
					continue;
				}
				flag_h = 1;
				printf("Arg: Help\n");
				break;
			};
			case 's': {
				if (flag_s > 0) {
					continue;
				}
				flag_s = 1;
				printf("Arg: Size\n");
				break;
			};
			case 'c': {
				if (flag_c > 0) {
					continue;
				}
				flag_c = 1;
				printf("Arg: Check\n");
				break;
			};
			case 'r': {
				if (flag_r > 0) {
					continue;
				}
				flag_r = 1;
				printf("Arg: Reverse\n");
				break;
			};
	
			case 'f': {
				if (flag_f > 0) {
					continue;
				}
				flag_f = 1;
				printf("file = %s\n",optarg);
				break;
			};
			case '?': default: {
				printf("unknown option\n");
				break;
			};
		};
	};
	return 0;
};
