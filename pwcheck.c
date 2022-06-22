#include <stdio.h>
#include <stdlib.h>


//funkce porovnani stringu
int compstr(char *str1,char * str2){
    for(int i =0; ;i++){
        if(str1[i] != str2[i])
        {
            return str1[i] < str2[i] ? -1:1;
        }
        if (str1[i] == '\0')
        {
            return 0;
        }
    }   
}


//funkce porovnani char 
int compstr2(char a,char b)
{
    return(a == b);
}


//funkce vyhledani velka a mala pismena
int per(char *heslo)
{
    for(int i = 0;heslo[i] != '\0';i++)
        
        {
            if(heslo[i] >= 'A' && heslo[i] <= 'Z')
            {
              for(int i = 0;heslo[i] != '\0';i++)
                {
                    if(heslo[i] >= 'a' && heslo[i] <= 'z')
                    {
                      return 1;
                    
                    } 
                }
            }
        }

    return 0;
}


int delka(char *slovo)
{
    float delka = 0;

    for(int i=0; slovo[i] != '\0'; i++)
    {
    if(slovo[i] != 10 && slovo[i] != 13)
	//printf("%.2f: %c\n",delka,slovo[i]);
    delka++;
    }
    //delka--;
	
	
    return delka;


	
}



int per11(char *heslo)
{
    for(int i = 0;heslo[i] != '\0';i++)
    {
        if(heslo[i] >= 'a' && heslo[i] <= 'z')
                    {
                      return 1;
                    
                    } 
    }
    
    
    return 0;
}




//funkce vehledani cisla v stringu(heslo)

int per3(char *heslo)
{
    char cisla[11] = {"0123456789"}; 
    for(int i = 0;heslo[i] != '\0';i++)
    {
        for(int g = 0;g<=9;g++)
        {
            if(compstr2(heslo[i],cisla[g]))
            {
                return 1;
            }
        }
    }
return 0;
}

//funkce speciГЎlnГ­ znaky

int per4(char *heslo)
{
    char cisla[33] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126}; 
    for(int i = 0;heslo[i] != '\0';i++)
    {
        for(int g = 0;g<=33;g++)
        {
            if(compstr2(heslo[i],cisla[g]))
            {
                return 1;
            }
        }
    }
return 0;
}





//funkce sekvenci stejnych znaku

int sek_zn_2(char *heslo,int dlina,int i_pointer,int g_pointer)
{
    int ticker = 0;
    for(;dlina != 0;dlina--)
    {
        if(compstr2(heslo[i_pointer],heslo[g_pointer]))
        {
            g_pointer++;
            ticker = 1;
        }
        else
        {
            ticker = 0;
        }
    }
    return ticker;
}

int sek_zn(char *heslo,int dlina)
{
    for(int i = 0;heslo[i] != '\0';i++)
    {
        for(int g = 0;heslo[g] != '\0';g++)
        {
            if(compstr2(heslo[i],heslo[g]))
            {
                if(sek_zn_2(heslo,dlina,i,g))
                return 1;
            }
        }
    }
    return 0;        
}



//funkce sekvenci stejnГ© podЕ™etД›zce

int sekvence_2(char *heslo,int dlina,int i_pointer,int g_pointer)
{
    int ticker = 0;
    for(;dlina != 0;dlina--)
    {
       if(compstr2(heslo[i_pointer],heslo[g_pointer]))
       {
           i_pointer++;
           g_pointer++;
           ticker = 1;
           //printf("%s %d\n",heslo,ticker);
       }
       else
       {
           ticker = 0;
           //printf("%d",ticker);
       }
    }

    return ticker;
}





