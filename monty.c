#include "monty.h"

/**
 * main - demo
 *
 * Return: Always 0
 */

int main(void)
{
	FILE *fd;
	ssize_t read;
	size_t n = 0;
	char *buf = NULL;
	char *cmd = NULL, *tok;
	stack_t *elem;

	fd = fopen("Emmanuel", "r");
	
	if (fd == NULL)
	{
		printf("An Error Occured\n");
	}
	else
	{
		printf("File Opened Successfully...\n\n");
		while (1)
		{
			read = getline(&buf, &n, fd);
			if (read == -1)
				break;
			else
			{
				printf("%s\n", buf);
				tok = strtok(buf, "\t\r\n\v\f");
				while (1)
				{
					if (tok == NULL)
					{
						break;
					}
					else
					{	
						if (strcmp(tok, "push") == 0)
						{
							strcpy(cmd, tok);
						}
						tok = strtok(NULL, "\t\r\n\v\f");
						if (isdigit(atoi(tok)) != 0)
						{
							elem = malloc(sizeof(stack_t));
							elem->n = atoi(tok);
							elem->next = NULL;
							elem->prev = NULL;
							tok = strtok(NULL, "\t\r\n\v\f");
						}
						else
						{
							printf("not integer");
							break;
						}
					}
				}
			}
		}
		printf("1 - %d\n", elem->n);
		fclose(fd);
	}


	return (0);
}
