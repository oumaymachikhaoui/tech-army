
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}



int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int d)
{

  SDL_Color col;
  if(d==0)//right
  {
    col=GetPixel(calque,posperso.x+perso->w ,posperso.y+(perso->h/2));
  }
else  if(d==1)//left
  {
    col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  }
else  if(d==2)//up
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) ,posperso.y);
  }
else  if(d==3)//down
  {
    col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
  }
  
if ((col.r==0)&&(col.b==255)&&(col.g==0))
{
	printf("collision \n");
  return 1;
}
else 
{
	printf("pas de collision \n");
	return 0;
}
}

