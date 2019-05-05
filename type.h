#ifndef TYPE_H_INCLUDE
#define TYPE_H_INCLUDE
typedef struct 
{
	SDL_Surface *t[4];
	SDL_Rect pos;
}unit; 
bool collision(SDL_Rect* rect1,SDL_Rect* rect2);
void anim_hero(SDL_Surface *t[]);
void anim_hero_reverse(SDL_Surface *t[]);
void anim_enemy(SDL_Surface *t[]);
void display(SDL_Surface *ecran,SDL_Surface *bg,SDL_Surface *img,SDL_Surface *img1,SDL_Rect pos1,SDL_Rect pos2);
void AItest();
void anim_enemy_attack(SDL_Surface *t[]);
void anim_enemy_attack_reverse(SDL_Surface *t[]);

#endif