int sekvence (char *heslo,int dlina)
{
    for(int i = 0;heslo[i] != '\0';i++)
    {
        for(int g = i+1;heslo[g] != '\0';g++)
        {
            if(compstr2(heslo[i],heslo[g]))
            {
                if(sekvence_2(heslo,dlina,i,g))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}






struct St
{
    int cur_delka;
    int min_delka;
    float all_delka;
    float kolik_slov;

}Stats;


void unik( char heslo,char *unik_symb)
{
       int i = heslo; 
       if(i != 10 && i != 13)
       unik_symb[i] = '1';
        
}
int cislo(char a)
{
    if(a >= '0' && a <= '9')
    {
        
    return 1;
    }
   return 0; 
}

int my_atoi(char *argv1)
{
  
    for(int i = 0;argv1[i] != '\0';i++)
    {
        if(!cislo(argv1[i]))
        {
            return 1;
        }
    }
return 0;
}
int my_atoi2(char *argv2)
{
    for(int i = 0;argv2[i] != '\0';i++)
    {
        if(!cislo(argv2[i]))
        {
            //printf("%d",argv2[i]);
            return 1;
        }
    }

    return 0;
}




int main(/*РєРѕР» Р°СЂРі*/int argc, char *argv[]/*РїРѕР»Рµ Р°СЂРі*/){

    int level = atoi(argv[1]); 
    int param = atoi(argv[2]); 

    
    if(argc < 3 || argc > 4)
    {
        
        fprintf(stderr,"Error\n");
        return 1;
    }
    


    if(level < 1 || level > 4)
    {
        fprintf(stderr,"Error\n");
        return 1;
    }
    
    if(argv[2] != NULL)
    {
	if(!(!compstr(argv[2],"--stats"))	)
{
    int tick  = delka(argv[2]);
    if(tick > 19)
    {
        param = 99;
    }
    if(param < 1)
    {
        fprintf(stderr,"Err\n");
        return 1;
    }
}
    }
  
if(argv[2] != NULL && argv[1] != NULL)
{  
    if(!(!compstr(argv[2],"--stats")))
{
    if(my_atoi(argv[1]))
    {
       fprintf(stderr,"Error\n");
        return 1;
    }
    if(my_atoi2(argv[2]))
    {
       fprintf(stderr,"Er\n");
        return 1;
    }
 }  
}



    if (argv[3] != NULL)
    {
    if(!(!compstr(argv[3],"--stats"))) 
    {
         fprintf(stderr,"Error\n");
        return 1;
    }
    }
    
    
    
    
    
    

    struct St *stats = &Stats;
    //struct St stats;
    
    char heslo[102]; // ...\n'\0'
    char unik_symb[129];

    stats->min_delka = 101;
    stats->kolik_slov = 0.0;
    stats->all_delka = 0.0;
    //int level = atoi(argv[1]); 
    //int param = atoi(argv[2]);  
    
    while(fgets(heslo,102,stdin) != NULL)
    {   
       

        int a = delka(heslo);
        //printf("DELKA: %d",a);
        if(a > 100)
        {
            fprintf(stderr,"Errr\n");
            return 1;
        }
        
        
        
        //float pomoc= delka(heslo);
        //printf("%.1f\n",pomoc);



        
        switch(level) 
        {
        case 1:
            if(per(heslo))
            {
                printf("%s",heslo);
            }
            break;
        
        case 2:
            switch(param)
            {
             case 1:
                if(per(heslo))
                {
                    printf("%s",heslo);
                }
             break;


             case 2:
                if(per(heslo))
            {
                printf("%s",heslo);
            }
             break;


             case 3:
                if(per(heslo) && per3(heslo))
                {
                    printf("%s",heslo);
                }
             break; 


             case 4:
                if(per(heslo) && per4(heslo) && per3(heslo))
                {
                   printf("%s",heslo); 
                }
             break;  
             default:
                if(argv[2] != NULL)
                if(per(heslo) && per4(heslo) && per3(heslo))
                {
                   printf("%s",heslo); 
                }
             break; 

             
            }   
            break;
        case 3:
            switch(param)
            {
                case 1:
                if(per(heslo) && !sek_zn(heslo,param))
                {
                    printf("%s",heslo);
                }
                break;
                case 2:
                if(per(heslo) && !sek_zn(heslo,param))
                {
                    printf("%s",heslo);
                }

                break;
                case 3:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo))
                {
                    printf("%s",heslo);
                }
                break;
                case 4:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo) && per4(heslo))
                {
                    printf("%s",heslo);
                }
                break;
                default:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo) && per4(heslo))
                {
                    printf("%s",heslo);
                }
                break;
            }
             
            
            
            
            
            break;
         case 4:
            switch(param)
            {
                case 1:
                if(per(heslo) && !sekvence(heslo,param) && !sek_zn(heslo,param))
                {
                    printf("%s",heslo);
                }
                break;
                case 2:
                if(per(heslo) && !sekvence(heslo,param) && !sek_zn(heslo,param))
                {
                    printf("%s",heslo);
                }

                break;
                case 3:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo) && !sekvence(heslo,param))
                {
                    printf("%s",heslo);
                }
                break;
                case 4:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo) && per4(heslo) && !sekvence(heslo,param))
                {
                    printf("%s",heslo);
                }
                break;

                default:
                if(per(heslo) && !sek_zn(heslo,param) && per3(heslo) && per4(heslo) && !sekvence(heslo,param))
                {
                    printf("%s",heslo);
                }
                break;
            }   



        break;     
        } 

       
        

        for(int i = 0;heslo[i] != '\0';i++)
        {
            unik(heslo[i],unik_symb);
        }
        stats->all_delka +=delka(heslo);
        
	stats->cur_delka = delka(heslo);
	if(stats->cur_delka != 0)
	{
        ++stats->kolik_slov;
	}
if(stats->cur_delka != 0)
	{

        if((stats->cur_delka  < stats->min_delka))
        {
            stats->min_delka = stats->cur_delka;
        }
   }
    
   
   
    }
   
   
   
   
    if(stats->kolik_slov == 0)
    {
        stats->kolik_slov = 1;
    }

    if(stats->min_delka == 101)
    {
        stats->min_delka = 0;
    }
    if (argv[3] != NULL)
    {
    
    if((!compstr(argv[3],"--stats")))
    {
    int a = 0;
    for(int i = 0;i<128;i++)
    {
    if(compstr2(unik_symb[i],'1')) 
    {
        a++;
    }
    
    }


    printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f\n",a,stats->min_delka,(stats->all_delka/stats->kolik_slov));
    
    }
    
    }

    if (argv[2] != NULL)
    {
    
    if((!compstr(argv[2],"--stats")))
    {
    int a = 0;
    for(int i = 0;i<128;i++)
    {
    if(compstr2(unik_symb[i],'1')) 
    {
        a++;
    }
    
    }


    printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f\n",a,stats->min_delka,(stats->all_delka/stats->kolik_slov));
    
    }
    
    }	

   
    
return 0;
}
