#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __linux__
#  define K_W		119
#  define K_S		115
#  define K_A		97
#  define K_D		100
#  define K_UP		65362
#  define K_DOWN	65364
#  define K_LEFT	65361
#  define K_RIGHT	65363
#  define K_ESC		96 //65307
# else
#  define K_W		13
#  define K_S		1
#  define K_A		0
#  define K_D		2
#  define K_UP		126
#  define K_DOWN	125
#  define K_LEFT	123
#  define K_RIGHT	124
#  define K_ESC		53
# endif

#endif
