/*
 * cmatriz.h
 *
 *  Created on: 15 de out de 2017
 *      Author: nocera
 */

#ifndef CLASSES_H_
#define CLASSES_H_


#include <vector>
#include <string>
#include <ctime>

using namespace std;



/* class CMatriz
{
	public :
	int col, row;
	vector <vector <float> > matriz;
	CMatriz (int, int, vector<vector<float> > matriz);
	CMatriz (int, int);
	CMatriz ();


	friend ostream & operator<<(ostream &os, const CMatriz &rhs);
	CMatriz operator+(const CMatriz &rhs);
	CMatriz operator*(const float &rhs);
	CMatriz operator*(const CMatriz &rhs);
	CMatriz &operator=(const CMatriz &rhs);
	CMatriz operator~();

}; */

class Area_de_Conhecimento
{
    public:
        int cd_Area;
        string nm_Area;
        Area_de_Conhecimento (int, string);

};

class Local
{
    public:
        int cd_Local;
        int nu_Telefone;
        string nm_Local;
        Local (int, int, string);

};

class Pessoa
{
    public:
        int cd_Pessoa;
        string nm_Pessoa;
		string nm_Sexo;
		int nu_Idade;
        Pessoa (int, string, string, int);
};

class Professor // Classes: Pessoa; Local;
{
    public:
        int cd_Professor;
        Pessoa cd_Pessoa;
        Local cd_Local;
        string nm_Site;
        string nm_Email;
        int nu_SIAPE;
        string nm_Titulo;
        string nm_Classe;
        Professor (int, Pessoa, Local, string, string, int, string, string);
        Professor (int, int, string, Local, string, string, int, string, string);
};

class Curso // Classes: Area; Professor;
{
    public:
        int cd_Curso;
        Area_de_Conhecimento cd_Area;
        Professor cd_Coordenador;
        string nm_Curso;
        Curso (int, Area_de_Conhecimento, Professor, string);
};

class Disciplina
{
    public:
        int cd_Disciplina;
        string cd_Codigo;
        int hh_Carga_Horaria;
        string nm_Ementa;
        string nm_Bibliografia;
        string nm_Disciplina;
		int nu_Creditos;
        Disciplina (int, string, int, string, string, string, int);
};

class Rel_Pre_Requisito // Classes: Disciplina;
{
    public:
        Disciplina cd_Disciplina;
        Disciplina cd_Pre_Requisito;
        Rel_Pre_Requisito (Disciplina, Disciplina);
};

class Rel_Curso_Disciplina // Classes: Curso; Disciplina;
{
    public:
        Curso cd_Curso;
        Disciplina cd_Disciplina;
        string nm_Obrigatoriedade;
		int nu_Periodo;
        Rel_Curso_Disciplina (Curso,Disciplina, string, int);
};

class Aluno // Classes: Pessoa; Professor; Curso;
{
    public:
        int cd_Aluno;
        Pessoa cd_Pessoa;
        Professor cd_Orientador;
        Curso cd_Curso;
        Aluno (int, Pessoa, Professor, Curso);
        Aluno (int, int, string, Professor, Curso);
};

class Turma // Classes: Disciplina; Local; Professor;
{
    public:
        int cd_Turma;
        Disciplina cd_Disciplina;
        Local cd_Local;
        Professor cd_Professor;
        int hh_Horario;
        int nu_Vagas;
        int nu_Turma;
		int nu_Ano;
		int nu_Semestre;
        Turma (int, Disciplina, Local, Professor, int, int, int, int, int);
};

class Rel_Turma_Aluno // Classes: Turma; Aluno;
{
    public:
        Turma cd_Turma;
        Aluno cd_Aluno;
        int nu_Nota;
        Rel_Turma_Aluno (Turma, Aluno, int);
};

class Extensao // Classes: Aluno; Professor;
{
    public:
        int cd_Extensao;
        Aluno cd_Aluno;
        Professor cd_Orientador;
        string nm_Extensao;
        Extensao (int, Aluno, Professor, string);
};

class Trabalho // Classes: Extensao;
{
    public:
        int cd_Trabalho;
        Extensao cd_Extensao;
        int nu_Nota;
        string nm_Trabalho;
        Trabalho (int, Extensao, int, string);
};




#endif /* CLASSES_H_ */
