/*
 * definiciones.cpp
 *
 *  Created on: 28 nov. 2018
 *      Author: luis
 */
#include "funciones.h"
char eliminado[100];


struct articulo{
	char nombre[100];
	float costo;
	float precio;
	int cantidad;

};
struct articulo productos[100] = {
	"GALLETAS", 0.5, 0.7, 10,
	"CARAMELOS",0.1, 0.2, 10,
	"GASEOSAS", 1.0, 1.5, 10,
	"FRITURAS", 0.5, 0.7, 10,
	"CHOCOLATE",1.0,1.5,10,
	"TELEVISOR",990.50, 1599.9, 10,
	"IMPRESORA",400, 999.9, 10,
	"ACEITE",4.8, 6.0, 10,
	"TALADRO",5.5, 6.5, 10,
	"MARTILLO",2.7, 3.5, 10,
	};
void titulo(){
    cout<<"\n"<<endl;
	cout<<"                        SISTEMA DE INVENTARIO PARA TIENDA                        "<<endl;
	cout<<"  ----------------------------------------------------------------------------   "<<endl;
	cout<<endl;
}
void opciones(){
	gotoxy(5,8);cout<<"<1> NUEVA VENTA ";
	gotoxy(5,10);cout<<"<2> NUEVA COMPRA ";
	gotoxy(5,12);cout<<"<3> INVENTARIO ";
	gotoxy(5,14);cout<<"<4> NUEVO PRODUCTO ";
	gotoxy(5,16);cout<<"<5> ELIMINAR PRODUCTO ";
	gotoxy(5,18);cout<<"<6> SALIR ";
}
void venta(){
 system("cls");
	float cantidad;
	cout<< "           Nueva venta          "<<endl;cin.ignore();
	cout<<"\nNombre del producto: ";cin.getline(eliminado,100,'\n');
   strupr(eliminado);
	for(int i=0;i<15;i++){
		if(strcmp(eliminado,productos[i].nombre)==0){

			cout<<"Cantidad: ";cin>>cantidad;
		if(cantidad>productos[i].cantidad){ cout<<"Stock insuficiente."<<endl;system("pause");system("cls");break;}
			productos[i].cantidad=productos[i].cantidad-cantidad;
			cout<<"  ----------------------------------------------------------------------------   "<<endl;
			cout<<"                                     RECIBO                                      "<<endl;
			cout<<"  ----------------------------------------------------------------------------   "<<endl;
			cout<<"Producto: "<<productos[i].nombre<<endl;
			cout<<"Precio por unidad: "<<"S/."<<productos[i].precio<<endl;
			cout<<"Cantidad: "<<cantidad<<endl;
			cout<<"Total a pagar: "<<"S/."<<productos[i].precio*cantidad<<endl;system("pause");system("cls");break;
			}
		else if(i>=14){
		    	        	   cout<<"No está en el registro"<<endl;system("pause");system("cls");
		    	           }
		}

}
void compra(){
	system("cls");
   float cantidad;
   int op2;
	cout<< "           Nueva compra          "<<endl; cin.ignore();
	cout<<"\nNombre del producto: ";cin.getline(eliminado,100,'\n');
	strupr(eliminado);
	for(int i=0;i<15;i++){
		if(strcmp(eliminado,productos[i].nombre)==0){
			cout<<"Cantidad: ";cin>>cantidad;
			productos[i].cantidad=productos[i].cantidad+cantidad;
			cout<<"Datos actualizados correctamente"<<endl;system("pause");system("cls");break;
		}
		else if(i>=14){
			cout<<"Producto no registrado"<<endl;
			cout<<"¿Registrar? <1>SI <2>NO ";cin>>op2;
			if(op2==1){ int cont=0;
			for(int i=0;i<15;i++){
		       if(productos[i].costo==0){
		    	   while(cont<1){
					cin.ignore();
				cout<<"Nombre del producto: ";cin.getline(productos[i].nombre,100,'\n');
				strupr(productos[i].nombre);
			    cout<<"Precio de compra: ";cin>>productos[i].costo;
			    cout<<"Precio de venta: ";cin>>productos[i].precio;
			    cout<<"Existencias: ";cin>>productos[i].cantidad;
			    cont++;
		    	   }
		          }
		        }
			cout<<"Datos actualizados correctamente"<<endl;system("pause");system("cls");

			}
			else{ system("cls");}
			}
	}



}
void inventario(){
	system("cls");
 int op;
		        cout<<"                               INVENTARIO                                        "<<endl;
		        cout<<"  ----------------------------------------------------------------------------   "<<endl;
			    gotoxy(0,4);cout<<"Producto";gotoxy(17,4);cout<<"Compra";gotoxy(30,4);cout<<"Venta";
			    gotoxy(43,4);cout<<"Stock";
		    for(int i=0;i<15;i++){
		    	if(productos[i].costo>0){
			gotoxy(0,i+6);cout<<productos[i].nombre;gotoxy(18,i+6);cout<<productos[i].costo;
			gotoxy(31,i+6);cout<<productos[i].precio;gotoxy(44,i+6);cout<<productos[i].cantidad;
		    	}
		    }
		    cout<<"\n\n";
		    cout<<"<1> NUEVO PRODUCTO "<<endl;
		    cout<<"<2> ELIMINAR PRODUCTO "<<endl;
		    cout<<"<3> VOLVER "<<endl;
		    cout<<"ACCIÓN: ";cin>>op;
		    if(op>3||op<1){
		    	system("cls"); inventario();
		    }
		    switch (op){
		    case 1:nuevo_p(); break;
		    case 2:eliminar_p(); break;
		    case 3: system("cls");break;
		    }
}
void nuevo_p(){
	system("cls");
           int cont=0;
			for(int i=0;i<15;i++){
		       if(productos[i].costo==0){
		    	   while(cont<1){

				cout<<"Nombre del producto: ";cin.ignore();cin.getline(productos[i].nombre,100,'\n');
				strupr(productos[i].nombre);
			    cout<<"Precio de compra: ";cin>>productos[i].costo;
			    cout<<"Precio de venta: ";cin>>productos[i].precio;
			    cout<<"Existencias: ";cin>>productos[i].cantidad;
			    cont++;
		    	   }
		          }
		        }
			cout<<"Datos actualizados correctamente"<<endl;system("pause");system("cls");
	}
