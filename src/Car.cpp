using namespace std;

#include <iostream>
#include <string>
#include "Car.h"

string coca_intestazione(){
    string inte;
    inte = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
    inte += "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n";
    return inte;
}

string coca_sfondo(){
    string sfon;
    sfon = "<rect  x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\"/>\n"; 
    return sfon;
}

string coca_fine(){
    string fin;
    fin = "</svg>\n";
    return fin;
    
}

void coca_trycarrozzeria(coca_device* macch){
    cout << "Inserire la lunghezza della macchina: ";
    cin >> macch->car.width;
    cout << "Inserire l'altezza della macchina: ";
    cin >> macch->car.height;
}

string coca_carrozzeria(coca_device* macch){
    string carr;
    carr = "<rect  x=\"100\" y=\"430\" rx=\"10\" ry=\"10\"";
    carr += " width=\"" + to_string(macch->car.width) + "\"";
    carr += " height=\"" + to_string(macch->car.height) + "\"";
    carr += " style=\"stroke-width:3;stroke:rgb(0,0,0)\" fill=\"red\"/>\n"; 
    return carr;
}

void coca_tryruote(coca_device* macch){

    cout << "Scegliere il diametro delle ruote" << endl;
    cout << "RUOTA SINISTRA" << endl;
    while(macch->sx.cerchione != 16 && macch->sx.cerchione != 17 && macch->sx.cerchione != 18){
        cout << "Ruote disponibili:" << endl;
        cout << "Ruote 16 pollici\nRuote 17 pollici\nRuote 18 pollici\n" << endl;
        cin >> macch->sx.cerchione;
            if(macch->sx.cerchione != 16 && macch->sx.cerchione != 17 && macch->sx.cerchione != 18){
                cout << "Ruote non disponibili" << endl;
            }
    }
    cout << "RUOTA DESTRA:" << endl;
    while(macch->dx.cerchione != 16 && macch->dx.cerchione != 17 && macch->dx.cerchione != 18){
        cout << "Ruote disponibili:" << endl;
        cout << "Ruote 16 pollici\nRuote 17 pollici\nRuote 18 pollici\n" << endl;
        cin >> macch->dx.cerchione;
            if(macch->dx.cerchione != 16 && macch->dx.cerchione != 17 && macch->dx.cerchione != 18){
                cout << "Ruote non disponibili" << endl;
            }
    }

    macch->sx.cerchione += 8;
    macch->sx.ruota = macch->sx.cerchione * 1.6;

    macch->dx.cerchione += 8;
    macch->dx.ruota = macch->dx.cerchione * 1.6;
}

void coca_tryassetto(coca_device* macch){
    int x;
    cout << "Sceglier l'assetto della macchina" << endl;
        while(x!= 1 && x!= 2 && x!= 3){
        cout << "Assetti disponibili:" << endl;
        cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
        cin >> x;
            if(x!= 1 && x!= 2 && x!= 3){
            cout << "Assetto non disponibile" << endl;
            }
        }
    switch (x){
        case 1:
            macch->sx.centrox = 165;
            macch->dx.centrox = 375;
            break;
        case 2:
            macch->sx.centrox = 170;
            macch->dx.centrox = 370;
            break;
        case 3:
            macch->sx.centrox = 175;
            macch->dx.centrox = 365;
            break;

        default:
            break;
        }
}

string coca_ruote(coca_device* macch){
    string ruo;
    // Ruota sinistra
    ruo = "<circle ";
    ruo += "cx=\"" + to_string(macch->sx.centrox) + "\" cy=\"500\" ";
    ruo += "r=\"" + to_string(macch->sx.ruota) + "\" stroke=\"black\" stroke-width=\"3\" fill=\"black\" />\n";
    // Cerchione sinistra
    ruo += "<circle ";
    ruo += "cx=\"" + to_string(macch->sx.centrox) + "\" cy=\"500\" ";
    ruo += "r=\"" + to_string(macch->sx.cerchione) + "\" stroke=\"black\" stroke-width=\"3\" fill=\"black\" />\n";
    // Ruota destra
    ruo += "<circle ";
    ruo += "cx=\"" + to_string(macch->dx.centrox) + "\" cy=\"500\" ";
    ruo += "r=\"" + to_string(macch->dx.ruota) + "\" stroke=\"black\" stroke-width=\"3\" fill=\"black\" />\n";
    // Cerchione destra
    ruo += "<circle ";
    ruo += "cx=\"" + to_string(macch->dx.centrox) + "\" cy=\"500\" ";
    ruo += "r=\"" + to_string(macch->dx.cerchione) + "\" stroke=\"black\" stroke-width=\"3\" fill=\"black\" />\n";

    return ruo;
}