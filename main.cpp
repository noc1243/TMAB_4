#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "classes.h"
#include "base_nomes.h"

#define NUM_AREAS_DE_CONHECIMENTO 10
#define SIZE_AREAS_DE_CONHECIMENTO 3

#define NUM_LOCAL_NOMES 100
#define SIZE_LOCAL_NOMES 5


using namespace std;

vector <int> geraCodigosAleatorios ()
{
    vector <int> codigos;
    for (int i=0; i<10000; i ++)
    {
        codigos.push_back(i);
    }

    return codigos;
}

int getCodigo (vector <int> &codigos)
{
    int rndIndex = rand() % codigos.size();
    int rndValue = codigos[rndIndex];
    codigos.erase(codigos.begin() + rndIndex);
    
    return rndValue;
}

vector <Area_de_Conhecimento>  geraAreas ()
{
    vector <Area_de_Conhecimento> areas;
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Area;
    int cd_Area;
    
    for (int i=0; i< NUM_AREAS_DE_CONHECIMENTO; i++)
    {
        cd_Area = getCodigo (codigos);
        nm_Area = AREA_DE_CONHECIMENTO [rand() % SIZE_AREAS_DE_CONHECIMENTO];
        Area_de_Conhecimento area (cd_Area, nm_Area);
        areas.push_back(area);
    }
    
    return areas;
}

vector <Local> geraLocais ()
{
    vector <Local> locais;
    vector <int> codigos = geraCodigosAleatorios ();
    int num_Telefone;
    string nm_Local;
    int cd_Local;
    
    for (int i=0; i<NUM_LOCAL_NOMES; i++)
    {
        cd_Local = getCodigo (codigos);
        num_Telefone = 7000 + rand () % 2999;
        nm_Local = LOCAL_NOMES [rand () % SIZE_LOCAL_NOMES];
        Local local (cd_Local, num_Telefone, nm_Local);
        locais.push_back(local);
    }
    
    return locais;
}


int main()
{
     // Start a seed...
     srand (time(NULL));


    cout << "Hello world!" << endl;
    return 0;
}
