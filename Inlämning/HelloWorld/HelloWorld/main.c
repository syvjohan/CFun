#include <stdio.h>

int main(void) {
	printf("hello, world\n");

	system("pause");
	return 0;
}/*Jag �ppnade upp VS2013 och skapade ett projekt med namnet HelloWorld.D�refter skapade jag en fil med namnet main.c.F�r att jag skulle kunna l�sa texten i f�nstret adderade jag raden system("pause"); samthar jag sett fr�n kursboken att i int main() ska void placeras mellan paranteserna eftersom main i det h�r fallet inte tar in n�gra argument s� deklareras int main(void).F�r att kompilera som C i VS gjorde jag f�ljande: Projekt->HelloWorld properties->Configuration Properties->C/C++ ->All Options ->Compile as Compile as C Code (T/S).Eftersom mah brukar f�respr�ka VS har jag nu avinstallerat Xubuntu och GNU och installerat Windows med VS2013.Med GNU kan man anv�nda -Wall s� att man ser alla varningarna. I VS2013 kan Wall funktionen aktiverasn�gra rader under "Compile as Compile as C Code (T/S)". Jag har inte anv�nt VS p� 1 �r nu (anv�nt GNU tillsammans med Sublime) men jag tycker intedet finns n�gon annan utvecklingsmilj� p� marknaden som kan konkurera med alla dess funktioner, tillitlighet och stabilitet. Nackdelen �r att den �r kr�vandef�r datorn att k�ra vilket man oftast p�mins om p� laptops.*/