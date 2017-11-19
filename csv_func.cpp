#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "csv_func.h"

/*void csv_Template (vector <table_template> vecBase)
{
	//cout << vecBase[1].num1 << endl;
	string csv_filename = "template.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i<2; i++)
		csvF << vecBase[i].nome1 << "," << vecBase[i].num1 << ","
			 << vecBase[i].nome2 << "," << vecBase[i].num2 << endl;

}*/

void csv_Area_de_Conhecimento (vector <Area_de_Conhecimento> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Area_de_Conhecimento.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Area << ","
			 << vecBase[i].nm_Area << endl;
	}
	csvF.close();
}

void csv_Local (vector <Local> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Local.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Local << ","
			 << vecBase[i].nu_Telefone << ","
			 << vecBase[i].nm_Local << endl;
	}
	csvF.close();
}

void csv_Pessoa (vector <Pessoa> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Pessoa.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Pessoa << ","
			 << vecBase[i].nm_Pessoa << ","
			 << vecBase[i].nm_Sexo << ","
			 << vecBase[i].nu_Idade << endl;
	}
	csvF.close();
}

void csv_Professor (vector <Professor> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Professor.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	string csv_filename_2 = "Pessoa_Professor.csv";
	ofstream csvF_2 (csv_filename_2.c_str(), std::ofstream::out);
	
	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Professor << ","
			 << vecBase[i].cd_Pessoa.cd_Pessoa << ","
			 << vecBase[i].cd_Local.cd_Local << ","
			 << vecBase[i].nm_Site << ","
			 << vecBase[i].nm_Email << ","
			 << vecBase[i].nu_SIAPE << ","
			 << vecBase[i].nm_Titulo << ","
			 << vecBase[i].nm_Classe << endl;
	}
	csvF.close();
	
	for (int i=0; i < sz_vec; i++)
	{
		csvF_2 << vecBase[i].cd_Pessoa.cd_Pessoa << ","
			 << vecBase[i].cd_Pessoa.nm_Pessoa << ","
			 << vecBase[i].cd_Pessoa.nm_Sexo << ","
			 << vecBase[i].cd_Pessoa.nu_Idade << endl;
	}
	csvF_2.close();
}

void csv_Curso (vector <Curso> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Curso.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Curso << ","
			 << vecBase[i].cd_Area.cd_Area << ","
			 << vecBase[i].cd_Coordenador.cd_Professor << ","
			 << vecBase[i].nm_Curso << endl;
	}
	csvF.close();
}

void csv_Disciplina (vector <Disciplina> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Disciplina.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Disciplina << ","
			 << vecBase[i].cd_Codigo << ","
			 << vecBase[i].hh_Carga_Horaria << ","
			 << vecBase[i].nm_Ementa << ","
			 << vecBase[i].nm_Bibliografia << ","
			 << vecBase[i].nm_Disciplina << ","
			 << vecBase[i].nu_Creditos << endl;
	}
	csvF.close();
}

void csv_Rel_Pre_Requisito (vector <Rel_Pre_Requisito> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Rel_Pre_Requisito.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Disciplina.cd_Disciplina << ","
			 << vecBase[i].cd_Pre_Requisito.cd_Disciplina << endl;
	}
	csvF.close();
}

void csv_Rel_Curso_Disciplina (vector <Rel_Curso_Disciplina> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Rel_Curso_Disciplina.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Curso.cd_Curso << ","
			 << vecBase[i].cd_Disciplina.cd_Disciplina << ","
			 << vecBase[i].nm_Obrigatoriedade << ","
			 << vecBase[i].nu_Periodo << endl;
	}
	csvF.close();
}

void csv_Aluno (vector <Aluno> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Aluno.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	string csv_filename_2 = "Pessoa_Aluno.csv";
	ofstream csvF_2 (csv_filename_2.c_str(), std::ofstream::out);
	
	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Aluno << ","
			 << vecBase[i].cd_Pessoa.cd_Pessoa << ","
			 << vecBase[i].cd_Orientador.cd_Professor << ","
			 << vecBase[i].cd_Curso.cd_Curso << endl;
	}
	csvF.close();
	
	for (int i=0; i < sz_vec; i++)
	{
		csvF_2 << vecBase[i].cd_Pessoa.cd_Pessoa << ","
			 << vecBase[i].cd_Pessoa.nm_Pessoa << ","
			 << vecBase[i].cd_Pessoa.nm_Sexo << ","
			 << vecBase[i].cd_Pessoa.nu_Idade << endl;
	}
	csvF_2.close();
}

void csv_Turma (vector <Turma> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Turma.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Turma << ","
			 << vecBase[i].cd_Disciplina.cd_Disciplina << ","
			 << vecBase[i].cd_Local.cd_Local << ","
			 << vecBase[i].cd_Professor.cd_Professor << ","
			 << vecBase[i].hh_Horario << ","
			 << vecBase[i].nu_Vagas << ","
			 << vecBase[i].nu_Turma << ","
			 << vecBase[i].nu_Ano << ","
			 << vecBase[i].nu_Semestre << endl;
	}
	csvF.close();
}

void csv_Rel_Turma_Aluno (vector <Rel_Turma_Aluno> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Rel_Turma_Aluno.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Turma.cd_Turma << ","
			 << vecBase[i].cd_Aluno.cd_Aluno << ","
			 << vecBase[i].nu_Nota << endl;
	}
	csvF.close();
}

void csv_Extensao (vector <Extensao> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Extensao.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Extensao << ","
			 << vecBase[i].cd_Aluno.cd_Aluno << ","
			 << vecBase[i].cd_Orientador.cd_Professor << ","
			 << vecBase[i].nm_Extensao << endl;
	}
	csvF.close();
}

void csv_Trabalho (vector <Trabalho> vecBase)
{
	int sz_vec = vecBase.size();
	string csv_filename = "Trabalho.csv";
	ofstream csvF (csv_filename.c_str(), std::ofstream::out);

	for (int i=0; i < sz_vec; i++)
	{
		csvF << vecBase[i].cd_Trabalho << ","
			 << vecBase[i].cd_Extensao.cd_Extensao << ","
			 << vecBase[i].nu_Nota << ","
			 << vecBase[i].nm_Trabalho << endl;
	}
	csvF.close();
}






