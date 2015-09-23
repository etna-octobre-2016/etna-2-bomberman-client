/*
** my_fondation.h for Fondation in /home/clementcosson/C/Fondation/cosson_c/headers
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Thu Jan  8 14:41:31 2015 COSSON Clement
** Last update Wed Sep 23 12:14:23 2015 COSSON Clement
*/
#ifndef __MY_FONDATION__
#define __MY_FONDATION__
#define MAX_LEN_IP_V6 39
#define PORT_MIN 1024
#define PORT_MAX 65535
#define T_MAX_TABLE 250
#define CMD_IGN "Les commandes de plus de 250 sont ignorées\n"
#define IP_V6_NOT_IMPL "La connection en IP v6 n'est pas implémenté\n"
#define CANT_NOT_CREATE_SOCK "Impossible de créer une socket"
#define CON_OK "Connection OK"
#define CON_KO "Erreur de connection"

/*
**	--ip [adresse ip du serveur]
**	--port [port du serveur]
**	--cycle [nombre entier de microsecondes correspondant à un cycle]
**	-v (active le mode verbeux)
**	--log [adresse absolue du log]
**	--size [nombre entier correspondant à la taille de la map]
*/
typedef struct		s_args
{
  int			v_ip;
  char			ip[MAX_LEN_IP_V6];
  int			v;
  int			size;
  unsigned short	port;
  int			d_socket;
  char			*log;
  int			cycle;
}			t_args;

/*
** ============================================================================
** ============================== my_bomberman_part 1 =========================
** ============================================================================
*/

/*
**      fonctions pour afficher un usage
*/
void	print_usage();

/*
**      fonctions de vérification des paramètres
**      retourne 1 si l'IP et le port sont bien rensigné
**      0 dans le cas contraire
*/
int	check_if_params_are_corrects(int ac, char **av, t_args *s_as);

/*
**	fonction qui check quelle type d'ip lutilisateur semble utiliser
**	retourn 4 pour un V4, 6 pour une V6 et 0 si ni V4 ni V6
*/
int	check_if_look_ip(char *str,  t_args *s_as);

/*
**	fonction qui check que l'ip (v4 ou v6 est correct ou non)
*/
int	check_if_ip_is_correct(int version_ip, char *str, int i, int index);

/*
**	check si le port est numérique et bien compris entre
**	PORT_MIN && PORT_MAX
*/
int	check_if_port_is_correct(char *port);

/*
** ============================================================================
** ============================== my_bomberman_part 2 =========================
** ============================================================================
*/

/*
**		Lit l'entrée standard et redirige sur la fonction qui traite le
**		Write -- Read (des sockets) ou quit le programme
*/
void	read_stdin(int socket_director, char big_table[T_MAX_TABLE]);

/*
**		Send cmd amd display message
*/
void	chat_with_server(int socket_director, char big_table[T_MAX_TABLE]);

/*
**		Remet le tableau à 0 (comme c'est une chaine de charactère ça devient)
**		un caractere null;
*/
void	reset_big_table(char big_table[T_MAX_TABLE]);

/*
**		Fonction de connection au serveur
*/
int	connect_to_server(t_args *s_as);

/*
**		fonction qui renvoi un charactere enmvoyé sur la socket
*/
char	my_getsocketchar(int socket_director);

/*
** ============================================================================
** ============================== my_bomberman_part 3 =========================
** ============================================================================
*/
void	give_me_the_map(int socket_director);
#endif

