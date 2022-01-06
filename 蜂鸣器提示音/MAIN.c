#include <REGX52.H>
#include "key.h"
#include "xs.h"
#include "delay.h"
#include "bz.h"

unsigned char keyn;
void main()
{     sx(1,0);
      while(1)
     {
      keyn=key();
			 if(keyn)
			 { 
				bztime(100);
			 sx(1,keyn);
				 
			 }
      }
}


