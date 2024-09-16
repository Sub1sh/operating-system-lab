//To read data from the standard input device and write it on screen
#include <unistd.h>
int main()
{
	char buff[20];
	read(0,buff,10); 
	write(1,buff,10);
}
