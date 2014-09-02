#include <stdio.h>

int main(void) {
	printf("hello, world\n");

	system("pause");
	return 0;
}/*Jag öppnade upp VS2013 och skapade ett projekt med namnet HelloWorld.Därefter skapade jag en fil med namnet main.c.För att jag skulle kunna läsa texten i fönstret adderade jag raden system("pause"); samthar jag sett från kursboken att i int main() ska void placeras mellan paranteserna eftersom main i det här fallet inte tar in några argument så deklareras int main(void).För att kompilera som C i VS gjorde jag följande: Projekt->HelloWorld properties->Configuration Properties->C/C++ ->All Options ->Compile as Compile as C Code (T/S).Eftersom mah brukar förespråka VS har jag nu avinstallerat Xubuntu och GNU och installerat Windows med VS2013.Med GNU kan man använda -Wall så att man ser alla varningarna. I VS2013 kan Wall funktionen aktiverasnågra rader under "Compile as Compile as C Code (T/S)". Jag har inte använt VS på 1 år nu (använt GNU tillsammans med Sublime) men jag tycker intedet finns någon annan utvecklingsmiljö på marknaden som kan konkurera med alla dess funktioner, tillitlighet och stabilitet. Nackdelen är att den är krävandeför datorn att köra vilket man oftast påmins om på laptops.*/