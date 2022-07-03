#include "pipex_bonus.h"


				/// AFFICHAGE LISTE CHAINÉ ///
void ft_debug_cmd(t_pipex pipex)
{
	int i;

	i = 0;
	while (pipex.cmd)
	{
		printf("------------------\n");
		printf("addr : %p\n",pipex.cmd);
		printf("num_cmd = %d\n",pipex.cmd->num_cmd);
		printf("cmd = %s\n",pipex.cmd->cmd);
		printf("ARG_CMD = ");
		while (pipex.cmd->arg_cmd[i])
		{
			printf("%s ",pipex.cmd->arg_cmd[i]);
			i++;
		}
		printf("\n");
		printf("pid = %d\n",pipex.cmd->pid);
		printf("next = %p\n",pipex.cmd->next);
		printf("------------------\n\n");
		pipex.cmd = pipex.cmd->next;
	}
	printf("nombre ARGV = %d\n",pipex.n_cmd);
}