void eliminar_p(){
	system("cls");
		cout<<"Qué producto eliminar: ";cin.ignore();cin.getline(eliminado,100,'\n');
		strupr(eliminado);
	    for(int i=0;i<15;i++){
	    	if(strcmp(eliminado,productos[i].nombre)==0){

	           productos[i].costo=0;
	           productos[i].precio=0;
	           productos[i].cantidad=0;
	           cout<<"Datos actualizados correctamente"<<endl;break;;
	          }
	    	 if(i>=14){
	    	        	   cout<<"No está en el registro"<<endl;
	    	           }
}
}
void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	   COORD coord;
	   hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	   coord.X = x; coord.Y = y;
	   SetConsoleCursorPosition (hConsoleOutput, coord);
}
void login(){
	char temp_u[100],temp_p[100];
	char user[]="luis";
	char pass[]="holaqtal";
	char alf[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
      //Cifrado César
		    int j;
			for(int i=0;i<strlen(pass);i++){
			  j=0;
			  while(j<52){
			   if(pass[i]==alf[j] && (j<23||(j>=26 &&j<49))){
			    pass[i]=alf[j+3];
			    j=52;
			      }
			   if(pass[i]==alf[j] && (j>=23 && j<26)){
			       if(pass[i]=='x'){
			        pass[i]='a';
			    }
			    if(pass[i]=='y'){
			        pass[i]='b';
			    }
			    if(pass[i]=='z'){
			        pass[i]='c';
			    }
			    j=52;
			   }
			   if(pass[i]==alf[j] && (j>=49 && j<52)){
			       if(pass[i]=='X'){
			        pass[i]='A';
			    }
			    if(pass[i]=='Y'){
			        pass[i]='B';
			    }
			    if(pass[i]=='Z'){
			        pass[i]='C';
			    }
			    j=52;
			   }
			      j++;
			  }
			 } //Acaba cifrado
	titulo();

	cout<<"Usuario ("<<user<<"): ";cin.getline(temp_u,100,'\n');
	cout<<"Contraseña ("<<pass<<"): ";cin.getline(temp_p,100,'\n');
	if(strcmp(user,temp_u)==0&&strcmp(pass,temp_p)==0){
		system("pause");system("cls");
	}
	else{ cout<<"Usuario y/o contraseña incorrectos."<<endl;system("pause");system("cls");login();}

}



