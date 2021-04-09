#include "includes/main.h"
#include "includes/rofis_constructor.h"


int main(int argc, char const *argv[])
{
	rofi test;
	test.buffer = 32;
	test.text(test, "oui");

	printf("%s\n", test.choice);
}

