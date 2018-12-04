#include "funciones.h"



int main() {
	login();

		int op1;

   //Empieza el programa con el menú de opciones.
	do{

		titulo();
        opciones();
        gotoxy(5,20);cout<<"ACCIÓN: ";cin>>op1;
             if (op1<1||op1>6){
			system("cls"); main();
		           }

		switch(op1){
		case 1: venta(); break;
		case 2: compra(); break;
		case 3: inventario();break;
		case 4: nuevo_p();break;
		case 5: eliminar_p();break;


	}
	} while(op1!=6);
	return 0;
}





