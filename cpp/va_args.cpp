#include <vector>                                      
#include <iostream>                                    
#include <stdarg.h>                                    

namespace test {
void names(int l, char * d1, ...)                      
{                                                      

	va_list args;                                        
	va_start(args, d1);                                  
	fprintf(stderr, "Level_1: ");                        
	vfprintf(stderr, d1, args);                          
	va_end(args);                                        
	fprintf(stderr, "\n");                               
}                                                      
} //namespace test

#define NAME(level, ...) test::names(level, ##__VA_ARGS__);    


int main(void)                                         
{                                                      

	test::names(1, "jack1");                    
	test::names(1, "jack1: %d", 1);                            
	NAME(1, "JACK");                                     
	NAME(1, "JACK1: %d", 1);                             
	return 0;                                            
}                                                      

