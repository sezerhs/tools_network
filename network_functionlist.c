#include <glib.h>
#include <glib/gstdio.h>
#include <gio/gio.h>
#include <arpa/inet.h>

//#include <yaml.h>
//#include "parse.h"
#include "error.h"
#include <stdio.h>


/* Check sanity for address types */

gboolean
is_ip4_address(const char* address)
{
    struct in_addr a4;
    int ret;

    ret = inet_pton(AF_INET, address, &a4);
    g_assert(ret >= 0);
    if (ret > 0)
        return TRUE;

    return FALSE;
}

gboolean
write_file(const char* string)
{

	FILE *file;
	file = fopen("configs","w");
	if(file == NULL){
		printf("error file not open\n");
		exit(1);
	}

	fprintf(file,"%s",string);
	fclose(file);
   return 0;
}

int main(){

	char str[100];

	printf( "Enter a value :");
	scanf("%s", str);

	if(is_ip4_address(str)){
		printf( "ok\n");
		write_file(str);
	}
   return 0;
}
